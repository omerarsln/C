#include <iostream>
#include <string>

using namespace std;

//def
class Atom;
int boslukSay(const string &, int);
void degerlikElektronAta(Atom *, int);
int toplamDegerlikElektronDondur(Atom *, int);
int gerekliElektronHesapla(Atom *, int);
void isimElektronAta(Atom *, int);


//impl
class Atom
{
	friend void degerlikElektronAta(Atom *, int);
	friend int toplamDegerlikElektronDondur(Atom *, int);
	friend int gerekliElektronHesapla(Atom *, int);

private:
	static int elementCesitiS;
	static int toplamDegerlikE;
	static int toplamGerekliE;
	static int toplamBagSayisi;
	static int toplamKurulabilirBagSayisi;
	static int toplamElementCesitSayisi;
	char karakter;
	int degerlikE;
	int kurulacakBagSayisi;
	int kurulanBagSayisi = 0;
	string bagKurulanAtomlar = "";
	string goruntulenecekIsim;

public:
	Atom()
	{
		elementCesitiS = elementCesitiS + 1;
	}

	static int dondurElementCesitiS()
	{
		return elementCesitiS;
	}

	static void ataToplamDegerlikE(int i)
	{
		toplamDegerlikE = i;
	}

	static int dondurToplamDegerlikE()
	{
		return toplamDegerlikE;
	}

	static void ataToplamGerekliE(int i)
	{
		toplamGerekliE = i;
	}

	static int dondurToplamGerekliE()
	{
		return toplamGerekliE;
	}

	static void ataToplamBagSayisi(int i)
	{
		toplamBagSayisi = i;
	}

	static int dondurtoplamBagSayisi()
	{
		return toplamBagSayisi;
	}


	static void toplamKurulabilirBagSayisiAta(int i)
	{
		toplamKurulabilirBagSayisi = i;
	}
	static int toplamKurulabilirBagSayisiDondur() {
		return toplamKurulabilirBagSayisi;
	}

	static void toplamElementCesitSayisiAta(int i)
	{
		toplamElementCesitSayisi = i;
	}
	static int toplamElementCesitSayisiDondur() {
		return toplamElementCesitSayisi;
	}

	void ataKarakter(char);
	char dondurKarakter();

	void ataDegerlikE(int);
	int dondurDegerlikE();

	void ataKurulacakBagSayisi(int);
	int dondurKurulacakBagSayisi();

	void bagKur(string);
	bool tumBaglarKurulduMu();

	void ataIsim(string);
	string dondurIsim();

	string dondurBagKurulanAtomlar();
};


int Atom::elementCesitiS = 0;
int Atom::toplamDegerlikE = 0;
int Atom::toplamGerekliE = 0;
int Atom::toplamBagSayisi = 0;
int Atom::toplamKurulabilirBagSayisi = 0;
int Atom::toplamElementCesitSayisi = 0;

void Atom::ataKarakter(char c)
{
	karakter = c;
}


char Atom::dondurKarakter()
{
	return karakter;
}


void Atom::ataDegerlikE(int i)
{
	degerlikE = i;
}


int Atom::dondurDegerlikE()
{
	return degerlikE;
}

void Atom::ataKurulacakBagSayisi(int i)
{
	kurulacakBagSayisi = i;
}


int Atom::dondurKurulacakBagSayisi()
{
	return kurulacakBagSayisi;
}


void Atom::bagKur(string bagKurulanAtom)
{
	kurulanBagSayisi++;
	if (kurulanBagSayisi == 1)
	{
		bagKurulanAtomlar = bagKurulanAtom;
	}
	else
	{
		bagKurulanAtomlar += "," + bagKurulanAtom;
	}
}

bool Atom::tumBaglarKurulduMu()
{
	if (kurulanBagSayisi == kurulacakBagSayisi) {
		return true;
	}
	return false;
}

void Atom::ataIsim(string isim)
{
	goruntulenecekIsim = isim;
}

