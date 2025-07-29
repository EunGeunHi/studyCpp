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
using namespace std;

class CharsEditer {
private:
	string data;
	int it_cursor;//�ǿ����� 0, �ǿ������� data.length()
public:
	CharsEditer(const string& chars) : data(chars) {// ���ڿ� ó��?
		it_cursor = (int)chars.length();
	}
	void goCursorLeft();
	void goCursorRight();
	void deleteCursorLeft();
	void addCursorLeft(const string&);
	const string& getData() const { return data; }
	friend ostream& operator<<(ostream& os, const CharsEditer editer) {//������
		os << "data: \"" << editer.data << " \"\t Ŀ��:" << editer.it_cursor;
		return os;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string edit_chars;
	cin >> edit_chars;
	CharsEditer editer(edit_chars);
	//cout << editer << endl;

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
		//cout << editer << endl;
	}
	cout << editer.getData();

	return 0;
}

void CharsEditer::goCursorLeft() {
	if (it_cursor > 0) --it_cursor;
	return;
}
void CharsEditer::goCursorRight() {
	if (it_cursor < data.length()) ++it_cursor;
	return;
}
void CharsEditer::deleteCursorLeft() {
	if (it_cursor > 0) data.erase(--it_cursor, 1);
	return;
}
void CharsEditer::addCursorLeft(const string& new_data) {
	data.insert(it_cursor++, new_data);
	return;
}

/*
�ð� �ʰ� �߻�
-> string.insert()�� .erase() ������ �ݺ������� ����߱� ����
������ ���ڿ��� ���� = M, ���� ��ġ ������ ���ڿ� ���� = N
�� �ð� ���⵵�� O(N + M)
->���� �˰��򿡼� ������ ���硤�̵��� ��� ����

array�� ������ ȿ����������
����/������ ��ȿ������
*/