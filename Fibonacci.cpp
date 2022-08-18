#include <iostream>

using namespace std;

unsigned long fibo(int x)
{

	unsigned long a = 0, b = 1, c;

	if (x == 0 || x == 1)
		return x;
	else
	{

		for (int i = 1; i < x; i++)
		{

			c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
}

int main()
{

	int a = 0;

	while (a < 30)
	{

		cout << "Fibonacci (" << a << ") : " << fibo(a) << endl;
		a++;
	}

	getchar();
	return 0;
}
