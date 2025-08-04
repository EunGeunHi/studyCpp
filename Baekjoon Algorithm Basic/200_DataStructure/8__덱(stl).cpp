//10866. ���� ��(double ended queue) ����
/*
push_front X: X�� ���� �տ� ����
push_back X: X�� ���� �ڿ� ����
pop_front:	���� ���� �տ� �ִ� ���� ���� �� ���� ���, �� ��� -1 ���
pop_back:	���� ���� �ڿ� �ִ� ���� ���� �� ���� ���, �� ��� -1 ���
size:			���� ����ִ� ������ ���� ���
empty:		���� ��������� 1, �ƴϸ� 0 ���
front:			���� ���� �տ� �ִ� ���� ���, �� ��� -1 ���
back:			���� ���� �ڿ� �ִ� ���� ���, �� ��� -1 ���
*/

#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main() {
	int num_command;
	cin >> num_command;

	deque<int> dq;

	string command;
	while (num_command--) {
		cin >> command;
		if (command == "push_front") {
			int new_data;
			cin >> new_data;
			dq.push_front(new_data);
		}
		else if (command == "push_back") {
			int new_data;
			cin >> new_data;
			dq.push_back(new_data);
		}
		else if (command == "pop_front") {
			if (!dq.empty()) {
				cout << dq.front() << endl;
				dq.pop_front();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (command == "pop_back") {
			if (!dq.empty()) {
				cout << dq.back() << endl;
				dq.pop_back();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (command == "size") {
			cout << dq.size() << endl;
		}
		else if (command == "empty") {
			cout << dq.empty() << endl;
		}
		else if (command == "front") {
			cout << (!dq.empty() ? dq.front() : -1) << endl;
		}
		else if (command == "back") {
			cout << (!dq.empty() ? dq.back() : -1) << endl;
		}
		else {
			cout << "�Է�\" " << command << " \" Ȯ�� �ʿ�" << endl;
		}
	}

	return 0;
}