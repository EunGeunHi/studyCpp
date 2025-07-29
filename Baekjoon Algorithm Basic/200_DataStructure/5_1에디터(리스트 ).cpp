//1406. ������
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
#include <list>
using namespace std;

class CharsEditer {
private:
	list<char> str;
	list<char>::iterator it_cursor = str.begin();
public:
	CharsEditer(const string& data) {
		str.insert(it_cursor, data.begin(), data.end());//for (char ch : data) str.push_back(ch); 
		it_cursor = str.end();
	}
	void goCursorLeft();
	void goCursorRight();
	void deleteCursorLeft();
	void addCursorLeft(const string&);
	string getStr() const;

};

int main() {

	string edit_chars;
	cin >> edit_chars;
	CharsEditer editer(edit_chars);

	string command;
	int num_command;
	cin >> num_command;
	while (num_command--) {
		cin >> command;
		if (command.at(0) == 'L') {
			editer.goCursorLeft();
		}
		else if (command.at(0) == 'D') {
			editer.goCursorRight();
		}
		else if (command.at(0) == 'B') {
			editer.deleteCursorLeft();
		}
		else if (command.at(0) == 'P') {
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
	if (it_cursor != str.begin()) --it_cursor;
	return;
}
void CharsEditer::goCursorRight() {
	if (it_cursor != str.end()) ++it_cursor;
	return;
}
void CharsEditer::deleteCursorLeft() {
	if (it_cursor != str.begin()) it_cursor = str.erase(--it_cursor);	//erase()�� ������ ������ ��ȯ
	return;
}
void CharsEditer::addCursorLeft(const string& new_data) {
	str.insert(it_cursor, new_data.begin(), new_data.end());// insert()�� ���� ���Ե� ��Ҹ� ��ȯ <- ���ڰ� �ϳ��� �� ��
	return;
}
string CharsEditer::getStr() const {
	string ret;
	for (char ch : str) ret += ch;
	return ret;
}

/*
list
ȿ����:
� ��ġ������ ��� ����/���� ȿ���� O(1)
��ȿ����:
Ư�� �ε����� ���ٽ� ���̳� �ڿ��� ���� ���������� Ž���ؾ��� O(N)
*/