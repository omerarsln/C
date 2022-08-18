#include <stdio.h>
#include <math.h>

float f(float x)
{
    return (x * x * x - 7 * x * x + 14 * x - 6);
}

float df(float x)
{
    return (3 * x * x - 14 * x + 14);
}

int main()
{

    printf("YARILAMA METODU\n");
    float a = 0, b = 1, p, fp;

    for (int i = 1; i < 20; i++)
    {
        p = (a + b) / 2;
        fp = f(p);
        printf("%d. Iterasyon => a:%f b:%f p:%f f(p): %f \n", i, a, b, p, fp);

        if (fp > 0)
        {
            b = p;
        }
        else
        {
            a = p;
        }

        if (abs(a - b) < 0.001)
        {
            break;
        }
    }

    printf("\n\nNEWTON - RHAPSON METODU\n");
    a = 0, b = 1, p = 0.5;
    float h;

    for (int i = 1; i < 20; i++)
    {
        h = p - f(p) / df(p);
        printf("%d. Iterasyon => p:%f f(p): %f \n", i, p, f(p));

        if (abs(h - p) < 0.001)
        {
            break;
        }
        else
        {
            p = h;
        }
    }

    getchar();
    return 0;
}
