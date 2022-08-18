#include <iostream>
#include <time.h>

using namespace std;

int main()
{

	int yazi = 0, tura = 0, y;

	srand(static_cast<unsigned int>(time(0)));

	for (int i = 1; i <= 100; i++)
	{

		y = rand() % 2;

		if (y == 0)
			tura++;
		else
			yazi++;
	}

	cout << "Yazi: " << yazi << endl;
	cout << "Tura: " << tura << endl;
	getchar();
	return 0;
}
