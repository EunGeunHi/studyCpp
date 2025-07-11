#include <iostream>
#include <memory> // unique_ptr
using namespace std;

/*
����Ʈ �����ʹ� ������ó�� ���� but �޸𸮸� ���� ����X
����Ʈ ������ ��ü�� �Ҹ�ɶ�, ����Ű�� �޸𸮸� �ڵ����� ������-> �޸� ���� ó��
-> ����Ʈ �����ʹ� �������� ������ �ڵ����� �Ҹ��� ȣ���Ͽ� �ڵ� �޸� ����

lifetime�� ���� å���� ������'������'������ ����, ������ �޸� ������ ����
unique_ptr�� �� �� �ϳ��� ����Ʈ �����͸��� �޸𸮸� �����Ҽ� �ְԵ�
= ������ ���縦 ������� ����
-> unique_ptr<T> p1 (new int); unique_ptr<T> p2 = p1;
   ������ err : ���� �ڿ��� �� �����Ͱ� ������ ����
-> unique_ptr<T> p2 = move(p1);
   move()�� p2�� �������� �Ѱܹ���,���ÿ� �������� �Ѱ��� p1�� nullptr�� ��
*/

unique_ptr<int> returnUniqePtr() {
	//unique_ptr�� ���� ��ȯ�ϸ� ������ ������
	//���� �Լ� ���� �Ŀ��� �޸� ���� �߻����� ����

	//return unique_ptr<int>(new int(6));
	/*
	new int(6)�� int�ϳ� �޸� �Ҵ� ��, ���� 6���� �ʱ�ȭ�ؼ� int*��ȯ
	new int[6]�� ����6�� int�迭 �޸� �Ҵ� ��, int*��ȯ
	*/
	return make_unique<int>(6);//����Ʈ ������ ��Ÿ��
}
unique_ptr<int[]> retrunIntArray() {
	/*
	unique_ptr<T>�� ���� ��ü
	unique_ptr<T[]>�� �迭 ����
	*/
	//return unique_ptr<int[]>(new int[6]);
	return make_unique<int[]>(6);//����Ʈ ������ ��Ÿ��
}
void TakeUniquePtr(unique_ptr<int>ptr) {
	cout << "func: Take unique ptr" << endl;
	cout << "\tvalue = " << *ptr << endl;
	/*
	�Ķ���ͷ� ���޵� unique_ptr�� �� �Լ� �ȿ����� ��ȿ��
	�Լ��� �����Ŀ��� �ڵ����� �޸� ������
	*/
}
void UseUniquePtr(unique_ptr<int>& ptr) {
	cout << "func: Use unique ptr" << endl;
	*ptr += 1;
}

int main() {
	unique_ptr<int> p1 = returnUniqePtr();
	//unique_ptr<int> copy = p1;	//������err ����ũ ������ ���� �õ�
	TakeUniquePtr(move(p1));	//unique_ptr<int> parameter = move(p1)�� ����
	//cout << *p1 << endl; // err: cout<< nullptr 

	unique_ptr<int> p2 = returnUniqePtr();
	unique_ptr<int>& refference = p2;	//������ ����
	cout << *refference << endl;
	UseUniquePtr(p2);
	cout << *p2 << endl;	//�������� �ѱ���� �ƴϱ⿡ nullptr�� �ƴ�

	return 0;
}