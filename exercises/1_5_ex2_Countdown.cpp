// Countdown - program wyœwietlaj¹cy iloœæ dni do koñca roku

#include <iostream>
#include <ctime>
#include <conio.h>

void main()
{
	std::cout << "   COUNTDOWN   " << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << std::endl;

	// struktura w któr¹ zczytamy aktualny czas
	tm AktualnyCzas = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	// zczytywanie czasu
	time_t Czas = time(NULL);
	localtime_s(&AktualnyCzas, &Czas);

	unsigned uDoKoncaRoku = 0; // zmienna przechowuj¹ca wynik
	unsigned uIleMinelo = AktualnyCzas.tm_yday; // ile dni mine³o od 1 Stycznia
	unsigned uRok = AktualnyCzas.tm_year + 1900; // obecny rok

	// warunek sprawdz¹jacy czy rok jest przestêpny czy nie
	if ((uRok% 4 == 0 && uRok % 100 != 0) || uRok % 400 == 0)
		uDoKoncaRoku = 365 - uIleMinelo; // rok przestêpny
	else
		uDoKoncaRoku = 364 - uIleMinelo;

	// wyœwietlenie wyniku
	std::cout << "Do konca rodku zostalo: ";
	std::cout << uDoKoncaRoku << std::endl;

	_getch();
}