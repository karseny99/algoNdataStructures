#include <stdio.h>


/*

16 14 10 4
13 9  3  5
8  2  6  11
1  7  12 15

*/


int main() {
    int n;
    scanf("%d", &n);
    int matr[n][n];
    int o = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            matr[i][j] = o + 1;
            o = matr[i][j];
            //scanf("%d", &matr[i][j]);
        }
    }



    printf("=================INPUT=================\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if ( matr[i][j] > 9 ) {
                printf("%d  ", matr[i][j] );
            } else {
                printf("%d   ", matr[i][j] );
     
            }
            //scanf("%d", &matr[i][j]);
        }
        printf("\n");
    }
    printf("==========================================\n>>> ");


    int shift = 0;
    int j = 0, i = n - 1;

    for(shift = 0; shift <= n - 1; shift ++) {

        while (j < n - shift) {                // low-up diag
            printf("%d " , matr[i][j]);
            j++;
            i--;
        }
        i ++;
        j --;


        i += (shift + 1);
        j += shift; 

        while (i <= n - 1){                     // up-down diag
            printf("%d ", matr[i][j]);
            j--;
            i++;
        };
        i--;
        j++;

        i -= (shift + 1);
        j -= (shift + 1);
    }

}