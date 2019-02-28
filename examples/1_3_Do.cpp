// Do - pierwsza pêtla warunkowa

#include <iostream>
#include <conio.h>

void main()
{
	int nLiczba;

	do
	{
		std::cout << "Wprowadz liczbe wieksza od 10: ";
		std::cin >> nLiczba;
	} while (nLiczba <= 10);

	std::cout << "Dziekuje za wspolprace :)";
	_getch();
}