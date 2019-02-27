// Multiply - iloczyn trzech liczb

#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	int nLiczba1;
	cout << "Podaj pierwsza liczbe: ";
	cin >> nLiczba1;

	int nLiczba2;
	cout << "Podaj druga liczbe: ";
	cin >> nLiczba2;

	int nLiczba3;
	cout << "Podaj trzecia liczbe: ";
	cin >> nLiczba3;

	int nWynik = nLiczba1 * nLiczba2 * nLiczba3;
	cout << nLiczba1 << " * " << nLiczba2 << " * " << nLiczba3 << " = " << nWynik;

	_getch();
}