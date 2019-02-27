// Arithmetic - proste dzia³ania matematyczne

#include <iostream>
#include <conio.h>

void main()
{
	int nLiczba1;
	std::cout << "Podaj pierwsza liczbe: ";
	std::cin >> nLiczba1;

	int nLiczba2;
	std::cout << "Podaj druga liczbe: ";
	std::cin >> nLiczba2;

	int nWynik = nLiczba1 + nLiczba2;
	std::cout << nLiczba1 << " + " << nLiczba2 << " = " << nWynik;
	_getch();
}