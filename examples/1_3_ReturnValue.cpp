// ReturnValue - funkcje zwracaj¹ce wartoœæ

#include <iostream>
#include <conio.h>

// --- funkcje pomocnicze ---

// obwód prostok¹ta
int Obwod(int nBok1, int nBok2)
{
	return 2 * (nBok1 + nBok2);
}

// pole prostok¹ta
int Pole(int nBok1, int nBok2)
{
	return nBok1 * nBok2;
}

// --- funkcja main() ---

void main()
{
	std::cout << "   OBLICZANIE OBWODU I POLA PROSTOKATA   " << std::endl;
	std::cout << "-----------------------------------------" << std::endl;
	std::cout << std::endl;

	int nDlugosc1;
	std::cout << "Podaj dlugosc pierwszego boku: ";
	std::cin >> nDlugosc1;

	int nDlugosc2;
	std::cout << "Podaj dlugosc drugiego boku: ";
	std::cin >> nDlugosc2;

	std::cout << "Obwod prostokata: " << Obwod(nDlugosc1, nDlugosc2) << std::endl;
	std::cout << "Pole prostokata: " << Pole(nDlugosc1, nDlugosc2) << std::endl;
	_getch();
};