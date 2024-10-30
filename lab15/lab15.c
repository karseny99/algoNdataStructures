#include <stdio.h>

// Замена элементов побочной диагонали суммами элементов, проходящих через них главной и других
// параллельных диагоналей 


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
    printf("==========================================\n");


       

    int count = 0, j = 0, i = n - 3, s = 0, tmp_i, tmp_j; 
    for(count = 0; count < n - 2; count++) { 
        tmp_i = i;
        tmp_j = j;
        while(tmp_i < n && tmp_j < n) {
            s += matr[tmp_i][tmp_j];
            tmp_i++;
            tmp_j++;
        }
        matr[n - 2 - count][1 + count] = s;

        if(i - 2 >= 0) {
            i-=2;
        } else if( i == 0 ){
            j += 2;
        } else {
            i = 0;
            j ++;
        }
        s = 0;
        
    }





    printf("=================OUTPUT=================\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if ( matr[i][j] > 9 ) {
                printf("%d  ", matr[i][j] );
            } else if( matr[i][j] > 99) {
                printf("%d ", matr[i][j] );
            } else {
                printf("%d   ", matr[i][j]);
            }
            //scanf("%d", &matr[i][j]);
        }
        printf("\n");
    }
    printf("==========================================\n");














}

































