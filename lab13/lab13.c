#include <stdio.h>


int get_letter_num(int c) {
    if ( c >= 'a' && c <= 'z') {
        return c - 'a'; 
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A';
    } else {
        return -1;
    }
}


int get_letter_from_num(int n) {
    return 'a' + n;
}


unsigned long set_from_letter(int c) {
    int n = get_letter_num(c);
    if (n != -1) {
        return 1ull << n; 
    } else {
        return 0;
    }
}


int main() {
    unsigned long vowels = set_from_letter('a')|set_from_letter('e')|set_from_letter('o')|set_from_letter('u')|set_from_letter('y');
    unsigned long letter_set = 0;
    int c;
    do {
    c = getchar();
    unsigned long letters_set = letters_set|set_from_letter(c);
    } while(c != '?');
    unsigned long vowels_set = letter_set & vowels;
    int idx = 0;
    while(vowels_set != 0)  {
        if(vowels_set % 2 == 1) {
            printf("%c", get_letter_from_num(idx));
        }
        vowels_set >>= 1;
        idx ++;
    }
    // for(c = 'a'; c <= 'z'; c++ ) {
    //     if((set_from_letter(c)&vowels_set) != 0) {
    //         printf("%c", )
    //     }
    // }
}