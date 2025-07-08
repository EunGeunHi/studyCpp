// 10828. ���� ���� ���� ����
/*
push X	: ���� X�� ���ÿ� �ִ� ����
pop		: ���ٸ� -1���
size	: ���� ���� ���
empty	: ��������� 1 �ƴϸ� 0
top		: top�� ���� ��� ���ٸ� -1���
*/

#include <iostream>
#include <string>
using namespace std;
enum StackFunction { UNKNOWN, PUSH, POP, SIZE, EMPTY, TOP };
class MyStack {// ���� ����
private:
	int* data;
	int size;
public:
	MyStack(int n) {
		data = new int[n];
		size = 0;
	}
	~MyStack() { delete[] data; }

	void push(int input) {
		data[size++] = input;
	}
	int pop() {
		if (size < 1)
			return -1;
		return data[size--];
	}
	int getSize() { return size; }
	int top() { return data[size]; }
	bool isEmpty() { return size == 0; }
};

bool isSeveral(const string&);
void parsing(string&, int&);
StackFunction toStackFunction(string&);

int main() {

	int num_commands;
	cin >> num_commands;
	MyStack st(num_commands);

	string command;
	int command_parsed;
	for (int i = 0; i < num_commands; ++i) {
		cin.ignore();	//���� �Է� ���� ����
		getline(cin, command);

		if (isSeveral(command))	//�δܾ� �̻��̸� �Ľ�
			parsing(command, command_parsed);

		switch (toStackFunction(command)) { // �Է� ����
		case PUSH:
			st.push(command_parsed);
			break;
		case POP:
			cout << st.pop() << endl;
			break;
		case SIZE:
			cout << st.getSize() << endl;
			break;
		case EMPTY:
			cout << st.isEmpty() << endl;
			break;
		case TOP:
			cout << st.top() << endl;
			break;
		case UNKNOWN:
		default:
			cout << "switch default! :�Է� �̻�" << endl;
			break;
		}
	}

	return 0;
}


bool isSeveral(const string& command) {
	// string.find(char) char�� ã�� ���ϸ� std::string::npos�� ��ȯ
	return (command.find(' ') == string::npos) ? false : true;
}
int strToInt(const string& str) {
	int ret = 0;
	for (char ch : str) {
		if (ch < '0' || ch > '9') {
			cout << "parsing err! : ���� �ƴ� ���� ������ȯ �õ�" << endl;
			return -1;
		}
		ret *= 10;
		ret += (int)(ch - '0');
		return ret;
	}
}
void parsing(string& command, int& command_parsed) {
	size_t spacePos = command.find(' '); // npos��� ó���� main���� if�� Ȯ������
	//string.substr(size_t)�� string.substr(size_t, string.length() )�� ����
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