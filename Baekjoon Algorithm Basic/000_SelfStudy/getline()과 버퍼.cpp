
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;

    cout << "=== ���� ���� �м� ===" << endl;

    cout << "���̸� �Է��ϼ���: ";
    // �� �������� ���۴� �������: []

    cin >> age;
    // ����ڰ� "25"�� �Է��ϰ� ���͸� ����
    // Ű���� �Է�: 2 5 \n
    // cin >> age�� 25�� �а� ����
    // ���� ����: [\n] <- ���๮�ڰ� ��������!

    //cin.ignore(); //�ּ� ���� ���� üũ
    cout << "���� ���ۿ� ���� ���� ����: " << cin.rdbuf()->in_avail() << endl;

    cout << "�̸��� �Է��ϼ���: ";
    getline(cin, name);
    // getline()�� ���๮�ڸ� ���� ������ �дµ�,
    // ���ۿ� �̹� \n�� �����Ƿ� ��� �� ���ڿ��� �а� ����
    // ���� ����: [] <- ���� �������

    /** ���� cin ���� getline ������ cin.ignore() �ʿ� **/

    cout << "����: " << age << endl;
    cout << "�̸�: [" << name << "]" << endl;  // �� ���ڿ�
    cout << "�̸��� ����: " << name.length() << endl;

    return 0;
}