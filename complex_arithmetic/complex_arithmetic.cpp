
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Complex {
private:
    float real;
    float imaginary;



public:
    Complex(float r = 0.0, float i = 0.0) {
        real = r;
        imaginary = i;
    }


    void print() const {
        cout << fixed << setprecision(2);//소숫점 이하 두자리
        cout << real << " + " << imaginary << " i";
    }

    void printWithMagnitude() const {
        print();
        cout << " (magnitude: " << fixed << setprecision(2) << magnitude() << ")";
    }
};

// 난수 생성 함수
float randomFloat() {
    return static_cast<float>(rand()) / RAND_MAX * 10.0f;
}
enum Menu {
    ShowComplex = 1,
    Sum,
    Product,
    Sort,
    EXIT
};

int main() {
    int seed, command;
    cin >> seed >> command;
    srand(seed);

    const int N = 5;
    Complex* table[N];

    generateComplex(table, N);

        case ShowComplex:

            break;

        case Sum: {

            break;
        }

        case Product: {

            break;
        }

        case Sort:

            break;

        case EXIT:
            cout << "[Program terminated.]" << endl;
            break;


            freeTable(table, N);
            return 0;
}