string Atom::dondurIsim()
{
	return goruntulenecekIsim;
}

string Atom::dondurBagKurulanAtomlar()
{
	return bagKurulanAtomlar;
}
/////////////////Outside of class
int boslukSay(const string & s, int u)
{
	int sayac = 0;

	for (int i = 0; i < u; i++)
	{
		if (s[i] == ' ')
		{
			++sayac;
		}
	}

	return sayac;
}

void degerlikElektronAta(Atom * aPtr, int nSayisi)
{
	int toplamKurulabilirBagSayisi = 0;
	for (int i = 0; i < nSayisi; i++)
	{
		if (aPtr[i].dondurKarakter() == 'C')
		{
			aPtr[i].ataDegerlikE(4);
			aPtr[i].ataKurulacakBagSayisi(4);
			toplamKurulabilirBagSayisi += 4;
		}
		else if (aPtr[i].dondurKarakter() == 'K')
		{
			aPtr[i].ataDegerlikE(5); //?devde 3 yaz?yor ??
			aPtr[i].ataKurulacakBagSayisi(3);
			toplamKurulabilirBagSayisi += 3;
		}
		else if (aPtr[i].dondurKarakter() == 'O')
		{
			aPtr[i].ataDegerlikE(6);
			aPtr[i].ataKurulacakBagSayisi(2);
			toplamKurulabilirBagSayisi += 2;
		}
		else if (aPtr[i].dondurKarakter() == 'H')
		{
			aPtr[i].ataDegerlikE(1);
			aPtr[i].ataKurulacakBagSayisi(1);
			toplamKurulabilirBagSayisi++;
		}
		else
		{
			cout << "HATALI KARAKTERDEN DOLAYI DEGERLIK ELEKTRONLAR ATANAMADI!" << endl;
			system("pause");
			exit(1);
		}
	}
	Atom::toplamKurulabilirBagSayisiAta(toplamKurulabilirBagSayisi);
}

int toplamDegerlikElektronDondur(Atom * aPtr, int nSayisi)
{
	int toplam = 0;

	for (int i = 0; i < nSayisi; i++)
	{
		toplam = toplam + aPtr[i].dondurDegerlikE();
	}

	return toplam;
}

int gerekliElektronHesapla(Atom * aPtr, int nSayisi)
{
	int gerekE = 0;

	for (int i = 0; i < nSayisi; i++)
	{
		if (aPtr[i].dondurKarakter() == 'H')
			gerekE = gerekE + 2;

		else if (aPtr[i].dondurKarakter() == 'O')
			gerekE = gerekE + 8;

		else if (aPtr[i].dondurKarakter() == 'K')
			gerekE = gerekE + 8;

		else if (aPtr[i].dondurKarakter() == 'C')
			gerekE = gerekE + 8;

		else
		{
			cout << "HATALI KARAKTERDEN DOLAYI TOPLAM DEGERLIK ELEKTRON SAYISI HESAPLANAMADI!" << endl;
			system("pause");
			exit(1);
		}
	}

	return gerekE;
}

