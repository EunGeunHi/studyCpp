//1158 요세푸스 문제
/*
1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고,
 K번째 사람을 제거한다. 제거후 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.
원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다.
예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.
[시작,1,2,3,4,5,6,7] -> [1,2,시작,4,5,6,7] -> [1,2,4,5,시작,7] -> [1,시작,4,5,7]
-> [1,4,5,시작] -> [1,4,시작] -> [시작,4] -> [시작]
N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.
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
		cout << "K는 N 이하여야 합니다" << endl;
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