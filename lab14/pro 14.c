#include <stdio.h>



void print_matr(int n, int m, double matr[n][m]) {              // Здесь массив не копируется, как аргумент, передается тока адрес на него, то есть, если мы его изменим в функции, то он изменится в программе
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%lf ", matr[i][j]);
        }
        printf("\n");
    }
}


void linearize(int n, double matr[n][n]) {
    int id_c = 0;
    for(int id_c = 0; id_c < n/2; id_c++) {
        for(int j = id_c; j < n - id_c; j++) {
            print("%f ", matr[id_c][j]);
        }
        for(int i = id_c + 1; i < n - id_c; i++) {
            printf("%f ", matr[i][n - id_c - 1]);
        } 
        for(int j = n - id_c - 2; j >= id_c; j--) {
            printf("%f ", matr[n - id_c - 1][j]);
        }
        for(int i = n - id_c - 2; i > id_c ; i--) {
            printf("%f ", matr[i][id_c]);
        }
    }
    if ( n % 2 ) {
        printf("%f ", matr[n / 2][ n / 2 ]);
    }

}



int main() {
    int n = 2;
    //scanf("%d", &n);
    //double arr[n] = {0};         // ОДНОМЕРНЫЙ МАССИВ
    //arr[5] = 42.0;          // l-value то, чему можно присвоить значение -> !массив l-value не является!
    //arr[7] = arr[5]; 
                              // ДВУМЕРНЫЙ МАССИВ
    double matr[n][n];
    for (int i = 0 ; i < n; i++) {
        for(int j = 0; j < n; j ++) {
            matr[i][j] = 0;
        }
    }
    //or
    // for (int i = 0 ; i < n; i++) {
    //     for(int j = 0; j < n; j ++) {
    //         scanf("%lf", &matr[i][j]);
    //     }
    // }
    // print_matr(n, n, matr);

           // Разименованный указатель
    // int a = 42;
    // int *p = &a;
    // *p = 1337;
    // int b = *p + 1;
    // printf("%d", a);       // output >>> 1337

    // double *p = arr;        // Одинаковые с нижним
    // *p = &arr[0];         // <- с этим 

    // linearize(n, matr[n][n]);











}