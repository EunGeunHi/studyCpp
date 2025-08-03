//10845. 정수 큐&리스트 구현
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

		Node() : data()/*T기본생성자 호출됨*/, prev(nullptr), next(nullptr) {}
		Node(T value, Node* p, Node* n) : data(value), prev(p), next(n) {}
	};
public:	//auto가 접근할수 있도록
	class Iterator {	//데이터 접근할 이터레이터,
		friend class List<T>;//List클래스에서 Iterator.current접근할 수 있도록
	private:
		Node* current;
	public:
		Iterator(Node* ptr = nullptr) : current(ptr) {}
		//이터레이터 복사 생성자 필요 -> 매개변수로 사용하기 위해서 -> 디폴트로도 충분

		Iterator& operator++() { current = current->next; return *this; }
		Iterator& operator++(int) { Iterator temp = *this; ++(*this); return temp; }
		Iterator& operator--() { current = current->prev; return *this; }
		Iterator& operator--(int) { Iterator temp = *this; --(*this); return temp; }
		T& operator*() { return current->data; }
		bool operator==(const Iterator& other) const { return current == other.current; }
		bool operator!=(const Iterator& other) const { return current != other.current; }

	};
	//리스트 멤버 변수
	// 헤드 테일 더미노드로 엣지케이스 처리 용이화
private:
	Node* head;
	Node* tail;
	size_t list_size;

public:
	List() {
		head = new Node();
		tail = new Node();
		head->next = tail;
		tail->prev = head;
		list_size = 0;
	}
	Iterator begin() { return Iterator(head->next); }
	Iterator end() { return Iterator(tail); }
	bool empty() { return list_size == 0; }
	size_t size() { return list_size; }
	Iterator insert(Iterator position, const T& new_value) {
		Node* pos = position.current;
		Node* newNode = new Node(new_value, pos->prev, pos);
		pos->prev->next = newNode;
		pos->prev = newNode;
		++list_size;
		return Iterator(newNode);
	}
	Iterator erase(Iterator position) {
		if (position.current == head || position.current == tail) {
			throw std::out_of_range("Cannot erase dummy nodes or invalid iterator");
		}
		Node* deletedNode = position.current;
		deletedNode->prev->next = deletedNode->next;
		deletedNode->next->prev = deletedNode->prev;

		Node* nextNode = deletedNode->next;
		delete deletedNode;
		--list_size;
		return Iterator(nextNode);
	}
	void push_back(const T& new_value) { this->insert(--this->end(), new_value); }
	void push_front(const T& new_value) { this->insert(this->begin(), new_value); }
	T& back() { return *(--this->end()); }
	T& front() { return *(this->begin()); }
	void pop_back() {
		if (empty()) throw std::out_of_range("pop_back() on empty list");
		this->erase(--this->end());
	}
	void pop_front() {
		if (empty()) throw std::out_of_range("pop_front() on empty list");
		this->erase(this->begin());
	}
	void clear() {
		Iterator it = begin();
		while (it != end()) {
			it = erase(it); // erase는 삭제된 요소의 다음 이터레이터를 반환
		}
	}

	~List() {
		clear();
		delete head;
		delete tail;
	}
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
	int size() { return (int)data.size(); }
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
