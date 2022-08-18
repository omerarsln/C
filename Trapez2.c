#include <stdio.h>
#include <math.h>

double f(double x)
{
  return 2 / pow((pow(x, 2) - 3), 0.5);
}

double h = 0.2;
int main()
{

  double sonuc = (h / 2) * (f(3) + f(5));
  printf("%f", sonuc);
  getchar();
}
