#include <iostream>
#include <cstring>
using namespace std;

// 메뉴 enum 정의
enum Menu {
	INPUT = 1,
	INSERT,
	DELETE_STUDENT,
	UPDATE,
	EXIT
};

class Student {
private:
	int id;
	char* name;
	int age;
	static int count;

public:
	Student(int i, char* n, int a) :id(i), age(a) {
		name = new char[strlen(n) + 1];
		strcpy(name, n);
	}

	void print() {
		cout << "ID: " << id << ", Name: " << name << ", Age: " << age << endl;
	}
	char* getName() { return name; }
};


int Student::count = 0;

// 함수 정의 (파라미터 전달 방식)

void inputStudents(Student* table[], int& size) {
	// names[], ids[], ages[]를 사용하여 5명의 객체를 생성하여 테이블을 만든다 
	const char* names[5] = { "강감찬", "이순신", "신사임당", "김유신", "윤봉길" };
	int ids[5] = { 101, 102, 103, 104, 105 };
	int ages[5] = { 20, 21, 22, 23, 24 };

	for (int i = 0; i < 5; i++)
		table[i] = new Student(ids[i], names[i], ages[i]);

	size += 5;
	cout << "[5명의 학생이 자동으로 입력되었습니다.]" << endl;
}

void showStudents(Student* table[], int count) {
	cout << "[현재 등록된 학생 목록]" << endl;
	for (int i = 0; i < count; i++)
		table[i]->print();
}

void insertStudents(Student* table[], int& count) {
	int id;
	char Name[20];
	int age;
	cin >> id >> name >> age;
	table[++count] = new Student(id, name, age);
}
void insertStudents(Student* table[], int& count) {
	char delName[20];
	cout << "삭제할 이름:";
	cin >> delName;
	for (int i = 0; i < count; i++)
		if (strcmp(delName, table[i]->getName))

}




// main 함수
int main() {
	Student* table[10] = { nullptr };
	int count = 0;
	int choice;

	while (true) {
		cout << "\n1. INPUT\n2. INSERT\n3. DELETE\n4. UPDATE\n5. EXIT\n";
		cout << "Select menu: ";
		cin >> choice;

		switch (static_cast<Menu>(choice)) {
		case INPUT:
			inputStudents(table, count);
			showsStudents(table, count);
			break;
		case INSERT:
			insertStudents(table, count);
			showsStudents(table, count);
			break;
		case DELETE_STUDENT:
			break;
		case UPDATE:
			break;
		case EXIT:
			break;
		default:
		}
		//2번 INSERT시에 입력 데이터: 106 유관순 25
	  //3번 DELETE시에 김유신 삭제
	  //4번 UPDATE시에 신사임당 변경
	  //출력 내용은 실행 화면 예시를 보고 출력 내용을 정해야 한다!!!

	}
}
