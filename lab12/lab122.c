#include <stdio.h>

int len_counter(int a) {
    int c = 0;
    while (a != 0) {
        a /= 10;
        c ++;
    }
    return c;
}


int mypow(int a, int b) {
    int c = 1;
    for(int i = 0; i < b; i++) {
        c *= a;
    }
    return c;
}





int shift(int num, int step) {
    int c = mypow(10, step);
    num = (num % c) * mypow(10, len_counter(num / c)) + (num / c);
    return num;
}


int main() {
    int num, step;
    while (1==scanf("%d", &num) && 1==scanf("%d", &step)) {              // Ввод двух чисел: число,  которое сдвигается и число количеств сдвигов
        printf("Input num: %d | Output num: %d\n", num, shift(num, step % len_counter(num)));         
    }

}