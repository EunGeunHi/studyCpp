//10845. ���� ť stl
/*
push X:	X�� ť�� ����	
pop	:	ť�� ���� �տ� �ִ� ���� ���� �� ������ ���, ����ִٸ� -1���
size:	ť�� ����ִ� ���� ���
empty:	���������1, �ƴϸ� 0
front:	ť�� ���� �տ� �ִ� ���� ���, ����ִٸ� -1���
back:	ť�� ���� �ڿ� �ִ� ���� ���, ����ִٸ� -1���
*/

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {

	int num_command;
	cin >> num_command;

	queue<int> q;

	string command;
	for (int i = 0; i < num_command; ++i) {
		cin >> command;
		if (command == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (command == "pop") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "empty") {
			cout << q.empty() << endl;
		}
		else if (command == "front") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.front() << endl;
		}
		else if (command == "back") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.back() << endl;
		}
		else {
			cout << "�Է�\" " << command << " \" Ȯ�� �ʿ�" << endl;
		}
	}
	return 0;
}