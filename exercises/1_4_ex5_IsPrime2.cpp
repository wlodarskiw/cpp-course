// IsPrime2 - sprawdzanie, czy dana liczba jest pierwsza

#include <iostream>
#include <cmath>
#include <conio.h>

using namespace std;

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
	cout << "   LICZBA PIERWSZA   " << std::endl;
	cout << "---------------------" << std::endl;
	cout << std::endl;

	unsigned uWartosc;
	cout << "Podaj liczbe: ";
	cin >> uWartosc;

	cout << "Liczba " << uWartosc;
	cout << (LiczbaPierwsza(uWartosc) ?
		" jest pierwsza." : " nie jest pierwsza.");

	_getch();
}