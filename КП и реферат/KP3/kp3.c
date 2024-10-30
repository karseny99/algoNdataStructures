#include <stdio.h>
#include <math.h>

__attribute__ ((noinline)) double probros(double x) {
    return x;
}

double get_machine_epsilon() {
    double eps = 1;
    int i = 0;
    while (probros(1.0 + (eps / 2)) > 1.0) {
        eps /= 2;
        i++;
    }
    return eps;
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


double myabs(double x){
    if(x >= 0) {
        return x;
    }
    return -x;
}


typedef struct {
    double res;
    int num_of_iterations;
} return_helper;


return_helper mysin(double x, double cst) {
    return_helper ret;
    double res = x;
    unsigned long long k = 1;
    double sequence_member, odd = -1;
    int num_of_iterations = 1; 
    do{
        k *= (2 * num_of_iterations + 1) * (2 * num_of_iterations);
        sequence_member = odd * ((double)(binpow(x, 2*num_of_iterations + 1)) / k);
        odd *= -1;
        res += sequence_member;
        num_of_iterations++;
    } while (myabs(sequence_member) >= cst);
    ret.res = res;
    ret.num_of_iterations = num_of_iterations;
    return ret;
}

int main() {
    int segmentation;
    scanf("%d", &segmentation);
    double delta;
    double eps = get_machine_epsilon();
    double lower_edge = 0;
    double upper_edge = 1;
    double x = lower_edge;
    double cst = get_machine_epsilon() * binpow(2, 16);
    return_helper ans;
    for(int i = 0; i <= segmentation; i++) {
        x = lower_edge + i * (upper_edge - lower_edge) / segmentation;
        ans = mysin(x, cst);
        delta = sin(x) - ans.res;
        printf( " | %lf || sin(x) = %.8lf || mysin(x) = %.8lf || Iter_num = %d || delta = %e |  %d \n", x, sin(x), ans.res, ans.num_of_iterations, delta, i);
    } 
    printf("\nMachine epsilon is %e\n", eps);
}