void isimElektronAta(Atom * aPtr, int nSayisi)
{
	int kSAyisi = 0;
	int oSayisi = 0;
	int hSayisi = 0;
	int cSayisi = 0;
	int farkliElementSayisi = 0;

	for (int i = 0; i < nSayisi; i++)
	{
		char atomSembol = aPtr[i].dondurKarakter();
		if (atomSembol == 'H')
		{
			if (hSayisi == 0)
			{
				farkliElementSayisi++;
			}
			hSayisi++;
			string isim = string(1, atomSembol) + to_string(hSayisi);
			aPtr[i].ataIsim(isim);
		}
		else if (atomSembol == 'O')
		{
			if (oSayisi == 0)
			{
				farkliElementSayisi++;
			}
			oSayisi++;
			string isim = string(1, atomSembol) + to_string(oSayisi);
			aPtr[i].ataIsim(isim);
		}
		else if (atomSembol == 'K')
		{
			if (kSAyisi == 0)
			{
				farkliElementSayisi++;
			}
			kSAyisi++;
			string isim = string(1, atomSembol) + to_string(kSAyisi);
			aPtr[i].ataIsim(isim);
		}
		else if (atomSembol == 'C')
		{
			if (cSayisi == 0)
			{
				farkliElementSayisi++;
			}
			cSayisi++;
			string isim = string(1, atomSembol) + to_string(cSayisi);
			aPtr[i].ataIsim(isim);
		}
		else
		{
			cout << "HATALI KARAKTERDEN DOLAYI TOPLAM DEGERLIK ELEKTRON SAYISI HESAPLANAMADI!" << endl;
			system("pause");
			exit(1);
		}
	}
	Atom::toplamElementCesitSayisiAta(farkliElementSayisi);
}

