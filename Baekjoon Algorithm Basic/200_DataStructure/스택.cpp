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
enum StackFunction{ PUSH,POP,SIZE,EMPTY,TOP };
class MyStack {
private:
	int* data;
	int size;
public:
	MyStack(int n) {
		data = new int[n];
		size = 0;
	}
	~MyStack() {
		delete[] data;
	}
	int push(int);
	int pop();
	int getSize();
	int top();
	bool isEmpty();
};
bool isSeveral(const string&);
void parsing(string&, int&);
StackFunction toStackFunction(string&);

int main() {

	int num_commands;
	cin >> num_commands;
	MyStack st(num_commands);

	for (int i = 0; i < num_commands; ++i) {
		string command;
		int command_parsed;

		cin.ignore();	//���� �Է� ���� ����
		getline(cin, command);

		if (isSeveral(command)) {
			parsing(command, command_parsed);
		}

		switch (toStackFunction(command)) {
			case PUSH:
				cout << st.push(command_parsed) <<endl;
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
			default:
				cout << "switch default! :�Է� �̻�" << endl;
				break;
		}
	}

	return 0;
}



/*
Ŭ���� �ν��Ͻ�
{ �ݺ�
�� �Է� �ް�
�δܾ� �̻��̸� ������
ù �ܾ� �̳��̶� ���ؼ� ����ġ��
����ġ��-��� ����
}

���: Ŭ���� 

���� Ŭ����
����
int data[n]:n= �ִ� ũ�� : ��
int size: ž ��ġ, size
����Լ�
void push(int)
int pop()
int size()
bool empthy()
int top()
*/