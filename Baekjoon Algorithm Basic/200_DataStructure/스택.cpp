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

int main() {

	int num_commands;
	cin >> num_commands;

	cin.ignore();	//���� �Է� ���� ����
	for (int i = 0; i < num_commands; ++i) {
		string command;
		getline(cin, command);
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
int data[n]:n= �ִ� ũ��
int size: ž ��ġ, size
����Լ�
void push(int)
int pop()
int size()
bool empthy()
int top()
*/