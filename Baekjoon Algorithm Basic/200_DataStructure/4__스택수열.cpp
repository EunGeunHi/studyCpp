//1874. ���� ����
/*
1���� n������ ���� ���ÿ� �־��ٰ� �̾� �þ�������ν�, �ϳ��� ������ ���� �� �ִ�.
�̶�, ���ÿ� push�ϴ� ������ �ݵ�� ���������� ��Ű���� �Ѵٰ� ����.
������ ������ �־����� �� ������ �̿��� �� ������ ���� �� �ִ��� ������,
�ִٸ� � ������ push�� pop ������ �����ؾ� �ϴ����� �˾Ƴ� �� �ִ�.
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
