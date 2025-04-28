/*

학생 정보를 저장하기 위한 포인터 배열 Student* table[10]선언

static int count는 현재 등록된 학생 수를 관리

아래 메뉴를 switch문으로 구현
1.INPUT
    학생5명을 자동으로 입력. 객체들은 new를 사용해서 생성
2.ISERT
    사용자로부터 ID,이름,나이 입력받아 new로 student객체 생성후
    count이용하여 다음 빈칸에 저장
3.DELETE
    사용자로부터 이름 입력받고, 같은 이름을 가진 학생을 찾아 삭제
    delete 사용
4.UPDATE
    사용자로부터 이름 입력받고, 같은 이름을 가진 학생의 나이 +1
5.EXIT
    모든 동적 메모리 해제 후, 프로그램종료

*제한사항*
이름char*는 new로 동적할당,delete[]로 해제
strcmp()로 이름 비교
최대 10명 저장가능
static int count 사용

*/

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
    Student(int id, const char* name, int age) : id(id), age(age) {
        this->name = new char[strlen(name)+1];
        strcpy(this->name, name);
    }
    ~Student() {
        delete[] name;
    }
    void showStudent() {
        cout << "id: " << id << ", name: " << name << ", age: " << age << endl;
    }
};

int Student::count = 0;

// 함수 정의 (파라미터 전달 방식)

void inputStudents(Student* table[], int& count) {
    // names[], ids[], ages[]를 사용하여 5명의 객체를 생성하여 테이블을 만든다 
    const char* names[5] = { "강감찬", "이순신", "신사임당", "김유신", "윤봉길" };
    int ids[5] = { 101, 102, 103, 104, 105 };
    int ages[5] = { 20, 21, 22, 23, 24 };

    for (int i = count; i < count + 5; i++) {
        table[i] = Student(ids[], names[])
    }

    cout << "[5명의 학생이 자동으로 입력되었습니다.]" << endl;
}
void showStudents(Student* table[], int& count) {
    cout << endl << "[현재 등록된 학생 목록]" << endl;
    for (int i = 0; i < count; i++) {
        table[i]->showStudent();
    }
    cout << endl;
}

// main 함수
int main() {
    Student* table[10] = { nullptr };
    int count = 0;
    int choice;

    bool repeat_while = 1;
    while (repeat_while) {
        cout << "\n1. INPUT\n2. INSERT\n3. DELETE\n4. UPDATE\n5. EXIT\n";
        cout << "Select menu: ";
        cin >> choice;

        switch (static_cast<Menu>(choice)) {
        case INPUT:
            inputStudents(table, count);
            showStudents (table,count);
            break;
        case INSERT:

            break;
        case DELETE_STUDENT:

            break;
        case UPDATE:

            break;
        case  EXIT:

            repeat_while = 0;
            break;
        default:
            cout << "잘못된 입력! 다시 입력해주세요" << endl;
            break;
        }
    }
}



/*
* 1
* 2
* 106 유관순 25
* 5

1. INPUT
2. INSERT
3. DELETE
4. UPDATE
5. EXIT
Select menu: [5명의 학생이 자동으로 입력되었습니다.]

[현재 등록된 학생 목록]
ID: 101, Name: 강감찬, Age: 20
ID: 102, Name: 이순신, Age: 21
ID: 103, Name: 신사임당, Age: 22
ID: 104, Name: 김유신, Age: 23
ID: 105, Name: 윤봉길, Age: 24

1. INPUT
2. INSERT
3. DELETE
4. UPDATE
5. EXIT
Select menu: Enter ID Name Age: [학생이 추가되었습니다.]

[현재 등록된 학생 목록]
ID: 101, Name: 강감찬, Age: 20
ID: 102, Name: 이순신, Age: 21
ID: 103, Name: 신사임당, Age: 22
ID: 104, Name: 김유신, Age: 23
ID: 105, Name: 윤봉길, Age: 24
ID: 106, Name: 유관순, Age: 25

1. INPUT
2. INSERT
3. DELETE
4. UPDATE
5. EXIT
Select menu: [모든 메모리 해제 완료]
[프로그램 종료]





*/