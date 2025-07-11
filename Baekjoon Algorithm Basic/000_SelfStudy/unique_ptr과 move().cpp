#include <iostream>
#include <memory> // unique_ptr
using namespace std;

/*
스마트 포인터는 포인터처럼 동작 but 메모리를 직접 관리X
스마트 포인터 객체가 소멸될때, 가리키는 메모리를 자동으로 해제함-> 메모리 누수 처리
-> 스마트 포인터는 스코프가 끝날때 자동으로 소멸자 호출하여 자동 메모리 해제

lifetime을 누가 책임질 것인지'소유권'개념을 도입, 동일한 메모리 접근을 관리
unique_ptr은 는 단 하나의 스마트 포인터만이 메모리를 소유할수 있게됨
= 포인터 복사를 허용하지 않음
-> unique_ptr<T> p1 (new int); unique_ptr<T> p2 = p1;
   컴파일 err : 같은 자원을 두 포인터가 가질수 없음
-> unique_ptr<T> p2 = move(p1);
   move()로 p2가 소유권을 넘겨받음,동시에 소유권을 넘겨준 p1은 nullptr이 됨
*/

unique_ptr<int> returnUniqePtr() {
	//unique_ptr를 직접 반환하면 소유권 이전됨
	//따라서 함수 종료 후에도 메모리 누수 발생하지 않음

	//return unique_ptr<int>(new int(6));
	/*
	new int(6)는 int하나 메모리 할당 후, 값을 6으로 초기화해서 int*반환
	new int[6]는 길이6인 int배열 메모리 할당 후, int*반환
	*/
	return make_unique<int>(6);//스마트 포인터 스타일
}
unique_ptr<int[]> retrunIntArray() {
	/*
	unique_ptr<T>는 단일 객체
	unique_ptr<T[]>로 배열 관리
	*/
	//return unique_ptr<int[]>(new int[6]);
	return make_unique<int[]>(6);//스마트 포인터 스타일
}
void TakeUniquePtr(unique_ptr<int>ptr) {
	cout << "func: Take unique ptr" << endl;
	cout << "\tvalue = " << *ptr << endl;
	/*
	파라미터로 전달된 unique_ptr은 이 함수 안에서만 유효함
	함수가 끝난후에는 자동으로 메모리 해제됨
	*/
}
void UseUniquePtr(unique_ptr<int>& ptr) {
	cout << "func: Use unique ptr" << endl;
	*ptr += 1;
}

int main() {
	unique_ptr<int> p1 = returnUniqePtr();
	//unique_ptr<int> copy = p1;	//컴파일err 유니크 포인터 복사 시도
	TakeUniquePtr(move(p1));	//unique_ptr<int> parameter = move(p1)과 같음
	//cout << *p1 << endl; // err: cout<< nullptr 

	unique_ptr<int> p2 = returnUniqePtr();
	unique_ptr<int>& refference = p2;	//참조는 가능
	cout << *refference << endl;
	UseUniquePtr(p2);
	cout << *p2 << endl;	//소유권을 넘긴것이 아니기에 nullptr이 아님

	return 0;
}