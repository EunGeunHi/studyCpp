//10845. 정수 큐
/*
push X:	X를 큐에 넣음
pop	:	큐에 가장 앞에 있는 정수 빼고 그 정수를 출력, 비어있다면 -1출력
size:	큐에 들어있는 갯수 출력
empty:	비어있으면1, 아니면 0
front:	큐의 가장 앞에 있는 정수 출력, 비어있다면 -1출력
back:	큐의 가장 뒤에 있는 정수 출력, 비어있다면 -1출력
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
			cout << "입력\" " << command << " \" 확인 필요" << endl;
		}
	}
	return 0;
}
