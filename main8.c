#include <stdio.h>
#include <math.h>

//long double mycossq(int n, long double x);
//int enter(long double *x, int *n);
//int check(long double *x);


// int enter(long double *x, int *n) {
//     printf("Введите числа x и n:\n");
//     int d = scanf("%Lf%d", x, n);

//     if (d == 2) {
//         return 0; 
//     }

//     if (d == -1) {
//         printf("До свидания!\n");
//         return -1; 
//     }

//     printf("Введено некорректное значение, пожалуйста, попробуйте ещё раз\n");
//     return 1;
// }

// long double check(long double x) {
    
//     long double pi = 3.141592653589793;
    
    
//     while ( (x < -1 * pi) && (x > pi)) {
//         if (x < -1 * pi) x = x + pi;
//         if (x > pi) x = x - pi;
        
//     }
//     printf("было изменено исходное число на %lf", x);
//     return x;

// }

long double mycossq(int n, long double x) {
    long double s = 1;
    long double p = (-2 * x * x)/2;

    for (int i = 2; i < n; i++) {
        p *= (-4 * x * x) / ((2 * i - 1) * (2 * i));
        s += p;
    }
    
    s=s-((2*x*x)/2);
    return s;
}


int main() {
    int n;
    long double x;
    long double s1, s2;

    // if (enter(&x, &n) != 0) {
    //     return 1; 
    // }
    printf("введите числа x и n.\n");
    scanf("%Lf%d", &x, &n);
        
    printf("%f", x);
    // x = check(x);

    s1 = cos(x) * cos(x);
    s2 = mycossq(n, x);

    printf("Результат встроенной функции: %.15Lf\n", s1);
    printf("Результат расчёта через ряд Тейлора: %.15Lf\n", s2);

    return 0;
}