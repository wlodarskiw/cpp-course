// Countdown - program wy�wietlaj�cy ilo�� dni do ko�ca roku

#include <iostream>
#include <ctime>
#include <conio.h>

void main()
{
	std::cout << "   COUNTDOWN   " << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << std::endl;

	// struktura w kt�r� zczytamy aktualny czas
	tm AktualnyCzas = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// zczytywanie czasu
	time_t Czas = time(NULL);
	localtime_s(&AktualnyCzas, &Czas);

	unsigned uDoKoncaRoku = 0; // zmienna przechowuj�ca wynik
	unsigned uIleMinelo = AktualnyCzas.tm_yday; // ile dni mine�o od 1 Stycznia
	unsigned uRok = AktualnyCzas.tm_year + 1900; // obecny rok

	// warunek sprawdz�jacy czy rok jest przest�pny czy nie
	if ((uRok% 4 == 0 && uRok % 100 != 0) || uRok % 400 == 0)
		uDoKoncaRoku = 365 - uIleMinelo; // rok przest�pny
	else
		uDoKoncaRoku = 364 - uIleMinelo;

	// wy�wietlenie wyniku
	std::cout << "Do konca rodku zostalo: ";
	std::cout << uDoKoncaRoku << std::endl;

	_getch();
}