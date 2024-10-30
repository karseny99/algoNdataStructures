#include <stdio.h>



// Modulo (%)


int modulo(int a, int b) {
    return ((a % b + b) % b);
}


// min&max


int max(int x, int y) {
    if (x > y) {
        return x;
    } else {
        return y;
    }

}
int min(int x, int y) {
    if (x > y) {
        return y;
    } else {
        return x;
    }
}



// new (i, j) , l w/ modulo


int i_func(int i, int j, int l, int k) {
    return modulo(min(max(min(i - j, i - l), j - l), i - k), 30);
}

int j_func(int i, int j, int l, int k) {
    return modulo(max(min(max(i - j, i - l), j - l), i - k), 30);
}

int l_func(int i, int j, int l, int k) {
    return modulo(i, 30) - modulo(j, 30) + modulo(l, 30) - modulo(k, 30);
}






// w/out modulo

// int i_func(int i, int j, int l, int k) {
//     return min(max(min(i - j, i - l), j - l), i - k) % 30;
// }

// int j_func(int i, int j, int l, int k) {
//     return max(min(max(i - j, i - l), j - l), i - k) % 30;
// }

// int l_func(int i, int j, int l, int k) {
//     return i % 30 - j % 30 + l % 30 - k % 30;
// }





// is in triangle?


// int pos_check(int x, int y) {
//     return (y <= -x + 10) * (x >= -10) * (10 + x <= y);

// }



// Other triangle (0,0) , (0,10) , (5, 5)

int pos_check(int x, int y) {
    return ((y <= -x + 10) * (x >= 0) * (x <= y));

}



int main() {



    int i0 = 29;
    int j0 = -6;
    int l0 = 1;
    int k = 1;



    int i, j, l, pos_condition = 0;
    if (pos_check(i0, j0)) {
        i = i0;
        j = j0;
        l = l0;
        pos_condition = 1;
        k = 0;
    } else {
        for(; k <= 50; ++k) {
            i = i_func(i0, j0, l0, (k-1));
            j = j_func(i0, j0, l0, (k-1));
            l = l_func(i0, j0, l0, (k-1));
            i0 = i;
            j0 = j;            
            l0 = l; 
            pos_condition = pos_check(i, j);
            //printf("%d --- (%d,%d)  l=%d \n", k, i, j, l);
            if (pos_condition) {
                break;            
            }
        }
    }


    if (pos_condition) {
        printf("Dowel k=%d ; (i,j) = (%d, %d) ; l=%d", k,i,j,l);
    } else {
        k--;
        printf("Ne dowel k=%d ; (i,j) = (%d, %d) ; l=%d", k,i,j,l);
    } 
}