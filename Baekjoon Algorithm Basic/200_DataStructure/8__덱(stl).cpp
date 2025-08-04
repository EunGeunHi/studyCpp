//10866. 정수 덱(double ended queue) 구현
/*
push_front X: X를 덱의 앞에 넣음
push_back X: X를 덱의 뒤에 넣음
pop_front:	덱의 가장 앞에 있는 수를 빼고 그 수를 출력, 빈 경우 -1 출력
pop_back:	덱의 가장 뒤에 있는 수를 빼고 그 수를 출력, 빈 경우 -1 출력
size:			덱에 들어있는 정수의 개수 출력
empty:		덱이 비어있으면 1, 아니면 0 출력
front:			덱의 가장 앞에 있는 정수 출력, 빈 경우 -1 출력
back:			덱의 가장 뒤에 있는 정수 출력, 빈 경우 -1 출력
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
			cout << "입력\" " << command << " \" 확인 필요" << endl;
		}
	}

	return 0;
}