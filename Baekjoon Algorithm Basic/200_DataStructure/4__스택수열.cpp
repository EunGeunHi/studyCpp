//1874. 스택 수열
/*
1부터 n까지의 수를 스택에 넣었다가 뽑아 늘어놓음으로써, 하나의 수열을 만들 수 있다.
이때, 스택에 push하는 순서는 반드시 오름차순을 지키도록 한다고 하자.
임의의 수열이 주어졌을 때 스택을 이용해 그 수열을 만들 수 있는지 없는지,
있다면 어떤 순서로 push와 pop 연산을 수행해야 하는지를 알아낼 수 있다.
*/

#include <iostream>
#include <memory>
#include <stack>
using namespace std;

int main() {
	int command_num;
	cin >> command_num;

	unique_ptr<int[]> input_sequence = make_unique<int[]>(command_num); //int* input_sequence = new int[command_num];
	for (int i = 0; i < command_num; ++i)
		cin >> input_sequence[i];

	stack<int> st;
	int push_data = 1;
	int biggest_data;
	bool possible = true;
	string output;

	for (int i = 0; i < input_sequence[0]; ++i) {
		st.push(push_data++);
		output += "+\n";
	}
	st.pop();
	output += "-\n";
	biggest_data = input_sequence[0];

	for (int i = 1; i < command_num; ++i) {
		if (input_sequence[i] < input_sequence[i - 1]) {
			if (input_sequence[i] != st.top()) {
				possible = false;
				break;
			}
			if (st.top() > biggest_data)
				biggest_data = st.top();
			st.pop();
			output += "-\n";
		}
		else if (input_sequence[i] > input_sequence[i - 1]) {
			for (int j = biggest_data; j < input_sequence[i]; ++j) {
				st.push(push_data++);
				output += "+\n";
			}
			if (st.top() > biggest_data)
				biggest_data = st.top();
			st.pop();
			output += "-\n";
		}
		else {
			break;
		}
	}

	cout << (possible ? output : "NO") << endl;

	return 0;
}
