// Static - zmienne statyczne

#include <iostream>
#include <string>
#include <conio.h>

void Funkcja()
{
	static int nLicznik = 0;

	++nLicznik;
	std::cout << "Funkcje wywolano po raz " << nLicznik << std::endl;
}

void main()
{
	std::cout << "   ZMIENNA STATYCZNA   " << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;

	std::string strWybor;
	do
	{
		Funkcja();

		std::cout << "Wpisz 'q', aby zakonczyc: ";
		std::cin >> strWybor;
	} while (strWybor != "q");
}