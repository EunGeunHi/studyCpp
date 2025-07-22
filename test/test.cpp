//9012. 괄호
/*
유효한 괄호 문자열 판별
+ 안의 문자열 분리후 문자열 배열로 반환
-> ()세트 몇개인지 확인해야.
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
			cout << "parenthesisParse for문 err\n";
			result_list.clear();
			return;
		}
	}

	if (st.empty() == false) {	//'('이 더 많은 경우
		cout << "\"" << object << "\" is not VPS (많음";
		result_list.clear();
	}
}