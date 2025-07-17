//9012. 괄호
/*
유효한 괄호 문자열 판별
*/

#include <iostream>
#include <string>
using namespace std;

bool isParenthesis(string&);
bool isVPS(string&);

int main() {
	int command_num;
	cin >> command_num;
	//if (cin.fail()) {//예외처리
	//	cout << "올바르지 않은 입력" << endl;
	//	cin.clear();		//failbit 포함 모든 에러 플래그 초기화
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');	//입력 버퍼에 남아있는 잘못된 데이터 비움
	//	return 1;
	//}

	cin.ignore();
	string command;
	for (int i = 0; i < command_num; ++i) {
		getline(cin, command);

		/*if (!isParenthesis(command)) {
			cout << "괄호 외의 문자 포함됨" << endl;
			continue;
		}*/
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
			left_paren_num += 1;
		else {	// ch==')'일 때
			left_paren_num -= 1;
			if (left_paren_num < 0) return false;
		}
	}
	return left_paren_num == 0 ? true : false;
}
/*
1. 처음 )이 나오면 안됨											eg. )()	-> X
2. )이 나왔을때 이전에 나온 (갯수보다 )의 갯수가 많으면 안됨	eg. ())	-> X
3. 1,2통과후 (의 갯수가 )의 총 갯수보다 많은면 안됨				eg. (()	-> X
*/