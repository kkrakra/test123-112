#include <stdio.h>
#include <math.h>

long double mycossq(int n, long double x);
int enter(long double *x, int *n);
// int check(long double *x);

int main() {
    int n;
    long double x;
    long double s1, s2;

    if (enter(&x, &n) != 0) {
        return 1; // Завершение программы при некорректном вводе
    }

    s1 = cos(x) * cos(x);
    s2 = mycossq(n, x);

    printf("Результат встроенной функции: %.15Lf\n", s1);
    printf("Результат расчёта через ряд Тейлора: %.15Lf\n", s2);

    return 0;
}

int enter(long double *x, int *n) {
    printf("Введите числа x и n:\n");
    int d = scanf("%Lf%d", x, n);

    if (d == 2) {
        return 0; // Ввод корректен
    }

    if (d == -1) {
        printf("До свидания!\n");
        return -1; // Сигнал завершения программы
    }

    printf("Введено некорректное значение, пожалуйста, попробуйте ещё раз\n");
    return 1;
}

// int check
long double factorial(long double n)
{
    long double factorial = 1;

    for (int i = 2; i <= n; i++)
        factorial = factorial * i;

    return factorial;
}

long double mycossq(int n, long double x) {
    long double s = 1;
    long double p = 1;

    for (int i = 1; i < n; i++) {
        printf("%.15Lf\n", p);
        p = p * (-4 * x * x) / ((2 * i - 1) * (2 * i));
        s = s + p;
    }
    // for (int i = 1; i < n; i++)
    // {

    //     long double a1 = pow(-1, i);
    //     long double a2 = pow(2, 2*i -1);
    //     long double a3 = factorial(2*i);
    //     long double a4 = pow(x, 2*i);

    //     s = s + a1*(a2/a3)*a4;
    // }


    return s;
}