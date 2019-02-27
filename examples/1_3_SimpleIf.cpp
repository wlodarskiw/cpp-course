// SimpleIf - prosty przyk³ad funkcji if
// Else - blok alternatywny w instrukcji if

#include <iostream>
#include <conio.h>

void main()
{
	int nLiczba;

	std::cout << "Wprowadz liczbe wieksza od 10: ";
	std::cin >> nLiczba;

	if (nLiczba > 10)
	{
		std::cout << "Dziekuje." << std::endl;
		std::cout << "Wcisnij dowolny klawisz, by zakonczyc.";
	}
	else
	{
		std::cout << "Liczba " << nLiczba
			<< " nie jest wieksza od 10." << std::endl;
	}
	_getch();
}