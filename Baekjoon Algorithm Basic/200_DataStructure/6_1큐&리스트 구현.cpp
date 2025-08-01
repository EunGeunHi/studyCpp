//10845. 정수 큐 stl
/*
push X:	X를 큐에 넣음
pop	:	큐에 가장 앞에 있는 정수 빼고 그 정수를 출력, 비어있다면 -1출력
size:	큐에 들어있는 갯수 출력
empty:	비어있으면1, 아니면 0
front:	큐의 가장 앞에 있는 정수 출력, 비어있다면 -1출력
back:	큐의 가장 뒤에 있는 정수 출력, 비어있다면 -1출력
*/

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List {
private:
	struct Node {	//데이터 담을 노드
		T data;
		Node* prev;
		Node* next;

		Node() : data()/*T기본생성자 호출됨*/ ,prev(null), next(null){}
		Node(T value):  data(value), prev(null), next(null) {}
	};
public:	//auto가 접근할수 있도록
	class Iterator{	//데이터 접근할 이터레이터,
		friend class List<T>;//List클래스에서 Iterator.current접근할 수 있도록
	private:
		Node* current;
	public:
		Iterator(Node* ptr = nullptr) : current(ptr){}

		Iterator& operator++() { current = current->next; return *this; }
		Iterator& operator++(int) { Iterator temp = *this; ++(*this); return temp; }
		Iterator& operator--() { current = current->prev; return *this; }
		Iterator& operator--(int) { Iterator temp = *this; --(*this); return temp; }
		T& operator*() { return current->data; }
		bool operator==(const Iterator& other) const { return current == other.current; }
		bool operator!=(const Iterator& other) const { return current != other.current; }
	};
//리스트 멤버 변수
private:
	Node* head;
	Node* tail;
	//Node* fin;	//List.end()에서 반환할 iterator위해서->더미노드로 
	size_t size;	//stl에서 size는 size_t타입
public:
	List(){}

};

//큐 구현
template<typename T>
class Queue {
private:
	List<T> data;
public:
	void push(T new_data) { data.push_front(new_data); }
	void pop() { data.pop_front(); }
	T& front() { return data.front(); }
	T& back() { return data.back(); }
	bool empty() { return data.empty(); }
	int size() { return data.size(); }
};

int main() {

	int num_command;
	cin >> num_command;

	Queue<int> q;

	string command;
	for (int i = 0; i < num_command; ++i) {
		cin >> command;
		if (command == "push") {
			int data;
			cin >> data;
			q.push(data);
		}
		else if (command == "pop") {
			if (q.empty())
				cout << -1 << endl;
			else {
				cout << q.front() << endl;
				q.pop();
			}
		}
		else if (command == "size") {
			cout << q.size() << endl;
		}
		else if (command == "empty") {
			cout << q.empty() << endl;
		}
		else if (command == "front") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.front() << endl;
		}
		else if (command == "back") {
			if (q.empty())
				cout << -1 << endl;
			else
				cout << q.back() << endl;
		}
		else {
			cout << "입력\" " << command << " \" 확인 필요" << endl;
		}
	}
	return 0;
}
