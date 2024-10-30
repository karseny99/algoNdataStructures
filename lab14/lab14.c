#include <stdio.h>






int main() {
    int n;
    scanf("%d", &n);
    int matr[n][n];
    //int dir[4] = {1, 0, -1, 0};
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

            printf("%d  ", matr[i][j] );
            //scanf("%d", &matr[i][j]);
        }
        printf("\n");
    }
    printf("==========================================\n");




    int j = 0, i = 0;
    int sdvig = 1;

    for(i = diag - 1; i >= 0; --i) {
        printf("%d " , matr[i][j]);
            //printf("%d j = %d\n",matr[i][j], j);
        j++;
    }
    i = 1;
    j = n - 1;
    for(sdvig; sdvig <= n - 1; sdvig ++) {


        while (i <= n - 1){
            printf("%d ", matr[i][j]);
            j--;
            i++;
        };
        i--;
        j++;

        i -= sdvig;
        j -= sdvig;


        while (j < n - sdvig) {
            printf("%d " , matr[i][j]);
            j++;
            i--;
        }
        i ++;
        j --;



        i += (sdvig + 1);
        j += sdvig; 

    }

    putchar('\n');



}