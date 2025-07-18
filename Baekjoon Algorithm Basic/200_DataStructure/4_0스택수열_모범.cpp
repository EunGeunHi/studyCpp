#include <iostream>
#include <stack>

using namespace std;

int main() {
	stack<int> st;
	int push_data = 1;//마지막에 넣는 값 =최대값
	string output;
	
	int num_command;
	cin >> num_command;
	for (int i = 0; i < num_command; ++i) {
		int input;//i번째 배열 값
		cin >> input;

		for (; push_data <= input; ++push_data) {
			st.push(push_data);
			output += "+\n";
		}

		if (st.top() != input) {
			cout << "NO";
			return 0;
		}
		else {
			st.pop();
			output += "-\n";
		}
	}
	cout << output;

	return 0;
}