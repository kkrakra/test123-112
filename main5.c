#include <stdio.h>
#include <math.h>

long double factorial(long double n)
{
    long double factorial = 1;

    for (int i = 2; i <= n; i++)
        factorial = factorial * i;

    return factorial;
}

long double moi_cosinus_v_kvadrate(int o, long double x)
{
    long double s = 1;
    long double k;

    for (int i = 1; i < o; i++)
    {

        long double a1 = pow(-1, i);
        long double a2 = pow(2, 2*i -1);
        long double a3 = factorial(2*i);
        long double a4 = pow(x, 2*i);

        s = s + a1*(a2/a3)*a4;
    }

    return s;
}


int main()
{
    int o;
    long double x;
    printf("введите числа x и n.\n");
    scanf("%Lf%d", &x, &o);

    if ((finitef(x) == 0))
        puts("x - бесконечность");
    else
        puts("x");

    long double s1, s2;
    s1 = cos(x) * cos(x);
    s2 = moi_cosinus_v_kvadrate(o, x);
    printf("Через встроенную функцию (для сравнения точности): %Lf\n", s1);
    printf("Через ряд Тейлора: %Lf\n", s2);
    printf("Точность (разница между вычисленным и эталонным значениями): %Lf\n", s2-s1);
    // printf("Точность (разница между вычисленным и эталонным значениями в процентах): %Lf\n", (s2-s1)*100/s2);

}

