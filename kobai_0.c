#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void numerical_gradient(double (*f)(double[], int), double x[], double grad[], int size, double h) {
    int i, j;
    double tmp_val, fxh1, fxh2;
    double *tmp_x = (double *)malloc(sizeof(double) * size);

    for (i = 0; i < size; i++) {
        tmp_val = x[i];

        x[i] = tmp_val + h;
        fxh1 = f(x, size);

        x[i] = tmp_val - h;
        fxh2 = f(x, size);

        grad[i] = (fxh1 - fxh2) / (2 * h);

        x[i] = tmp_val;
    }

    free(tmp_x);
}

double target_function(double x[], int size) {
    // ここに目的の関数の計算式を実装する
    double result = pow(x[0], 2) + pow(x[1], 2);
    // 引数xは各変数の値を格納した配列であり、sizeは配列の要素数
    // 返り値は関数の値を返す
    return result;
}

int main(){
    double x[2] = {3.0, 4.0}; // 接線を求める点のx座標
    double grad[2]; // 勾配を格納する配列
    int size = sizeof(x) / sizeof(x[0]);
    double h = 1e-4; // 0.0001

    numerical_gradient(target_function, x, grad, size, h);

    printf("Gradient: %f\n, %f\n", grad[0], grad[1]);

    return 0;
}
