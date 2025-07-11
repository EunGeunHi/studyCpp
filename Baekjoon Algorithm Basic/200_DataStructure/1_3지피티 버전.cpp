// 10828변형. 멀티타입 저장 스택 구현
#include <iostream>
#include <string>
#include <memory>
using namespace std;

//스택 엘리먼트
class StackBaseData {
public:
	virtual ~StackBaseData() = default;
	virtual void combineOsValue(ostream& os) const = 0;
	friend ostream& operator<< (ostream& os, const StackBaseData& data) {	// cout<< 으로 출력
		data.combineOsValue(os);	//다형성
		return os;
	}
};
class StackIntData : public StackBaseData {
private:
	int value;
public:
	StackIntData(int value) :value(value) {}
	void combineOsValue(ostream& os) const override { os/* << "[integer] "*/ << value; }
};
class StackStrData : public StackBaseData {
private:
	string value;
public:
	StackStrData(string value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "[string] " << value; }
};
class StackDoubleData : public StackBaseData {
private:
	double value;
public:
	StackDoubleData(double value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "[double] " << value; }
};
class StackUnknownData : public StackBaseData {
private:
	string value;
public:
	StackUnknownData(string value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "[unkown] " << value; }
};

//스택 구현
template<typename T>
class MyStack {
private:
	T* data;
	int idx_top;
	int capacity;
public:
	MyStack(int n) : capacity(n) {
		data = new T[n];
		idx_top = -1;
	}
	~MyStack() { delete[] data; }

	// 복사 생성자와 대입 연산자 삭제 (unique_ptr 때문에 필요)
	MyStack(const MyStack&) = delete;
	MyStack& operator=(const MyStack&) = delete;

	bool isEmpty() { return idx_top == -1; }

	void push(T&& input) {  // rvalue reference로 변경
		if (idx_top + 1 >= capacity) {
			cout << "Stack overflow!" << endl;
			return;
		}
		data[++idx_top] = move(input);  // move 사용
	}

	T pop() {
		if (isEmpty()) {
			return nullptr;  // unique_ptr의 경우 nullptr 반환
		}
		return move(data[idx_top--]);  // move 사용
	}

	int size() { return idx_top + 1; }

	T& top() {  // 참조 반환으로 변경
		// 빈 스택인 경우의 처리는 호출부에서 isEmpty() 체크 후 호출
		return data[idx_top];
	}

	int getIdxTop() { return idx_top; }
};

//입력 처리
enum StackFunction { UNKNOWN, PUSH, POP, SIZE, EMPTY, TOP, QUIT };
enum DataType { UNKOWN, INT, STR, DOUBLE };
bool isSeveral(const string&);
void parsing(string&, unique_ptr<StackBaseData>&, DataType&);
StackFunction toStackFunction(string&);

int main() {
	int num_commands;
	cin >> num_commands;
	cin.ignore();

	MyStack<unique_ptr<StackBaseData>> st = MyStack<unique_ptr<StackBaseData>>(num_commands);

	string command;
	unique_ptr<StackBaseData> data;
	DataType data_type;
	for (int i = 0; i < num_commands; ++i) {
		getline(cin, command);

		if (isSeveral(command))
			parsing(command, data, data_type);

		switch (toStackFunction(command)) {
		case PUSH:
			if (!data) {
				cout << "parsing err" << endl;
				break;
			}
			if (data_type == UNKOWN) {  // UNKNOWN -> UNKOWN으로 수정
				cout << "push err :데이터 형식 이상" << endl;
				cout << "\t" << *data << "\t는 올바른 입력형식이 아닙니다" << endl;
				break;
			}
			st.push(move(data));	// 이미 move 사용 중
			break;
		case POP:
			if (st.isEmpty())	//빈 스택 예외 처리
				cout << -1 << endl;
			else {
				auto popped = st.pop();  // pop된 요소를 받아서
				if (popped) {
					cout << *popped << endl;  // 출력
				}
			}
			break;
		case SIZE:
			cout << st.size() << endl;
			break;
		case EMPTY:
			cout << st.isEmpty() << endl;
			break;
		case TOP:
			if (st.isEmpty())	//빈 스택 예외 처리
				cout << -1 << endl;
			else
				cout << *st.top() << endl;
			break;
		case QUIT:
			return 0;
		case UNKNOWN:
		default:
			cout << "switch default! :입력 이상" << endl;
			break;
		}
	}

	return 0;
}

bool isSeveral(const string& command) {
	return (command.find(' ') == string::npos) ? false : true;
}
bool isString(const string& str) {
	return (str.front() == '"' && str.back() == '"')
		|| (str.front() == '\'' && str.back() == '\'');	// 처음과 끝 모두 "거나 '면 str
}
bool isDouble(const string& str) {
	try {
		size_t pos;	//실수가 아닌 다음 문자의 인덱스 저장
		double data = stod(str, &pos);//실수변환
		for (size_t i = pos; i < str.length(); ++i)
			if (str[i] != ' ') return false; //숫자 뒤에 공백이 아닌 다른 문자 남아있으면 false
		return true;	//변환 성공하고, 뒤에 유효하지 않은 문자 없다면 true
	}
	catch (...) {
		return false;
	}
}
bool isDigits(const string& str) {
	try {
		size_t pos;
		int data = stoi(str, &pos);
		for (size_t i = pos; i < str.length(); ++i)
			if (str[i] != ' ') return false;
		return true;
	}
	catch (...) {
		return false;
	}
}

void parsing(string& command, unique_ptr<StackBaseData>& data, DataType& data_type) {

	size_t spacePos = command.find(' ');
	string command_splited = command.substr(spacePos + 1);

	//데이터 타입 검사후 포인터에 데이터 매핑
	if (command_splited.empty()) {//빈 문자열 처리 먼저
		data_type = UNKOWN;
		data = make_unique<StackUnknownData>(command_splited);
	}
	else if (isString(command_splited)) {
		data_type = STR;
		data = make_unique<StackStrData>(command_splited.substr(1, command_splited.length() - 2));
	}
	else if (isDigits(command_splited)) {
		data_type = INT;
		data = make_unique<StackIntData>(stoi(command_splited));
	}
	else if (isDouble(command_splited)) {
		data_type = DOUBLE;
		data = make_unique<StackDoubleData>(stod(command_splited));
	}
	else {
		data_type = UNKOWN;
		data = make_unique<StackUnknownData>(command_splited);
	}

	command = command.substr(0, spacePos);
}
StackFunction toStackFunction(string& command) {
	if (command == "push") return PUSH;
	else if (command == "pop") return POP;
	else if (command == "size") return SIZE;
	else if (command == "empty") return EMPTY;
	else if (command == "top") return TOP;
	else if (command == "quit") return QUIT;
	else return UNKNOWN;
}