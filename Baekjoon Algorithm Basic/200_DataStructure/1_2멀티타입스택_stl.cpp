//stl �����̳ʴ� �⺻������ �ϳ��� Ÿ�Ը� ����
// ��ȸ�� ���(1.��� ������ 2.std::variant 3.std::any)��� ���������� ����
// ���⼱ ������� ����
#include <iostream>
#include <string>
#include <stack>
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
	void combineOsValue(ostream& os) const override { os << "(integer) " << value; }
};
class StackStrData : public StackBaseData {
private:
	string value;
public:
	StackStrData(string value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "(string) " << value; }
};
class StackDoubleData : public StackBaseData {
private:
	double value;
public:
	StackDoubleData(double value) :value(value) {}
	void combineOsValue(ostream& os) const override { os << "(double) " << value; }
};
//�Է� ó��
enum StackFunction { UNKNOWN, PUSH, POP, SIZE, EMPTY, TOP };
enum DataType { UNKOWN, INT, STR, DOUBLE };
bool isSeveral(const string&);
void parsing(string&, unique_ptr<StackBaseData>, DataType&);
StackFunction toStackFunction(string&);


int main1() {
	stack<unique_ptr<StackBaseData>> st;

	st.push(make_unique<StackIntData>(12));
	st.push(make_unique<StackDoubleData>(12));
	st.push(make_unique<StackStrData>("12"));

	while (!st.empty()) {
		/*		����Ʈ �����Ͷ� ���� �޸� ���� ���� �ʾƵ� ��
		StackBaseData* temp = st.top();
		cout<< st.top();
		st.pop()
		delete temp;
		*/
		cout << *st.top() << endl;
		st.pop();
	}
	return 0;
}



int main() {
	int num_commands;
	cin >> num_commands;
	cin.ignore();

	stack<unique_ptr<StackBaseData>> st;	//��ƼŸ�� ���� ����

	string command;
	unique_ptr<StackBaseData> data;
	DataType data_type;
	for (int i = 0; i < num_commands; ++i) {
		getline(cin, command);

		if (isSeveral(command))
			parsing(command, data, data_type);

		switch (toStackFunction(command)) {
		case PUSH:
			st.push(data);
			break;
		case POP:
			if (st.empty())	//�� ���� ���� ó��
				cout << -1 << endl;
			else {
				//cout << st.pop() << endl;  //stack.pop()�� ��ȯ�� void
				cout << st.top() << endl;
				st.pop();
			}
			break;
		case SIZE:
			cout << st.size() << endl;
			break;
		case EMPTY:
			cout << st.empty() << endl;
			break;
		case TOP:
			if (st.empty())	//�� ���� ���� ó��
				cout << -1 << endl;
			else
				cout << st.top() << endl;
			break;
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

void parsing(string& command, unique_ptr<StackBaseData> data, DataType& data_type) {

	size_t spacePos = command.find(' ');
	string command_splited = command.substr(spacePos + 1);
	/*
		ó���� �� "��' STR,

		��� isdigit(ch)�� INT, stoi()
		.�ϳ� �鼭 ��� isdigit(ch)�ٸ� DOUBLE,

	*/
	for (char ch : command_splited) {
		
	}
	
	command = command.substr(0, spacePos);
}
StackFunction toStackFunction(string& command) {
	if (command == "push") return PUSH;
	else if (command == "pop") return POP;
	else if (command == "size") return SIZE;
	else if (command == "empty") return EMPTY;
	else if (command == "top") return TOP;
	else return UNKNOWN;
}




/*todo

 unique_ptr<StackBaseData> data;
 parsing(command, data, data_type);
 �ؼ� ������ �Ǵ���.
 shared_ptr<>ã�� �� ��.
*/