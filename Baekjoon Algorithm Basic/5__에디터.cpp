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

int main() {
	string edit_chars;
	int num_command;
	string command;

	cin >> edit_chars;
	cin >> num_command;

	while (num_command--) {
		cin >> command;
		if (command.at(0) == 'L') {

		}
		else if (command.at(0) == 'D') {

		}
		else if (command.at(0) == 'B') {

		}
		else if (command.at(0) == 'P') {

		}
		else {
			cout << "�Է�\" " << command << " \" Ȯ�� �ʿ�" << endl;
		}
	}
	cout << edit_chars;
	return 0;
}