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
#include <list>
using namespace std;

class CharsEditer {
private:
	list<char> str;
	list<char>::iterator it_cursor = str.begin();
public:
	CharsEditer(const string& data) {
		str.insert(it_cursor, data.begin(), data.end());//for (char ch : data) str.push_back(ch); 
		it_cursor = str.end();
	}
	void goCursorLeft();
	void goCursorRight();
	void deleteCursorLeft();
	void addCursorLeft(const string&);
	string getStr() const;

};

int main() {

	string edit_chars;
	cin >> edit_chars;
	CharsEditer editer(edit_chars);

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
	}
	cout << editer.getStr();

	return 0;
}

void CharsEditer::goCursorLeft() {
	if (it_cursor != str.begin()) --it_cursor;
	return;
}
void CharsEditer::goCursorRight() {
	if (it_cursor != str.end()) ++it_cursor;
	return;
}
void CharsEditer::deleteCursorLeft() {
	if (it_cursor != str.begin()) it_cursor = str.erase(--it_cursor);	//erase()가 삭제된 다음을 반환
	return;
}
void CharsEditer::addCursorLeft(const string& new_data) {
	str.insert(it_cursor, new_data.begin(), new_data.end());// insert()가 새로 삽입된 요소를 반환 <- 인자가 하나일 때 만
	return;
}
string CharsEditer::getStr() const {
	string ret;
	for (char ch : str) ret += ch;
	return ret;
}

/*
list
효율적:
어떤 위치에서든 요소 삽입/삭제 효율적 O(1)
비효율적:
특정 인덱스에 접근시 앞이나 뒤에서 부터 순차적으로 탐색해야함 O(N)
*/