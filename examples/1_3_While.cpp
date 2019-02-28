// While - druga p�tla warunkowa

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

	// pierwsza pr�ba odgadni�cia liczby
	int nWprowadzona;
	std::cout << "Sprobuj ja odgadnac: ";
	std::cin >> nWprowadzona;

	/* kolejne pr�by, a� do skutku - przy u�yciu p�tli while
	dzi�ki temu, �e sprawdza ona warunek na pocz�tku cyklu, uwzgl�dniony
	zostanie tak�e ma�o prawdopodobny, ale mo�liwy przypadek odgadni�cia
	w�a�ciwej liczby za pierwszym razem */
	while (nWprowadzona != nWylosowana)
	{
		if (nWprowadzona < nWylosowana)
			std::cout << "Liczba jest zbyt mala.";
		else
			std::cout << "Za duza liczba.";

		std::cout << " Sprobuj jeszcze raz: ";
		std::cin >> nWprowadzona;
	}
	std::cout << "Celny strzal. Brawo!" << std::endl;
	_getch();
}