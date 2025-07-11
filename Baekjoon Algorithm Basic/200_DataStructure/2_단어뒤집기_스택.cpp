//9093. 단어 뒤집기

#include<iostream>
#include<string>
#include<stack>
using namespace std;
void popEvery(stack<char>& st);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int command_num;
	cin >> command_num;
	cin.ignore();

	for (int i = 0; i < command_num; ++i) {
		string command;
		getline(cin, command);

		stack<char> st;
		command += ' ';
		for (char ch : command) {
			if (ch != ' ') st.push(ch);
			else if (ch == ' ') {
				popEvery(st);
				cout << ' ';
			}
		}
		cout << endl;

	}
	return 0;
}

void popEvery(stack<char>& st) {
	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}
