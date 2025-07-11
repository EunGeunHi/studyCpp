// 10828����. ��ƼŸ�� ���� ���� ����
#include <iostream>
#include <string>
#include <memory>

using namespace std;

//���� ������Ʈ
class StackBaseData {
public:
	virtual ~StackBaseData() = default;
	virtual void combineOsValue(ostream& os) const = 0;
	friend ostream& operator<< (ostream& os, const StackBaseData& data) {	// cout<< ���� ���
		data.combineOsValue(os);	//������
		return os;
	}
};
class StackIntData : public StackBaseData {
private:
	int value;
public:
	StackIntData(int value) :value(value) {}
	void combineOsValue(ostream& os) const override { os/* << "[integer] "*/ << value; }
};
class StackStrData : public StackBaseData {
private:
	string value;
public:
	StackStrData(string value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "[string] " << value; }
};
class StackDoubleData : public StackBaseData {
private:
	double value;
public:
	StackDoubleData(double value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "[double] " << value; }
};
class StackUnknownData : public StackBaseData {
private:
	string value;
public:
	StackUnknownData(string value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "[unkown] " << value; }
};
//���� ����
template<typename T>
class MyStack {
private:
	T* data;
	int idx_top;
public:
	MyStack(int n) {
		data = new T[n];
		idx_top = -1;
	}
	~MyStack() { delete[] data; }

	bool isEmpty() { return idx_top == -1; }
	void push(T input) {
		data[++idx_top] = input;
	}
	T pop() {
		/*if (isEmpty())
			return -1;*/	//Ÿ�� �������� �ʾƼ� ��ȯ�� �ټ� ����. erró�� �Ѵٸ� throw�� ó���ؾ��� ��
		return data[idx_top--];
	}
	int size() { return idx_top + 1; }
	T top() {
		/*if (isEmpty())
			return -1;*/
		return data[idx_top];
	}
	int getIdxTop() { return idx_top; }

};

//�Է� ó��
enum StackFunction { UNKNOWN, PUSH, POP, SIZE, EMPTY, TOP, QUIT };
enum DataType { UNKOWN, INT, STR, DOUBLE };
bool isSeveral(const string&);
void parsing(string&, unique_ptr<StackBaseData>&, DataType&);
StackFunction toStackFunction(string&);



int main() {
	int num_commands;
	cin >> num_commands;
	cin.ignore();

	MyStack<unique_ptr<StackBaseData>> st = MyStack<unique_ptr<StackBaseData>>(num_commands);

	string command;
	unique_ptr<StackBaseData> data;
	DataType data_type;
	for (int i = 0; i < num_commands; ++i) {
		getline(cin, command);

		if (isSeveral(command))
			parsing(command, data, data_type);

		switch (toStackFunction(command)) {
		case PUSH:
			if (!data) {
				cout << "parsing err" << endl;
				break;
			}
			if (data_type == UNKNOWN) {
				cout << "push err :������ ���� �̻�" << endl;
				cout << "\t" << *data << "\t�� �ùٸ� �Է������� �ƴմϴ�" << endl;
				break;
			}
			st.push(move(data));	// ���ڸ� �����ؼ� ����-> move�� ����
			break;
		case POP:
			if (st.isEmpty())	//�� ���� ���� ó��
				cout << -1 << endl;
			else {
				cout << *st.top() << endl;
				st.pop();
			}
			break;
		case SIZE:
			cout << st.size() << endl;
			break;
		case EMPTY:
			cout << st.isEmpty() << endl;
			break;
		case TOP:
			if (st.isEmpty())	//�� ���� ���� ó��
				cout << -1 << endl;
			else
				cout << *st.top() << endl;
			break;
		case QUIT:
			return 0;
		case UNKNOWN:
		default:
			cout << "switch default! :�Է� �̻�" << endl;
			break;
		}
	}

	return 0;
}


bool isSeveral(const string& command) {
	return (command.find(' ') == string::npos) ? false : true;
}
bool isString(const string& str) {
	return (str.front() == '"' && str.back() == '"')
		|| (str.front() == '\'' && str.back() == '\'');	// ó���� �� ��� "�ų� '�� str
}
bool isDouble(const string& str) {
	try {
		size_t pos;	//�Ǽ��� �ƴ� ���� ������ �ε��� ����
		double data = stod(str, &pos);//�Ǽ���ȯ
		for (size_t i = pos; i < str.length(); ++i)
			if (str[i] != ' ') return false; //���� �ڿ� ������ �ƴ� �ٸ� ���� ���������� false
		return true;	//��ȯ �����ϰ�, �ڿ� ��ȿ���� ���� ���� ���ٸ� true
	}
	catch (...) {
		return false;
	}
}
bool isDigits(const string& str) {
	try {
		size_t pos;
		int data = stoi(str, &pos);
		for (size_t i = pos; i < str.length(); ++i)
			if (str[i] != ' ') return false;
		return true;
	}
	catch (...) {
		return false;
	}
}

void parsing(string& command, unique_ptr<StackBaseData>& data, DataType& data_type) {

	size_t spacePos = command.find(' ');
	string command_splited = command.substr(spacePos + 1);

	//������ Ÿ�� �˻��� �����Ϳ� ������ ����
	if (command_splited.empty()) {//�� ���ڿ� ó�� ����
		data_type = UNKOWN;
		data = make_unique<StackUnknownData>(command_splited);
	}
	else if (isString(command_splited)) {
		data_type = STR;
		data = make_unique<StackStrData>(command_splited.substr(1, command_splited.length() - 2));
	}
	else if (isDigits(command_splited)) {
		data_type = INT;
		data = make_unique<StackIntData>(stoi(command_splited));
	}
	else if (isDouble(command_splited)) {
		data_type = DOUBLE;
		data = make_unique<StackDoubleData>(stod(command_splited));
	}
	else {
		data_type = UNKOWN;
		data = make_unique<StackUnknownData>(command_splited);
	}

	command = command.substr(0, spacePos);
}
StackFunction toStackFunction(string& command) {
	if (command == "push") return PUSH;
	else if (command == "pop") return POP;
	else if (command == "size") return SIZE;
	else if (command == "empty") return EMPTY;
	else if (command == "top") return TOP;
	else if (command == "quit") return QUIT;
	else return UNKNOWN;
}