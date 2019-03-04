// IsPrime - sprawdzanie, czy dana liczba jest pierwsza

#include <iostream>
#include <cmath>
#include <conio.h>

bool LiczbaPierwsza(unsigned uLiczba)
{
	if (uLiczba == 2) return true;

	for (unsigned i = 2; i <= sqrt(uLiczba); ++i)
	{
		if (uLiczba % i == 0)
			return false;
	}

	return true;
}

void main()
{
	std::cout << "   LICZBA PIERWSZA   " << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	unsigned uWartosc;
	std::cout << "Podaj liczbe: ";
	std::cin >> uWartosc;

	if (LiczbaPierwsza(uWartosc))
		std::cout << "Liczba " << uWartosc << " jest pierwsza.";
	else
		std::cout << "Liczba " << uWartosc << " nie jest pierwsza.";

	_getch();
}