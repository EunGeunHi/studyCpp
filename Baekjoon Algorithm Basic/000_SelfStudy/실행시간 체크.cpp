#include <stdio.h>
#include <time.h>


int main() {
    clock_t start, finish;
    double duration;

    start = clock();

    /*���� �ð��� �����ϰ� ���� �ڵ�*/

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f��", duration);

    return 0;
}
