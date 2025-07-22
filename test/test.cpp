//9012. ��ȣ
/*
��ȿ�� ��ȣ ���ڿ� �Ǻ�
+ ���� ���ڿ� �и��� ���ڿ� �迭�� ��ȯ
-> ()��Ʈ ����� Ȯ���ؾ�.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

void parenthesisParse(const string&, vector<string>&);

int main() {
	int command_num;
	cin >> command_num;
	cin.ignore();
	string command;

	for (int i = 0; i < command_num; ++i) {
		getline(cin, command);

		vector<string> words;
		parenthesisParse(command, words);

		for (string str : words)
			cout << str << ' ';
		cout << endl;

	}
	return 0;
}

void parenthesisParse(const string& object, vector<string>& result_list) {
	stack<char> st;
	string word="";
	for (char ch : object) {
		if (st.empty() && ch != '(') {
			cout << "\"" << object << "\" is not VPS";
			result_list.clear();
			return;
		}
		else if (ch == '(')
			st.push('(');
		else if (ch != '(' && ch != ')')
			word += ch;
		else if (ch == ')') {
			st.pop();
			result_list.push_back(word);
			word = "";
		}
		else {
			cout << "parenthesisParse for�� err\n";
			result_list.clear();
			return;
		}
	}

	if (st.empty() == false) {	//'('�� �� ���� ���
		cout << "\"" << object << "\" is not VPS (����";
		result_list.clear();
	}
}