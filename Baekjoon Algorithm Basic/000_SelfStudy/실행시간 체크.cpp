#include <stdio.h>
#include <time.h>


int main() {
    clock_t start, finish;
    double duration;

    start = clock();

    /*실행 시간을 측정하고 싶은 코드*/

    finish = clock();

    duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f초", duration);

    return 0;
}
