/*
1.class Complex
    private 실수부,허수부
    복소수 생성자
    복소수 출력 함수
    복소수 덧셈과 곱셈 수행하는 멤버함수
    복소수 크기 반환하는 float magnitude()const 함수
2.void generateComplex (Complex* table[],int size)
    난수를 사용해 복소수 5개 생성, 복소수 객체는 new로 생성
3.Complex sumComplex (Complex* table[],int size)
    전체 복소수의 합을 계산하여 반환
    복소수 반환할때 side effect유의
4.Complex multiflyComplex (Complex* table[],int size)
    전체 복소수의 곱을 계산하여 반환
    복소수 반환할때 side effect유의
5.void sortComplexByMagnitude (Complex* table[],int size)
    복소수를 크기 기준으로 오름차순 정렬
6.void showComplexWithMagnitude (Complex* table[],int size)
    복소수와 크기를 함께 출력

7.main()함수에서 출력
    생성된 5개 복소수 출력
    5개의 복소수 합
    5개의 복소수 곱
    복소수 크기 오름차순 정렬 결과 출력

    Complex Numbers:
    3.25 + 1.88 i
    2.11 + 4.32 i
    ...

    Sum: ~~~
    Product: ~~~

    Sorted by Magnitude:
    3.25 + 1.88 i (magnitude:3.77)
    ...

*
a+bi * c+di  =  (ac-bd)+(ad+bc)i
a+bi의 크기  =  sqrt(a*a + b*b) 

실수 난수 범위는 0.00~9.99
출력은 소수점 둘쨰 자리까지 고정
*/





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
