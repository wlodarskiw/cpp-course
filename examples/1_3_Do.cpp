// Do - pierwsza p�tla warunkowa
// Break - przerwanie p�tli

#include <iostream>
#include <conio.h>

void main()
{
	int nLiczba;

	do
	{
		std::cout << "Wprowadz liczbe wieksza od 10" << std::endl;
		std::cout << "lub zero, by zakonczyc program: ";
		std::cin >> nLiczba;
		
		if (nLiczba == 0) break;
	} while (nLiczba <= 10);

	std::cout << "Nacisnij dowolny klawisz.";
	_getch();
}