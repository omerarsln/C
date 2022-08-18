#include<iostream>
#include<cstdlib>
#include<ctime>
#include<math.h>

using namespace std;

unsigned int zarAt();

int main() {

	enum Status { WON, LOST, CONTINUE };

	srand(static_cast<unsigned int>(time(0)));

	Status gameStatus = CONTINUE;
	unsigned int Puanim = 0;
	unsigned int ZarToplami = zarAt();

	switch (ZarToplami)
	{
	case 7:
	case 11:
		gameStatus = WON;
		break;
	case 2:
	case 3:
	case 12:
		gameStatus = LOST;
		break;
	default:
		gameStatus = CONTINUE;
		Puanim = ZarToplami;
		cout << "Puaniniz: " << Puanim << endl;
		break;
	}

	while (CONTINUE == gameStatus) {

		ZarToplami = zarAt();

		if (ZarToplami == Puanim)
			gameStatus = WON;

		else if (ZarToplami == 7)
			gameStatus = LOST;
	}

	if (WON == gameStatus)
		cout << "KAZANDINIZ!" << endl;
	else
		cout << "Kaybettiniz" << endl;
		
	system("pause");
	return 0;
}

unsigned int zarAt() {

	cout << "Zar atmak icin bir tusa basiniz";
	getchar();
	unsigned int zar1 = 1 + rand() % 6;
	unsigned int zar2 = 1 + rand() % 6;

	unsigned int toplam = zar1 + zar2;

	cout << "Attiginiz Zarlar: " << zar1 << "+" << zar2 << "=" << toplam << endl;

	return toplam;
}
