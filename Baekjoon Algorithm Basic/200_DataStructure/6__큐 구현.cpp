//10845. ���� ť
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
#include <list>
using namespace std;

template<typename T>
class Queue {
private:
	list<T> data;
public:
	void push(T new_data){ data.push_back(new_data);}
	void pop(){ data.pop_front(); }
	T& front(){ return data.front(); }
	T& back(){ return data.back(); }
	bool empty(){ return data.empty(); }
	int size(){ return data.size(); }
};

int main() {

	int num_command;
	cin >> num_command;

	Queue<int> q;

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
