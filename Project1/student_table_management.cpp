#define MAXSIZE 10
#define _CRT_SECURE_NO_WARNINGS //strcpy() err
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
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }
    ~Student() {
        delete[] name;
    }
    void showStudent() {
        cout << "id: " << id << ", name: " << name << ", age: " << age << endl;
    }
    char* getName() {
        return name;
    }
    void update() {
        age++;
    }

};

int Student::count = 0;

// 함수 정의 (파라미터 전달 방식)

void inputStudents(Student* table[], int& count) {
    const char* names[5] = { "강감찬", "이순신", "신사임당", "김유신", "윤봉길" };
    int ids[5] = { 101, 102, 103, 104, 105 };
    int ages[5] = { 20, 21, 22, 23, 24 };
    bool addFive = true;

    for (int i = 0; i < 5; i++) {
        if (count < MAXSIZE)
            table[count++] = new Student(ids[i % 5], names[i % 5], ages[i % 5]);
        else {
            addFive = false;
            break;
        }
    }
    if (addFive)
        cout << "[5명의 학생이 자동으로 입력되었습니다.]" << endl;
    else
        cout << "[" << MAXSIZE << "명의 학생까지만 자동으로 입력되었습니다.]" << endl;
}
void showStudents(Student* table[], int& count) {
    cout << endl << "[현재 등록된 학생 목록]" << endl;
    for (int i = 0; i < count; i++) {
        if (i >= MAXSIZE) break;
        if (table[i] != nullptr)
            table[i]->showStudent();
    }
    cout << endl;
}
void insertStudents(Student* table[], int& count) {
    if (count >= MAXSIZE) {
        cout << "[테이블이 꽉차 더 추가할 수 없습니다]" << endl;
        return;
    }
    int id;
    char name[30];
    int age;
    cout << "Enter ID Name Age \n";
    cin >> id >> name >> age;
    table[count++] = new Student(id, name, age);
}
void deleteStudents(Student* table[], int& count) {
    char name[30];
    cin >> name;

    for (int i = 0; i < count; i++)
        if (strcmp(name, table[i]->getName()) == 0) {
            delete table[i];
            cout << "[학생이 삭제되었습니다.]\n";

            for (int j = i; j < count - 1; j++)
                table[j] = table[j + 1];
            table[count - 1] = nullptr;

            count--;
        }
}
void updateStudents(Student* table[], int& count) {
    char name[30];
    cin >> name;

    for (int i = 0; i < count; i++)
        if (strcmp(name, table[i]->getName()) == 0)
            table[i]->update();
}

// main 함수
int main() {
    Student* table[MAXSIZE] = { nullptr };
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
            showStudents(table, count);
            break;
        case INSERT:
            insertStudents(table, count);
            showStudents(table, count);
            break;
        case DELETE_STUDENT:
            deleteStudents(table, count);
            showStudents(table, count);
            break;
        case UPDATE:
            updateStudents(table, count);
            showStudents(table, count);
            break;
        case  EXIT:
            for (int i = 0; i < count; i++) {
                delete table[i];
                table[i] = nullptr;
            }
            cout << "[모든 메모리 해제 완료]" << endl;
            repeat_while = 0;
            break;
        default:
            cout << "잘못된 입력! 다시 입력해주세요" << endl;
            break;
        }
    }
}