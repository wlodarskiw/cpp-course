// Parameters - wykorzystanie parametrów funkcji (ulepszenie Arithmetic)

#include <iostream>
#include <conio.h>

void Dodaj(int nWartosc1, int nWartosc2)
{
	int nWynik = nWartosc1 + nWartosc2;
	std::cout << nWartosc1 << " + " << nWartosc2 << " = " << nWynik;
	std::cout << std::endl;
}

void main()
{
	int nLiczba1;
	std::cout << "Podaj pierwsza liczbe: ";
	std::cin >> nLiczba1;

	int nLiczba2;
	std::cout << "Podaj druga liczbe: ";
	std::cin >> nLiczba2;

	Dodaj(nLiczba1, nLiczba2);
	_getch();
}