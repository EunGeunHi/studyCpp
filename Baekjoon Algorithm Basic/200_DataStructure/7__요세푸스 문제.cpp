//1158 �似Ǫ�� ����
/*
1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�,
 K��° ����� �����Ѵ�. ������ ���� ������ �̷���� ���� ���� �� ������ ����� ������.
�� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�.
������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�.
���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.
[����,1,2,3,4,5,6,7] -> [1,2,����,4,5,6,7] -> [1,2,4,5,����,7] -> [1,����,4,5,7]
-> [1,4,5,����] -> [1,4,����] -> [����,4] -> [����]
N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

#include <iostream>
#include <list>
using namespace std;

int* josephus_permutation(int, int);
void format_print(int*, int);

int main() {
	int N, K;
	cin >> N >> K;
	if (K > N) {
		cout << "K�� N ���Ͽ��� �մϴ�" << endl;
		return 0;
	}

	int* jp = josephus_permutation(N, K);
	format_print(jp, N);
	delete jp;
	return 0;
}

int* josephus_permutation(int N, int K) {
	int* ret = new int[N];
	list<int>temp;

	for (int i = 1; i <= N; i++)
		temp.push_back(i);

	int* idx = ret;
	auto it = temp.begin();
	while (!temp.empty()) {
		for (int i = 0; i < K - 1; i++) {
			++it;
			if (it == temp.end())
				it = temp.begin();
		}
		*(idx++) = *it;
		it = temp.erase(it);
		if (it == temp.end())
			it = temp.begin();
	}
	return ret;
}
void format_print(int* array, int size) {
	cout << "<";
	for (int i = 0; i < size - 1; ++i) {
		cout << array[i] << ", ";
	}
	cout << array[size - 1] << ">";
}