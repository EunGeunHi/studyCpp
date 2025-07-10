
#include <iostream>
#include <string>
using namespace std;

int main() {
    int age;
    string name;

    cout << "=== 버퍼 상태 분석 ===" << endl;

    cout << "나이를 입력하세요: ";
    // 이 시점에서 버퍼는 비어있음: []

    cin >> age;
    // 사용자가 "25"를 입력하고 엔터를 누름
    // 키보드 입력: 2 5 \n
    // cin >> age는 25만 읽고 멈춤
    // 버퍼 상태: [\n] <- 개행문자가 남아있음!

    //cin.ignore(); //주석 해제 전후 체크
    cout << "현재 버퍼에 남은 문자 개수: " << cin.rdbuf()->in_avail() << endl;

    cout << "이름을 입력하세요: ";
    getline(cin, name);
    // getline()은 개행문자를 만날 때까지 읽는데,
    // 버퍼에 이미 \n이 있으므로 즉시 빈 문자열을 읽고 종료
    // 버퍼 상태: [] <- 이제 비어있음

    /** 따라서 cin 다음 getline 쓰려면 cin.ignore() 필요 **/

    cout << "나이: " << age << endl;
    cout << "이름: [" << name << "]" << endl;  // 빈 문자열
    cout << "이름의 길이: " << name.length() << endl;

    return 0;
}