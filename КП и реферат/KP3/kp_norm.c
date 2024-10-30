#include <stdio.h>
#include <math.h>


double get_machine_epsilon() {
    double eps = 1;
    int i = 0;
    while (1.0 + (eps / 2) > 1.0) {
        eps /= 2;
        i++;
    }
    return eps;
    //printf("Machine epsilon is %.16E and step num is %d\n", eps, i); 
}


double binpow(double x, int y) {
    double res = 1;
    while (y) {
        if (y & 1) {
            res *= x;
        }
        x *= x;
        y >>= 1;
    }
    return res;
}


double mysin(double x) {
    double res = x;
    unsigned long long k = 1;
    for(int i = 1; i < 4; i ++) {     
        k *= (2 * i + 1) * (2 * i);
        res += binpow(-1, i) * ((double)(binpow(x, 2*i + 1)) / k);
    } 
    return res;
}



int main() {
    int segmentation = 49;
    double point_segment, delta;
    double eps = get_machine_epsilon();
    for(int i = 0; i <= segmentation; i++) {
        point_segment = (double)i / segmentation;
        delta = sin(point_segment) - mysin(point_segment);
        printf( " | %lf || sin(x) = %.8lf || mysin(x) = %.8lf || delta = %.13lf | \n", point_segment, sin(point_segment), mysin(point_segment), delta);
    }
    printf("\nMachine epsilon is %e\n", eps);
}