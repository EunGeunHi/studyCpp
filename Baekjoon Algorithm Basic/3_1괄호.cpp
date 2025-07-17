//9012. 괄호
/*
유효한 괄호 문자열 판별
+ 안의 문자열 분리후 문자열 배열로 반환
-> ()세트 몇개인지 확인해야.
*/

#include <iostream>
#include <string>
using namespace std;

bool isParenthesis(string&);
bool isVPS(string&);

int main() {
	int command_num;
	cin >> command_num;
	cin.ignore();
	string command;

	for (int i = 0; i < command_num; ++i) {
		getline(cin, command);

		if (!isParenthesis(command)) {
			cout << "괄호 외의 문자 포함됨" << endl;
			continue;
		}
		cout << (isVPS(command) ? "YES" : "NO") << endl;
	}
	return 0;
}

bool isParenthesis(string& str) {
	if (str.empty())
		return false;
	for (char ch : str) {
		if (ch != '(' && ch != ')') return false;
	}

	return true;
}
bool isVPS(string& str) {
	if (str.at(0) == ')') return false;		//str[]는 범위 검사 하지 않음 str.at()이 더 안전

	int left_paren_num = 0;
	for (char ch : str) {
		if (ch == '(')
			left_paren_num = +1;
		else {	// ch==')'일 때
			left_paren_num = -1;
			if (left_paren_num < 0) return false;
		}
	}
	return left_paren_num == 0 ? true : false;
}