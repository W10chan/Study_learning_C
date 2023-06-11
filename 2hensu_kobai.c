#include <stdio.h>

double function(double x, double y) {
    return x * x + y * y;
}

void gradient(double x, double y, double* grad_x, double* grad_y) {
    double h = 0.0001;  //微小な量

    double f_x_plus_h = function(x + h, y);
    double f_x_minus_h = function(x - h, y);
    double f_y_plus_h = function(x, y + h);
    double f_y_minus_h = function(x, y - h);

    *grad_x = (f_x_plus_h - f_x_minus_h) / (2 * h);
    *grad_y = (f_y_plus_h - f_y_minus_h) / (2 * h);
}

int main() {
    double x = 3.0;
    double y = 4.0;
    double grad_x, grad_y;

    gradient(x, y, &grad_x, &grad_y);

    printf("x = %lf, y = %lf の勾配ベクトルは (%lf, %lf) です。\n", x, y, grad_x, grad_y);

    return 0;
}

