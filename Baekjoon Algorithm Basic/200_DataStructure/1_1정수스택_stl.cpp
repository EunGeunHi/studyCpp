
#include <iostream>
#include <string>
#include <stack>

using namespace std;
enum StackFunction { UNKNOWN, PUSH, POP, SIZE, EMPTY, TOP };

bool isSeveral(const string&);
void parsing(string&, int&);
StackFunction toStackFunction(string&);

int main() {
	int num_commands;
	cin >> num_commands;
	cin.ignore();

	stack<int> st;	//정수 스택 선언

	string command;
	int command_parsed;
	for (int i = 0; i < num_commands; ++i) {
		getline(cin, command);

		if (isSeveral(command))
			parsing(command, command_parsed);

		switch (toStackFunction(command)) {
		case PUSH:
			st.push(command_parsed);
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
int strToInt(const string& str) {
	int ret = 0;
	for (char ch : str) {
		if (ch < '0' || ch > '9') {
			cout << "parsing err! : 숫자 아닌 문자 정수변환 시도" << endl;
			return -1;
		}
		ret *= 10;
		ret += (int)(ch - '0');
	}
	return ret;
}
void parsing(string& command, int& command_parsed) {
	size_t spacePos = command.find(' ');
	command_parsed = strToInt(command.substr(spacePos + 1));
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