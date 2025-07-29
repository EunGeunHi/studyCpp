//1406. 에디터
/*
한줄로 된 에디터, 문자열 입력받고 명령들 실행
초기 커서 위치 = 맨 뒤
	L: 커서를 왼쪽으로 한 칸 이동, 맨앞이면 무시
	D: 커서를 오른쪽으로 한칸 이동, 맨 뒤면 무시
	B: 커서 왼쪽 문자를 삭제
	P $: $라는 문자를 커서 왼쪽에 추가
모든 명령 수행후의 문자열 출력
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
			cout << "입력\" " << command << " \" 확인 필요" << endl;
		}
	}
	cout << edit_chars;
	return 0;
}