#include <stdio.h>

double function(double x) {
    return x * x;
}

double gradient(double x) {
    double h = 0.0001;  //微小な量

    double f_x_plus_h = function(x + h);
    double f_x_minus_h = function(x - h);

    double grad = (f_x_plus_h - f_x_minus_h) / (2 * h);
    return grad;
}

int main() {
    double x = 2.0;
    double grad = gradient(x);

    printf("x = %lf の勾配は %lf です。\n", x, grad);

    return 0;
}

