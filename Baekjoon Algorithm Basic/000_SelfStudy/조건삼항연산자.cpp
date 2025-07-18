#include <iostream>
using namespace std;

int getFee(bool v) {
	return v ? 1 : 0;
}

int main() {
	cout << getFee(true) << endl;		// 1
	cout << getFee(false) << endl;		// 0
	bool value = true;
	cout << (value ? 1 : 0) << endl;	// 1
	cout << (!value ? 1 : 0) << endl;	// 0

	return 0;
}
