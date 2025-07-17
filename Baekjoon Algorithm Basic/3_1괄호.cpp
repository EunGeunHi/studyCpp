//9012. ��ȣ
/*
��ȿ�� ��ȣ ���ڿ� �Ǻ�
+ ���� ���ڿ� �и��� ���ڿ� �迭�� ��ȯ
-> ()��Ʈ ����� Ȯ���ؾ�.
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
			cout << "��ȣ ���� ���� ���Ե�" << endl;
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
	if (str.at(0) == ')') return false;		//str[]�� ���� �˻� ���� ���� str.at()�� �� ����

	int left_paren_num = 0;
	for (char ch : str) {
		if (ch == '(')
			left_paren_num = +1;
		else {	// ch==')'�� ��
			left_paren_num = -1;
			if (left_paren_num < 0) return false;
		}
	}
	return left_paren_num == 0 ? true : false;
}