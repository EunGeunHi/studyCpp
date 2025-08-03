//10845. ���� ť&����Ʈ ����
/*
push X:	X�� ť�� ����
pop	:	ť�� ���� �տ� �ִ� ���� ���� �� ������ ���, ����ִٸ� -1���
size:	ť�� ����ִ� ���� ���
empty:	���������1, �ƴϸ� 0
front:	ť�� ���� �տ� �ִ� ���� ���, ����ִٸ� -1���
back:	ť�� ���� �ڿ� �ִ� ���� ���, ����ִٸ� -1���
*/

#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List {
private:
	struct Node {	//������ ���� ���
		T data;
		Node* prev;
		Node* next;

		Node() : data()/*T�⺻������ ȣ���*/, prev(nullptr), next(nullptr) {}
		Node(T value, Node* p, Node* n) : data(value), prev(p), next(n) {}
	};
public:	//auto�� �����Ҽ� �ֵ���
	class Iterator {	//������ ������ ���ͷ�����,
		friend class List<T>;//ListŬ�������� Iterator.current������ �� �ֵ���
	private:
		Node* current;
	public:
		Iterator(Node* ptr = nullptr) : current(ptr) {}
		//���ͷ����� ���� ������ �ʿ� -> �Ű������� ����ϱ� ���ؼ� -> ����Ʈ�ε� ���

		Iterator& operator++() { current = current->next; return *this; }
		Iterator& operator++(int) { Iterator temp = *this; ++(*this); return temp; }
		Iterator& operator--() { current = current->prev; return *this; }
		Iterator& operator--(int) { Iterator temp = *this; --(*this); return temp; }
		T& operator*() { return current->data; }
		bool operator==(const Iterator& other) const { return current == other.current; }
		bool operator!=(const Iterator& other) const { return current != other.current; }

	};
	//����Ʈ ��� ����
	// ��� ���� ���̳��� �������̽� ó�� ����ȭ
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
			it = erase(it); // erase�� ������ ����� ���� ���ͷ����͸� ��ȯ
		}
	}

	~List() {
		clear();
		delete head;
		delete tail;
	}
};

//ť ����
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
			cout << "�Է�\" " << command << " \" Ȯ�� �ʿ�" << endl;
		}
	}
	return 0;
}
