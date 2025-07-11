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
	cin.ignore(); // �Է� ���� ����, �ݺ��������� ������� ����

	MyStack st(num_commands);

	string command;
	int command_parsed;
	for (int i = 0; i < num_commands; ++i) {
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
			cout << "switch default! :�Է� �̻�" << endl;
			break;
		}
		//cout << "idx_top: " << st.getIdxTop() << endl;
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
	}
	return ret;
}
void parsing(string& command, int& command_parsed) {
	size_t spacePos = command.find(' '); // npos��� ó���� main���� if�� Ȯ������
	//string.substr(size_t)�� string.substr(size_t����, string.length()���� )�� ����
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