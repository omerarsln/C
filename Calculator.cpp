#include<iostream>

using namespace std;

int main() {

	int sayi1, sayi2;
	float sonuc;
	char islem;

	cin >> sayi1 >> islem >> sayi2;

	switch (islem)
	{
	case '+':
		sonuc = sayi1 + sayi2;
		break;
	case '-':
		sonuc = sayi1 - sayi2;
		break;
	case '*':
		sonuc = sayi1 * sayi2;
		break;
	case '/':
		sonuc = sayi1 / sayi2;
		break;

	default:
		cout << "Yanlis Giris" << endl;
		break;
	}

	cout << sonuc << endl;

	system("pause");
	return 0;
}
