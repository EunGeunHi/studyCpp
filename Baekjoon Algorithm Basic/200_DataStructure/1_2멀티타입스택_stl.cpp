//stl 컨테이너는 기본적으로 하나의 타입만 저장
// 우회적 방법(1.상속 다형성 2.std::variant 3.std::any)들로 간접적으로 구현
// 여기선 상속으로 구현
#include <iostream>
#include <string>
#include <stack>
using namespace std;

//스택 엘리멘트
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
	void combineOsValue(ostream& os) const override { os << "(integer) " << value; }
};
class StackStrData : public StackBaseData {
private:
	string value;
public:
	StackStrData(string value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "(string) " << value; }
};
class StackDoubleData : public StackBaseData {
private:
	double value;
public:
	StackDoubleData(double value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "(double) " << value; }
};
//입력 처리
enum StackFunction { UNKNOWN, PUSH, POP, SIZE, EMPTY, TOP };
enum DataType { UNKOWN, INT, STR, DOUBLE };
bool isSeveral(const string&);
void parsing(string&, unique_ptr<StackBaseData>, DataType&);
StackFunction toStackFunction(string&);


int main1() {
	stack<unique_ptr<StackBaseData>> st;

	st.push(make_unique<StackIntData>(12));
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
			st.push(data);
			break;
		case POP:
			if (st.empty())	//빈 스택 예외 처리
				cout << -1 << endl;
			else {
				//cout << st.pop() << endl;  //stack.pop()은 반환값 void
				cout << st.top() << endl;
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
				cout << st.top() << endl;
			break;
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

void parsing(string& command, unique_ptr<StackBaseData> data, DataType& data_type) {

	size_t spacePos = command.find(' ');
	string command_splited = command.substr(spacePos + 1);
	/*
		처음과 끝 "나' STR,

		모두 isdigit(ch)면 INT, stoi()
		.하나 면서 모두 isdigit(ch)다면 DOUBLE,

	*/
	for (char ch : command_splited) {
		
	}
	
	command = command.substr(0, spacePos);
}
StackFunction toStackFunction(string& command) {
	if (command == "push") return PUSH;
	else if (command == "pop") return POP;
	else if (command == "size") return SIZE;
	else if (command == "empty") return EMPTY;
	else if (command == "top") return TOP;
	else return UNKNOWN;
}




/*todo

 unique_ptr<StackBaseData> data;
 parsing(command, data, data_type);
 해서 공유가 되는지.
 shared_ptr<>찾아 볼 것.
*/