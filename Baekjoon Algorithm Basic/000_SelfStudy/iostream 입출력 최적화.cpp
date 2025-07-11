#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    // C++ 스트림과 C 스트림 동기화 해제
    ios::sync_with_stdio(false);
    // -> 이후 scanf/printf 와 cin/cout을 섞어 쓸 수 없음

    // cin과 cout (cout을 보여주고cin 받을수 있도록한)연결 해제
    cin.tie(nullptr);
    //-> cin이 cout의 플러시를 기다리지 않음
    //필요시 cout<<flush; 가능

    // 이제부터 std::cin과 std::cout은 매우 빠르게 작동
    int N;
    cin >> N; // 빠른 입력

    vector<int> numbers(N);
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    for (int i = 0; i < N; ++i) {
       cout << numbers[i] << " "; // 빠른 출력
    }
    cout <<endl; // 마지막에 std::endl로 버퍼를 비워주는 습관

    return 0;
}