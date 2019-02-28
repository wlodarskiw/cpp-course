// For - pêtla krokowa

#include <iostream>
#include <conio.h>

int Suma(int nLiczba)
{
	int nSuma = 0;

	for (int i = 1; i <= nLiczba; i++)
		nSuma += i;

	return nSuma;
}

void main()
{
	std::cout << "   SUMA   " << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << std::endl;

	int nLiczba;
	std::cout << "Program oblicza sume od 1 do podanej liczby." << std::endl;
	std::cout << "Podaj ja: ";
	std::cin >> nLiczba;

	std::cout << "Suma liczb od 1 do " << nLiczba << " wynosi " << Suma(nLiczba) << ".";
	_getch();
}