int main()			// 4H 1O 1C		2K 1O		2K 2O		1K 1O (hatal?)
{
	string molekul;


	cout << "Molekulu giriniz: ";     getline(cin, molekul);
	cout << "Girilen molekul = " << molekul << endl << endl;							// Kontrol ama?l?, silinecek!..


	int uzunluk = molekul.length();
	cout << "Uzunluk = " << uzunluk << endl << endl;									// Kontrol ama?l?, silinecek!..


	int boslukSayisi = boslukSay(molekul, uzunluk);
	cout << "Bosluk sayisi = " << boslukSayisi << endl << endl;							// Kontrol ama?l?, silinecek!..


	int d = (uzunluk - boslukSayisi) / 2;
	cout << "Sayi ve karakter ikilisinin sayisi = " << d << endl << endl;				// Kontrol ama?l?, silinecek!..


	int * sayiPtr = new int[d];


	int h = 0;
	for (int i = 0; i < uzunluk; i = i + 3)
	{
		sayiPtr[h] = (int)molekul.at(i) - 48;	// Say?lar, ASCII tablosunda 48'den ba?lar.
		h++;
	}


	cout << "Molekuldeki sayilar = ";													// Kontrol ama?l?, silinecek!..
	for (int i = 0; i < d; i++)
	{
		cout << sayiPtr[i] << "  ";
	}
	cout << endl << endl;


	int toplamAtom = 0;
	for (int i = 0; i < d; i++)
	{
		toplamAtom = toplamAtom + sayiPtr[i];
	}


	cout << "Toplam atom sayisi = " << toplamAtom << endl << endl;						// Kontrol ama?l?, silinecek!..


	Atom * atomPtr = new Atom[toplamAtom];


	int k = 0;
	for (int i = 1; i < uzunluk; i = i + 3)
	{
		for (int y = 0; y < ((int)molekul.at(i - 1) - 48); y++)
		{
			char a = molekul.at(i);

			if (a == 'C' || a == 'c')
			{
				atomPtr[k].ataKarakter('C');
				++k;
			}

			else if (a == 'K' || a == 'k')
			{
				atomPtr[k].ataKarakter('K');
				++k;
			}

			else if (a == 'O' || a == 'o')
			{
				atomPtr[k].ataKarakter('O');
				++k;
			}

			else if (a == 'H' || a == 'h')
			{
				atomPtr[k].ataKarakter('H');
				++k;
			}

			else
			{
				cout << "HATALI KARAKTERDEN DOLAYI KARAKTERLER ATANAMADI!" << endl << endl;
				system("pause");
				exit(1);
			}
		}
	}


	cout << "k = " << k << endl << endl;												// Kontrol ama?l?, silinecek!..


	int nesneSayisi = Atom::dondurElementCesitiS();
	cout << "Olusturulan nesne sayisi = " << nesneSayisi << endl << endl;				// Kontrol ama?l?, silinecek!..


	cout << "Olusturulan nesnelerin karakterleri = ";									// Kontrol ama?l?, silinecek!..
	for (int i = 0; i < nesneSayisi; i++)
	{
		cout << atomPtr[i].dondurKarakter() << "  ";
	}
	cout << endl << endl;


	degerlikElektronAta(atomPtr, nesneSayisi);


	for (int i = 0; i < nesneSayisi; i++)												// Kontrol ama?l?, silinecek!..
	{
		cout << i + 1 << ". nesne olan " << atomPtr[i].dondurKarakter() << "'nin degerlik elektron sayisi = " << atomPtr[i].dondurDegerlikE() << endl;
	}
	cout << endl;


	int toplamDegerlikE = toplamDegerlikElektronDondur(atomPtr, nesneSayisi);
	Atom::ataToplamDegerlikE(toplamDegerlikE);
	cout << "Toplam degerlik elektron sayisi = " << Atom::dondurToplamDegerlikE() << endl << endl;		// Kontrol ama?l?, silinecek!..


	int toplamGerekliE = gerekliElektronHesapla(atomPtr, nesneSayisi);
	Atom::ataToplamGerekliE(toplamGerekliE);
	cout << "Toplam gerekli elektron sayisi = " << Atom::dondurToplamGerekliE() << endl << endl;		// Kontrol ama?l?, silinecek!..


	int toplamBagSayisi = (toplamGerekliE - toplamDegerlikE) / 2;
	Atom::ataToplamBagSayisi(toplamBagSayisi);
	cout << "Toplam bag sayisi = " << Atom::dondurtoplamBagSayisi() << endl << endl;							// Kontrol ama?l?, silinecek!..

	//toplam bag sayisi kuralacak kadar element var m? ? Yok ise, unstable durumu
	int kurulabilirBagSayisi = Atom::toplamKurulabilirBagSayisiDondur();
	if (kurulabilirBagSayisi % 2 != 0 || (kurulabilirBagSayisi / 2) != toplamBagSayisi)
	{
		cout << "UNSTABLE" << endl;
		system("pause");
		return 0;
	}

	//H1, H2 gibi g?r?nt?lenmesi i?in isim ata ;)
	isimElektronAta(atomPtr, nesneSayisi);
	for (int i = 0; i < nesneSayisi; i++)												// Kontrol ama?l?, silinecek!..
	{
		cout << i + 1 << ". nesne olan " << atomPtr[i].dondurKarakter() << "'nin ismi = " << atomPtr[i].dondurIsim() << endl;
	}
	cout << endl;

	//molek?l olu?turmak i?in en az 2 farkli ?e?it element olmas? gerekiyor
	int elementCesitSayisi = Atom::toplamElementCesitSayisiDondur();
	if (elementCesitSayisi < 2)
	{
		cout << "En az 2 farkli element girisi yapilmali." << endl;
		system("pause");
		return 0;
	}

	//en fazla ba? yapacak atomu bul ve merkeze yerle?tir
	int enFazlaBaglantiliAtomSirasi = 0;
	int enfazlaBaglantiSayisi = 0;
	for (int i = 0; i < nesneSayisi; i++)
	{
		if (atomPtr[i].dondurKurulacakBagSayisi() > enfazlaBaglantiSayisi)
		{
			enfazlaBaglantiSayisi = atomPtr[i].dondurKurulacakBagSayisi();
			enFazlaBaglantiliAtomSirasi = i;
		}
	}
	cout << "En fazla baglanti kuracak = " << atomPtr[enFazlaBaglantiliAtomSirasi].dondurIsim() << "(" << atomPtr[enFazlaBaglantiliAtomSirasi].dondurKurulacakBagSayisi() << ")" << endl << endl;
	//H hari? di?er t?m atomlardan merkezdeki atoma birer ba? kur (en fazla merkezdeki atomun ba? say?s? kadar)
	int kurulanToplamBagSayisi = 0;
	for (int i = 0; i < nesneSayisi; i++)												// Kontrol ama?l?, silinecek!..
	{
		if (i != enFazlaBaglantiliAtomSirasi && atomPtr[i].dondurKarakter() != 'H')
		{
			if (atomPtr[enFazlaBaglantiliAtomSirasi].tumBaglarKurulduMu() == false)
			{
				atomPtr[enFazlaBaglantiliAtomSirasi].bagKur(atomPtr[i].dondurIsim());
				atomPtr[i].bagKur(atomPtr[enFazlaBaglantiliAtomSirasi].dondurIsim());
				kurulanToplamBagSayisi++;
			}
			else
			{
				break;
			}
		}
	}
	//	elde kalan atom var ise bunlar? da merkezdeki atoma ba?l? di?er atomlara ba?la
	int atomIndex = 0;
	bool ilkKezBagKuruluyor = true;
	while (kurulanToplamBagSayisi != toplamBagSayisi)
	{
		//bu elementin ba?lar? tamamlanm??sa di?erine ge?
		if (atomPtr[atomIndex].tumBaglarKurulduMu() == false)
		{
			string mevcutAtomIsmi = atomPtr[atomIndex].dondurIsim();
			//bu element hari? t?m atomlar? tekrar d?n, 
			//bag sayisi tamamlanmam?? ve daha ?nce ba? kurulmam?? olanlar ile ilk olarak tekli ba? kur
			//H'ler kendi aras?nda ba? kurmas?n!
			//ilk turda tekli ba?lar tamamland?ktan sonra, ikinci turda kurulacak ba? kalm??sa ikili-??l? ba? kurulmas?na izin ver
			for (int x = 0; x < nesneSayisi; x++)
			{
				if (x != atomIndex)
				{
					//?nce H'lerin t?m ba?lar? kurulmal?
					bool bagKurulmayanHVar = false;
					for (int z = 0; z < nesneSayisi; z++)
					{
						if (atomPtr[atomIndex].dondurKarakter() != 'H'
							&& atomPtr[z].dondurKarakter() == 'H'
							&& atomPtr[z].tumBaglarKurulduMu() == false)
						{
							bagKurulmayanHVar = true;
							break;
						}
					}

					string bagKurulacakAtomunBagliOlduguAtomlar = atomPtr[x].dondurBagKurulanAtomlar();
					if (atomPtr[x].dondurKarakter() != 'H' &&
						atomPtr[x].tumBaglarKurulduMu() == false &&
						bagKurulmayanHVar == false &&
						((bagKurulacakAtomunBagliOlduguAtomlar.find(mevcutAtomIsmi) == string::npos && ilkKezBagKuruluyor)
							|| (bagKurulacakAtomunBagliOlduguAtomlar.find(mevcutAtomIsmi) != string::npos && !ilkKezBagKuruluyor)))
						//ilk d?ng?de herkes ilk ?nce bir ba? kuruluyor, birinci d?ng?den sonra a??kta ba? kal?rsa,
						//birbirlerine tekrar ba?lanmas?na izin veriyoruz (2li 3l? ba? i?in)
					{
						atomPtr[atomIndex].bagKur(atomPtr[x].dondurIsim());
						atomPtr[x].bagKur(atomPtr[atomIndex].dondurIsim());
						kurulanToplamBagSayisi++;

					}

					if (atomPtr[atomIndex].tumBaglarKurulduMu() == true)
					{
						break;
					}
				}
			}
		}

		if (atomIndex == nesneSayisi - 1)
		{
			//ilk tur tamamland?, toplam ba? say?s? tamamlanmad?ysa ba?tan tekrar ba?la
			atomIndex = 0;
			ilkKezBagKuruluyor = false;
		}
		else
		{
			atomIndex++;
		}
	}

	//happy print :):)
	for (int i = 0; i < nesneSayisi; i++)
	{
		cout << atomPtr[i].dondurIsim() << "--> " << atomPtr[i].dondurBagKurulanAtomlar() << endl;
	}

	system("pause");
	return 0;
}
