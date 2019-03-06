// Biorhythm - pobieranie aktualnego czasu w postaci struktury
//             i u�ycie go do obliczenia biorytmu

#include <iostream>
#include <cmath>
#include <ctime>
#include <conio.h>

// typ wyliczeniowy, okre�laj�cy rodzaj biorytmu
enum BIORHYTHM { BIO_PHYSICAL = 23,
				 BIO_EMOTIONAL = 28,
				 BIO_INTELECTUAL = 33 };

// pi
const double PI = 3.1415926538;

//------------------------------------------------------------------------------

// funkcja wyliczaj�ca dany rodzaj biorytmu
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

	/* trzy struktury, przechowuj�ce dat� urodzenia,
	   aktualny czas oraz r�nic� pomi�dzy nimi */
	tm DataUrodzenia = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	tm AktualnyCzas = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	tm RoznicaCzasu = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	/* pytamy u�ytkownika o dat� urodzenia */

	std::cout << "Podaj date urodzenia" << std::endl;

	// dzie�
	std::cout << "- dzien: ";
	std::cin >> DataUrodzenia.tm_mday;

	// miesi�c - musimy odj�� 1, bo u�ytkownik poda go w systemie 1..12
	std::cout << "- miesiac: ";
	std::cin >> DataUrodzenia.tm_mon;
	DataUrodzenia.tm_mon--;

	// rok - tutaj natomiast musimy odj�� 1900
	std::cout << "- rok: ";
	std::cin >> DataUrodzenia.tm_year;
	DataUrodzenia.tm_year -= 1900;

	/* obliczamy liczb� prze�ytych dni */
	// pobieramy aktualny czas w postaci struktury
	time_t Czas = time(NULL);
	//AktualnyCzas = *localtime(&Czas);
	localtime_s(&AktualnyCzas, &Czas);

	// obliczamy r�nic� mi�dzy nim a dat� urodzenia
	RoznicaCzasu.tm_mday = AktualnyCzas.tm_mday - DataUrodzenia.tm_mday;
	RoznicaCzasu.tm_mon = AktualnyCzas.tm_mon - DataUrodzenia.tm_mday;
	RoznicaCzasu.tm_year = AktualnyCzas.tm_year - DataUrodzenia.tm_year;

	double fPrzezyteDni = RoznicaCzasu.tm_year * 365.25
						+ RoznicaCzasu.tm_mon * 30.4375
						+ RoznicaCzasu.tm_mday;

	/* obliczamy biorytm i wy�wietlamy go */
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