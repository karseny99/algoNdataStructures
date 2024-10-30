#include <stdio.h>
#include <stdbool.h>


/*
берем свой варик и следующий за ним
пишем две функции и используем все три метода
то есть в ответе 6 результатов
*/
struct result {
    double root;
    int steps;
    bool is_success;
};


typedef struct result result;

double f(double x) {
    return x;
}

double der(double x, func f) {
    double delta = sqrt(eps);
    return ((f(x + delta) - f(x - delta)) / (2 * delta));            // Если x = 0 , то значение ожидаемое будет ноль, но мы получим что-то дргуое, поэтому надо как-то
                                            // поменять вид функции, а именно сделать из нее симметричную (в овале в тетради) 
                                    
}


// Надо написать свою функцию второй производной

double der2(double x, func f) {
    return x;
    
}

// хз как делать
// typedef func {
//     double (func*)(double);

// }
// func f1 = sin;
// func f2 = cos;
// f1(15.0);
//            | <- tyt
result diho(func f, double a, double b, double delta) {
    result ans;
    if ( f(a) * f(b) > 0) {
        ans.is_success = false;
        return ans;
    } else {
        ans.is_success = true;
    }
    while (b - a > delta) {
        double c = (a + b) / 2;
        if (f(a) * f(b) < 0) {
            b = c;
        }  else {
            a = c;
        }
        ans.steps++;
    }
    ans.root = (a + b) / 2;
    return ans;

}














int main() {

}