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

class CharsEditer {
private:
	string data;
	int it_cursor;//맨왼쪽이 0, 맨오른쪽이 data.length()
public:
	CharsEditer(const string& chars) : data(chars) {// 빈문자열 처리?
		it_cursor = (int)chars.length();
	}
	void goCursorLeft();
	void goCursorRight();
	void deleteCursorLeft();
	void addCursorLeft(const string&);
	const string& getData() const { return data; }
	friend ostream& operator<<(ostream& os, const CharsEditer editer) {//디버깅용
		os << "data: \"" << editer.data << " \"\t 커서:" << editer.it_cursor;
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
			cout << "입력\" " << command << " \" 확인 필요" << endl;
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
시간 초과 발생
-> string.insert()와 .erase() 연산을 반복적으로 사용했기 때문
삽입할 문자열의 길이 = M, 삽입 위치 이후의 문자열 길이 = N
총 시간 복잡도는 O(N + M)
->내부 알고리즘에서 데이터 복사·이동이 잦기 때문

array는 접근이 효율적이지만
삽입/삭제가 비효율적임
*/