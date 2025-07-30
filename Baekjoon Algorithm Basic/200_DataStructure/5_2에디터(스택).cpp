//1406. 에디터- 스택 구현
/*
한줄로 된 에디터, 문자열 입력받고 명령들 실행
초기 커서 위치 = 맨 뒤
	L: 커서를 왼쪽으로 한 칸 이동, 맨앞이면 무시
	D: 커서를 오른쪽으로 한칸 이동, 맨 뒤면 무시
	B: 커서 왼쪽 문자를 삭제
	P $: $라는 문자를 커서 왼쪽에 추가
모든 명령 수행후의 문자열 출력
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

class CharsEditer {
private:
	stack<char> left_side_cursor;
	stack<char> right_side_cursor;
public:
	CharsEditer(const string& data) {
		for (char ch : data) left_side_cursor.push(ch);
	}
	void goCursorLeft();
	void goCursorRight();
	void deleteCursorLeft();
	void addCursorLeft(const char);
	string getStr() const;

};

int main() {

	string edit_chars;
	cin >> edit_chars;
	CharsEditer editer(edit_chars);

	char command;
	int num_command;
	cin >> num_command;
	while (num_command--) {
		cin >> command;
		if (command == 'L') {
			editer.goCursorLeft();
		}
		else if (command == 'D') {
			editer.goCursorRight();
		}
		else if (command == 'B') {
			editer.deleteCursorLeft();
		}
		else if (command == 'P') {
			cin >> command;
			editer.addCursorLeft(command);
		}
		else {
			cout << "입력\" " << command << " \" 확인 필요" << endl;
		}
	}
	cout << editer.getStr();

	return 0;
}

void CharsEditer::goCursorLeft() {
	if (left_side_cursor.empty() == false) {
		right_side_cursor.push(left_side_cursor.top());
		left_side_cursor.pop();
	}
	return;
}
void CharsEditer::goCursorRight() {
	if (right_side_cursor.empty() == false) {
		left_side_cursor.push(right_side_cursor.top());
		right_side_cursor.pop();
	}
	return;
}
void CharsEditer::deleteCursorLeft() {
	if (left_side_cursor.empty() == false) left_side_cursor.pop();
	return;
}
void CharsEditer::addCursorLeft(const char new_data) {
	left_side_cursor.push(new_data);
	return;
}
string CharsEditer::getStr() const {
	stack<char> temp_r = right_side_cursor;
	stack<char> temp_l = left_side_cursor;
	while (temp_l.empty()) {
		temp_r.push(temp_l.top());
		temp_l.pop();
	}
	string ret;
	while (temp_r.empty()) {
		ret += temp_l.top();
		temp_l.pop();
	}
	return ret;
}
