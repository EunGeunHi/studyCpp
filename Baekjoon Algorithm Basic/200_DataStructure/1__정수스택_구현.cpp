// 10828. 정수 저장 스택 구현
/*
push X	: 정수 X를 스택에 넣는 연산
pop		: 없다면 -1출력
size	: 스택 갯수 출력
empty	: 비어있으면 1 아니면 0
top		: top의 정수 출력 없다면 -1출력
*/

#include <iostream>
#include <string>
using namespace std;
enum StackFunction { UNKNOWN, PUSH, POP, SIZE, EMPTY, TOP };
class MyStack {// 스택 구현
private:
	int* data;
	int idx_top;
public:
	MyStack(int n) {
		data = new int[n];
		idx_top = -1;
	}
	~MyStack() { delete[] data; }

	bool isEmpty() { return idx_top == -1; }
	void push(int input) {
		data[++idx_top] = input;
	}
	int pop() {
		if (isEmpty())
			return -1;
		return data[idx_top--];
	}
	int size() { return idx_top + 1; }
	int top() {
		if (isEmpty())
			return -1;
		return data[idx_top];
	}
	int getIdxTop() { return idx_top; }

};

bool isSeveral(const string&);
void parsing(string&, int&);
StackFunction toStackFunction(string&);

int main() {
	int num_commands;
	cin >> num_commands;
	cin.ignore(); // 입력 버퍼 정리, 반복문에서는 사용하지 않음

	MyStack st(num_commands);

	string command;
	int command_parsed;
	for (int i = 0; i < num_commands; ++i) {
		getline(cin, command);

		if (isSeveral(command))	//두단어 이상이면 파싱
			parsing(command, command_parsed);

		switch (toStackFunction(command)) { // 입력 매핑
		case PUSH:
			st.push(command_parsed);
			break;
		case POP:
			cout << st.pop() << endl;
			break;
		case SIZE:
			cout << st.size() << endl;
			break;
		case EMPTY:
			cout << st.isEmpty() << endl;
			break;
		case TOP:
			cout << st.top() << endl;
			break;
		case UNKNOWN:

		default:
			cout << "switch default! :입력 이상" << endl;
			break;
		}
		//cout << "idx_top: " << st.getIdxTop() << endl;
	}

	return 0;
}


bool isSeveral(const string& command) {
	// string.find(char) char를 찾지 못하면 std::string::npos를 반환
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
	size_t spacePos = command.find(' '); // npos경우 처리는 main에서 if로 확인했음
	//string.substr(size_t)면 string.substr(size_t에서, string.length()까지 )과 같음
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