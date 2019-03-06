// Biorhythm - pobieranie aktualnego czasu w postaci struktury
//             i u¿ycie go do obliczenia biorytmu

#include <iostream>
#include <cmath>
#include <ctime>
#include <conio.h>

// typ wyliczeniowy, okreœlaj¹cy rodzaj biorytmu
enum BIORHYTHM { BIO_PHYSICAL = 23,
				 BIO_EMOTIONAL = 28,
				 BIO_INTELECTUAL = 33 };

// pi
const double PI = 3.1415926538;

//------------------------------------------------------------------------------

// funkcja wyliczaj¹ca dany rodzaj biorytmu
double Biorytm(double fDni, BIORHYTHM Cykl)
{
	return 100 * sin((2 * PI / Cykl) * fDni);
}

// funkcja main()
void main()
{
	std::cout << "   BIORYTM   " << std::endl;
	std::cout << "-------------" << std::endl;
	std::cout << std::endl;

	/* trzy struktury, przechowuj¹ce datê urodzenia,
	   aktualny czas oraz ró¿nicê pomiêdzy nimi */
	tm DataUrodzenia = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	tm AktualnyCzas = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	tm RoznicaCzasu = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	/* pytamy u¿ytkownika o datê urodzenia */

	std::cout << "Podaj date urodzenia" << std::endl;

	// dzieñ
	std::cout << "- dzien: ";
	std::cin >> DataUrodzenia.tm_mday;

	// miesi¹c - musimy odj¹æ 1, bo u¿ytkownik poda go w systemie 1..12
	std::cout << "- miesiac: ";
	std::cin >> DataUrodzenia.tm_mon;
	DataUrodzenia.tm_mon--;

	// rok - tutaj natomiast musimy odj¹æ 1900
	std::cout << "- rok: ";
	std::cin >> DataUrodzenia.tm_year;
	DataUrodzenia.tm_year -= 1900;

	/* obliczamy liczbê prze¿ytych dni */
	// pobieramy aktualny czas w postaci struktury
	time_t Czas = time(NULL);
	//AktualnyCzas = *localtime(&Czas);
	localtime_s(&AktualnyCzas, &Czas);

	// obliczamy ró¿nicê miêdzy nim a dat¹ urodzenia
	RoznicaCzasu.tm_mday = AktualnyCzas.tm_mday - DataUrodzenia.tm_mday;
	RoznicaCzasu.tm_mon = AktualnyCzas.tm_mon - DataUrodzenia.tm_mday;
	RoznicaCzasu.tm_year = AktualnyCzas.tm_year - DataUrodzenia.tm_year;

	double fPrzezyteDni = RoznicaCzasu.tm_year * 365.25
						+ RoznicaCzasu.tm_mon * 30.4375
						+ RoznicaCzasu.tm_mday;

	/* obliczamy biorytm i wyœwietlamy go */
	std::cout << std::endl;
	std::cout << "Twoj biorytm" << std::endl;
	std::cout << "- fizyczny: " << Biorytm(fPrzezyteDni, BIO_PHYSICAL)
			  << std::endl;
	std::cout << "- emocjonalny: " << Biorytm(fPrzezyteDni, BIO_EMOTIONAL)
			  << std::endl;
	std::cout << "- intelektualny: " << Biorytm(fPrzezyteDni, BIO_INTELECTUAL)
			  << std::endl;

	// czekamy na dowolny klawisz
	_getch();
}