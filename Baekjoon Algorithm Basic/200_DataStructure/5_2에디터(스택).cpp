//1406. ������- ���� ����
/*
���ٷ� �� ������, ���ڿ� �Է¹ް� ��ɵ� ����
�ʱ� Ŀ�� ��ġ = �� ��
	L: Ŀ���� �������� �� ĭ �̵�, �Ǿ��̸� ����
	D: Ŀ���� ���������� ��ĭ �̵�, �� �ڸ� ����
	B: Ŀ�� ���� ���ڸ� ����
	P $: $��� ���ڸ� Ŀ�� ���ʿ� �߰�
��� ��� �������� ���ڿ� ���
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
			cout << "�Է�\" " << command << " \" Ȯ�� �ʿ�" << endl;
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
