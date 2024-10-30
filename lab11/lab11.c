#include <stdio.h>

enum state { 
    state_out_num,    
    state_maybe_signed_num,
    state_maybe_num,
    state_exit_from_word,
};
 
enum state s = state_out_num;   

int sep(int c) {
    return (c == '\t') || (c == ' ') || (c == '\n') || (c == ',') || (c == EOF) ; 
}
/*  Tests:
    +1 da + 1b - b1 110100101321 101 -100 9832132131100101 dsadsa1 1dsadsadsa 10 -1 101 -> -100 101
    +1 +1 +1 -1 -1 -1   -> +1 -1
    b b b b b b  
    b 1b +1 b b b b
    +1 0 +1 0 0 0  -> +1 0
*/ 


int main() {
    int k = 0;
    int sign;
    int c;    
    int res = 0;
    int isSignAlone = 1;
    int output_num = 0, d = 1; 
    printf("===============\n");
    do {   
        c = getchar();
        if (s == state_out_num) {
            if (c == '+' || c == '-') {
                s = state_maybe_signed_num;
                sign = c;
                k ++;
            } else if (c == '0' || c == '1') {
                s = state_maybe_num;
                res = res * 2 + (c % 2); 
                k ++;                              
            } else if ( !sep(c) ) {
                s = state_exit_from_word;
            }
        } else if (s == state_maybe_signed_num) {
            if (c == '0' || c == '1') {
                res = res * 2 + (c % 2); 
                isSignAlone = 0;
            } else if( sep(c) && !isSignAlone){
                s = state_out_num;
                if (k % 3 == 0) {
                    output_num = 0; 
                    d = 1; 
                    while (res) {
                        output_num += (res % 2) * d;
                        res /= 2;
                        d *= 10;
                    }
                    printf("%c%d ", sign, output_num);
                    k = 0;
                }
                isSignAlone = 1;
                res = 0;
            
            } else {
                s = state_exit_from_word;
                k --;
            }
        } else if (s == state_maybe_num) {
            if (c == '0' || c == '1') {
                s = state_maybe_num;
                res = res * 2 + (c % 2);  

            } else if ( sep(c) ){
                s = state_out_num;
                //printf("ur num is %d\n", res);
                if (k % 3 == 0) {
                    output_num = 0; 
                    d = 1; 
                    while (res) {
                        output_num += (res % 2) * d;
                        res /= 2;
                        d *= 10;
                    }
                    printf("%d ", output_num);
                    k = 0;
                }
                res = 0;
            } else {
                s = state_exit_from_word;
                res = 0;
                k --;
            }
        } else if (s == state_exit_from_word) {
            if ( sep(c) ) {
                s = state_out_num;
            }
        }
    } while (c != EOF);
}
