// 10828. 정수 저장 스택 구현
/* 
push X	: 정수 X를 스택에 넣는 연산
pop		: 없다면 -1출력
size	: 스택 갯수 출력
empty	: 비어있으면 1 아니면 0
top		: top의 정수 출력 없다면 -1출력
*/

#include <iostream>
#include <string>
using namespace std;
enum StackFunction{ PUSH,POP,SIZE,EMPTY,TOP };
class MyStack {
private:
	int* data;
	int size;
public:
	MyStack(int n) {
		data = new int[n];
		size = 0;
	}
	~MyStack() {
		delete[] data;
	}
	int push(int);
	int pop();
	int getSize();
	int top();
	bool isEmpty();
};
bool isSeveral(const string&);
void parsing(string&, int&);
StackFunction toStackFunction(string&);

int main() {

	int num_commands;
	cin >> num_commands;
	MyStack st(num_commands);

	for (int i = 0; i < num_commands; ++i) {
		string command;
		int command_parsed;

		cin.ignore();	//이전 입력 버퍼 정리
		getline(cin, command);

		if (isSeveral(command)) {
			parsing(command, command_parsed);
		}

		switch (toStackFunction(command)) {
			case PUSH:
				cout << st.push(command_parsed) <<endl;
				break;
			case POP:
				cout << st.pop() << endl;
				break;
			case SIZE:
				cout << st.getSize() << endl;
				break;
			case EMPTY:
				cout << st.isEmpty() << endl;
				break;
			case TOP:
				cout << st.top() << endl;
				break;
			default:
				cout << "switch default! :입력 이상" << endl;
				break;
		}
	}

	return 0;
}



/*
클래스 인스턴스
{ 반복
줄 입력 받고
두단어 이상이면 나누고
첫 단어 이넘이랑 비교해서 스위치문
스위치문-펑션 연걸
}

펑션: 클래스 

스택 클래스
변수
int data[n]:n= 최대 크기 : 만
int size: 탑 위치, size
멤버함수
void push(int)
int pop()
int size()
bool empthy()
int top()
*/