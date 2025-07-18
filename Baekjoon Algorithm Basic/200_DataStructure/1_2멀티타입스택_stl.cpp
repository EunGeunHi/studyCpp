//stl 컨테이너는 기본적으로 하나의 타입만 저장
// 우회적 방법(1.상속 다형성 2.std::variant 3.std::any)들로 간접적으로 구현
// 여기선 상속으로 구현
#include <iostream>
#include <string>
#include <stack>
#include <memory>	//스마트 포인터
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
//입력 처리
enum StackFunction { UNKNOWN, PUSH, POP, SIZE, EMPTY, TOP, QUIT };
enum DataType { UNKOWN, INT, STR, DOUBLE };
bool isSeveral(const string&);
void parsing(string&, unique_ptr<StackBaseData>&, DataType&);
StackFunction toStackFunction(string&);


int main1() {
	stack<unique_ptr<StackBaseData>> st;

	unique_ptr<StackBaseData> data;
	unique_ptr<StackBaseData>& p = data;
	p = make_unique<StackIntData>(12);
	st.push(move(data));
	st.push(make_unique<StackDoubleData>(12));
	st.push(make_unique<StackStrData>("12"));

	while (!st.empty()) {
		/*		스마트 포인터라 따로 메모리 해제 하지 않아도 됨
		StackBaseData* temp = st.top();
		cout<< st.top();
		st.pop()
		delete temp;
		*/
		cout << *st.top() << endl;
		st.pop();
	}
	return 0;
}


int main() {
	int num_commands;
	cin >> num_commands;
	cin.ignore();

	stack<unique_ptr<StackBaseData>> st;	//멀티타입 스택 선언

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
			if (data_type == UNKNOWN) {
				cout << "push err :데이터 형식 이상" << endl;
				cout << "\t" << *data << "\t는 올바른 입력형식이 아닙니다" << endl;
				break;
			}
			st.push(move(data));	//stl stack.push는 인자를 복사해서 받음-> move로 전달
			break;
		case POP:
			if (st.empty())	//빈 스택 예외 처리
				cout << -1 << endl;
			else {
				cout << *st.top() << endl;
				st.pop();
			}
			break;
		case SIZE:
			cout << st.size() << endl;
			break;
		case EMPTY:
			cout << st.empty() << endl;
			break;
		case TOP:
			if (st.empty())	//빈 스택 예외 처리
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
	/*for (char ch : str)
		if (!isdigit(ch)) return false;
	return true;*/
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