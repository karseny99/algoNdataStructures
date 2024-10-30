#include <stdio.h>

const int a = 1072, ya = 1103, A = 1040, YA = 1071;
const int y = 1091, o = 1086, i = 1080, ee = 1101, bI = 1099, u = 1102, e = 1077, e_ = 1105;
const int Y = 1059, O = 1054, I = 1048, EE = 1069, BI = 1067, U = 1070, E = 1045, E_ = 1025;


int get_num_from_letter(int c) {
    if (c >= a && c <= e) {
        return c - a;
    } else if (c > e && c <= ya) {
        return c - a + 1;
    } else if (c == e_ || c == E_) {
        return 6;
    } else if (c >= A && c <= E) {
        return c - A;
    } else if (c > E && c <= YA) {
        return c - A + 1;
    } else {
        return -1;
    } 
}


int utf8_get_num(int c) {
    int c1 = c, num_of_cp = 0;
    
    if (c < 0x80) {
        return c;               
    }

    while (c1) {
        if (c1 % 2) {
            num_of_cp++;
        } else {
            num_of_cp = 0;
        }
        c1 >>= 1;
    }

    if (num_of_cp== 2) {
        c -= 0xc0;
    } else if (num_of_cp == 3) {
        c -= 0xe0;
    } else if (num_of_cp == 4) {
        c -= 0xf0;
    }
    for(int i = 1; i < num_of_cp; i++) {
        unsigned long long c2 = getchar() - 0x80;
        c <<= 6;
        c |= c2;
    }
    return c;
}


int get_set_from_letter(int c) {
    int n = get_num_from_letter(utf8_get_num(c));
    if (n != -1) {
        return 1ull << n;
    } else {
        return 0;
    }
}

int sep(int c) {
    return (c == '\t') || (c == ' ') || (c == '\n') || (c == ',') || (c == EOF) ; 
}


int main() {

    unsigned int c, set_c, word = 0;
    int issimilar = 0, hasvowel = 0, vowel_not_in_seq = 1;
    unsigned int vowels = get_set_from_letter(a)|get_set_from_letter(y)|get_set_from_letter(o)|get_set_from_letter(i)|get_set_from_letter(ee)|get_set_from_letter(bI)|get_set_from_letter(u)|get_set_from_letter(e)|get_set_from_letter(e_)|get_set_from_letter(A)|get_set_from_letter(Y)|get_set_from_letter(O)|get_set_from_letter(I)|get_set_from_letter(EE)|get_set_from_letter(BI)|get_set_from_letter(U)|get_set_from_letter(E)|get_set_from_letter(E_);
    

    do {
        c = getchar();
        if (!sep(c)) {                                        
            set_c = get_set_from_letter(c);
            if(vowels & set_c) {
                if (word == (word|set_c)) { 
                   issimilar = 1;
                } else {
                    hasvowel = 1;
                }
            }
            word |= set_c;    
        } else if (sep(c)) {
            if (issimilar == 0 && hasvowel == 1) {
                printf("YES");
                vowel_not_in_seq = 0;
                break;
            }
            hasvowel = 0;
            issimilar = 0;
            word = 0;
        }
    } while(c != EOF);

    if (vowel_not_in_seq) {
        printf("NO");
    }
}