/*
Variant 15 & 16:
0.4 + atan(sqrt(x)) - x = 0  [1, 2] x = 1.2388
3sin(sqrt(x)) + 0.35x - 3.8 = 0  [2, 3] x = 2.2985
*/


#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>

double func(double x) {           // F(x) = 0
    return 0.4 + atan(sqrt(x)) - x;
}

double f(double x) {              // x = f(x) 
    return 0.4 + atan(sqrt(x));
}

double func2(double x) {           // F(x) = 0
    return 3 * sin(sqrt(x)) + 0.35 * x - 3.8;
}

double f2(double x) {              // x = f(x) 
    return (3.8 - 3 * sin(sqrt(x))) / 0.35;
}


double der(double (*f)(double), double x) {      // Производная
    double delta = pow(2, -36);
    return (f(x + delta) - f(x - delta)) / (2 * delta);
}

double der2(double (*f)(double), double x) {                // Вторая производная через предел с википедии
    double dx = pow(2, -18);
    return (func(x + dx) - 2 * func(x) + func(x - dx)) / (dx * dx);
}

typedef struct {
    double root;
    int i;
    bool is_success;
} return_helper;

return_helper dichotomy(double (*f)(double), double a, double b, double delta) {
    return_helper res;
    double root, c;
    int i = 0;
    if (f(a) * f(b) > 0) {
        res.is_success = false;
        return res;
    } else {
        res.is_success = true;
    }
    while (b - a > delta) {
        c = (a + b) / 2;
        if (f(a) * f(c) <= 0) {
            b = c;
        } else {
            a = c;
        }
        i++;
    }
    res.i = i;
    root = (a + b) / 2;
    res.root = root;
    return res;
}

return_helper iter(double (*f)(double), double a, double b, double delta) {
    return_helper res;
    double x0 = (a + b) / 2, x = f(x0);
    int i = 0;
    while(fabs(x - x0) > delta) {
        if (fabs(der(f, x)) >= 1) {
            res.is_success = false;
            res.i = i;
            res.root = x;
            return res;
        }
        x0 = x;
        x = f(x0);
        i++;
    }
    res.i = i;
    res.root = x;
    res.is_success = true;
    return res;
}

return_helper newton(double (*f)(double), double a, double b, double delta) {
    return_helper res;
    double x0, x = (a + b) / 2;
    int i = 0;
    do {
        x0 = x;
        if(fabs(f(x0) * der2(f, x0)) >= der(f, x0) * der(f, x0)) {
            res.is_success = false;
            res.i = i;
            res.root = x0;
            return res;
        }
        x = x0 - (f(x0) / der(f, x0));
        i++;
    } while (fabs(x - x0) > delta);
    res.i = i;
    res.root = x;
    res.is_success = true;
    return res;
}

int main() {

    double a = 1, b = 2;
    double delta= 65536 * __DBL_EPSILON__;
    double root = 1.2388; 
    printf("\n0.4 + atan(sqrt(x)) - x = 0    [1, 2]    x = 1.2388\n");
    return_helper d1 = dichotomy(func, a, b, delta);
    printf("Dichotomy: root = %f iter_num = %d root_difference = %e is_success = %d\n", d1.root, d1.i, fabs(d1.root - root), d1.is_success);

    return_helper i1 = iter(f, a, b, delta);
    printf("Iterations: root = %f iter_num = %d root_difference = %e is_success = %d\n", i1.root, i1.i, fabs(i1.root - root), i1.is_success);

    return_helper n1 = newton(func, a, b, delta);
    printf("Newton: root = %f iter_num = %d root_difference = %e is_success = %d\n", n1.root, n1.i, fabs(n1.root - root), n1.is_success);

    double a2 = 2, b2 = 3;
    root = 2.2985;
    printf("\n3sin(sqrt(x)) + 0.35x - 3.8 = 0    [2, 3]    x = 2.2985\n");
    
    return_helper d2 = dichotomy(func2, a2, b2, delta);
    printf("Dichotomy: root = %f iter_num = %d root_difference = %e is_success = %d\n", d2.root, d2.i, fabs(d2.root - root), d2.is_success);

    return_helper i2 = iter(f2, a2, b2, delta);
    printf("Iterations: root = %f iter_num = %d root_difference = %e is_success = %d\n", i2.root, i2.i, fabs(i2.root - root), i2.is_success);

    return_helper n2 = newton(func2, a2, b2, delta);
    printf("Newton: root = %f iter_num = %d root_difference = %e is_success = %d\n", n2.root, n2.i, fabs(n2.root - root), n2.is_success);

}









































































