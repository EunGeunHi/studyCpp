#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    // C++ ��Ʈ���� C ��Ʈ�� ����ȭ ����
    ios::sync_with_stdio(false);
    // -> ���� scanf/printf �� cin/cout�� ���� �� �� ����

    // cin�� cout (cout�� �����ְ�cin ������ �ֵ�����)���� ����
    cin.tie(nullptr);
    //-> cin�� cout�� �÷��ø� ��ٸ��� ����
    //�ʿ�� cout<<flush; ����

    // �������� std::cin�� std::cout�� �ſ� ������ �۵�
    int N;
    cin >> N; // ���� �Է�

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < N; ++i) {
       cout << numbers[i] << " "; // ���� ���
    }
    cout <<endl; // �������� std::endl�� ���۸� ����ִ� ����

    return 0;
}