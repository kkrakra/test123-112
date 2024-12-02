#include <math.h>

int main() {


    long double x = 2;

    long double f = 1;
    long double a1 = 2;

    int b1 = -1;

    long double s = 1;

    for (int n=2; n<=20; n+=2){
                
        printf("%i\n", n);
        f = f*(n-1)*(n);

        a1 = a1*x*x;

        printf("f %Lf\n", f);
        printf("a1 %Lf\n", a1);
        printf("b1 %i\n", b1);

        s = s+b1*a1/f;


        a1 = a1*4;
        b1 = b1*(-1);

    

    }

    printf("Ответ: %Lf\n", s);
    long double s2 = cos(x) * cos(x);
    printf("Результат встроенной функции: %Lf\n", s2);
}