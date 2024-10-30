#include <stdio.h>
#include <math.h>

__attribute__ ((noinline)) double probros(double x) {
    return x;
}

double get_machine_epsilon() {
    volatile double eps = 1;
    int i = 0;
    while (1.0 + (eps / 2) > 1.0) {
        eps /= 2;
        eps = probros(eps);
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


typedef struct {
    double res;
    int num_of_iterations;
} return_helper;


return_helper* mysin(double x, int num_of_iteration) {
    static return_helper ret;
    double res = x;
    unsigned long long k = 1;
    for(int i = 1; i < num_of_iteration; i ++) {     
        k *= (2 * i + 1) * (2 * i);
        res += binpow(-1, i) * ((double)(binpow(x, 2*i + 1)) / k);
    } 
    ret.res = res;
    ret.num_of_iterations = num_of_iteration;
    return &ret;
}



int main() {
    int segmentation = 49;
    double point_segment = 0, delta;
    double eps = get_machine_epsilon();
    int num_of_iterations = 4;
    return_helper *ans = mysin(point_segment, num_of_iterations);

    for(int i = 0; i <= segmentation; i++) {
        point_segment = (double)i / segmentation;
        ans = mysin(point_segment, num_of_iterations);
        delta = sin(point_segment) - ans->res;
        printf( " | %lf || sin(x) = %.8lf || mysin(x) = %.8lf || Iter_num = %d || delta = %.13lf | \n", point_segment, sin(point_segment), ans->res, ans->num_of_iterations, delta);
    }
    printf("\nMachine epsilon is %e\n", eps);



}