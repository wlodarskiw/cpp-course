/* While2 - zmodyfikowana wersja z przyk³adu aby dodatkowo zlicza³a próby
odgadniêcia liczby */

#include <iostream>
#include <ctime>
#include <conio.h>

void main()
{
	std::cout << "   ZGADYWANKA   " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;

	// wylosowanie liczby
	srand((int)time(NULL));
	int nWylosowana = rand() % 100 + 1;
	std::cout << "Wylosowano liczbe z przedzialu 1-100." << std::endl;

	// pierwsza próba odgadniêcia liczby
	int nWprowadzona;
	std::cout << "Sprobuj ja odgadnac: ";
	std::cin >> nWprowadzona;

	// inicjalizacja licznika
	int i = 0;

	/* kolejne próby, a¿ do skutku - przy u¿yciu pêtli while
	dziêki temu, ¿e sprawdza ona warunek na pocz¹tku cyklu, uwzglêdniony
	zostanie tak¿e ma³o prawdopodobny, ale mo¿liwy przypadek odgadniêcia
	w³aœciwej liczby za pierwszym razem */
	while (nWprowadzona != nWylosowana)
	{
		// zliczanie prob
		++i;

		if (nWprowadzona < nWylosowana)
			std::cout << "Liczba jest zbyt mala.";
		else
			std::cout << "Za duza liczba.";

		std::cout << " Sprobuj jeszcze raz: ";
		std::cin >> nWprowadzona;
	}
	std::cout << "Ilosc prob: " << i << std::endl;
	_getch();
}