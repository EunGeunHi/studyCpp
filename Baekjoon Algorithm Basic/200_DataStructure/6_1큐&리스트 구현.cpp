//10845. ���� ť stl
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

		Node() : data()/*T�⺻������ ȣ���*/ ,prev(null), next(null){}
		Node(T value):  data(value), prev(null), next(null) {}
	};
public:	//auto�� �����Ҽ� �ֵ���
	class Iterator{	//������ ������ ���ͷ�����,
		friend class List<T>;//ListŬ�������� Iterator.current������ �� �ֵ���
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
//����Ʈ ��� ����
private:
	Node* head;
	Node* tail;
	//Node* fin;	//List.end()���� ��ȯ�� iterator���ؼ�->���̳��� 
	size_t size;	//stl���� size�� size_tŸ��
public:
	List(){}

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
			cout << "�Է�\" " << command << " \" Ȯ�� �ʿ�" << endl;
		}
	}
	return 0;
}
