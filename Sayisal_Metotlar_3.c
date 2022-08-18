#include <stdio.h>

double f(double x)
{
    if (x == 1)
        return -4;
    else if (x == 2)
        return 5;
    else if (x == 3)
        return 26;
    else if (x == 4)
        return 65;
    else
        return -1;
}

double df1(double x)
{
    double h = 1;
    return (1 / (2 * h)) * (-3 * f(x) + 4 * f(x + h) - f(x + 2 * h));
}
double df2(int x)
{
    double h = 1;
    return (1 / (2 * h)) * (-f(x - h) + f(x + h));
}
double df3(int x)
{
    double h = 1;
    return (1 / (2 * h)) * (f(x - 2 * h) - 4 * f(x - h) + 3 * f(x));
}

double func(double x)
{
    return (x * x * x - 2 * x * x + 5);
}

double simpson(double a, double b)
{

    double h = (b - a) / 3;
    return (3 * h / 8) * (func(a) + 3 * func(a + h) + 3 * func(a + 2 * h) + func(b));
}

int main()
{

    // 1.Soru
    printf("|  x  |   f(x)   |   f'(x)  |\n");
    printf("-----------------------------\n");
    printf("|  %d  |   %4.0f   |  %7.3f |\n", 1, f(1), df1(1));
    printf("|  %d  |   %4.0f   |  %7.3f |\n", 2, f(2), df2(2));
    printf("|  %d  |   %4.0f   |  %7.3f |\n", 3, f(3), df2(3));
    printf("|  %d  |   %4.0f   |  %7.3f |\n\n", 4, f(4), df3(4));

    // 2.Soru
    printf("Simpson 3/8 Integral : %f", simpson(0, 3));
    getchar();
    return 0;
}
