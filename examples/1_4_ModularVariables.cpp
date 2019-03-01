// ModularVariables - zmienne modu³owe

#include <iostream>
#include <conio.h>

int nX = 10;

void Funkcja()
{
	std::cout << "Zmienna nX wewnatrz innej funkcji: " << nX << std::endl;
}

void main()
{
	std::cout << "   ZMIENNA MODULOWA   " << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Zmienna nX wewnatrz funkcji main(): " << nX << std::endl;
	Funkcja();

	_getch();
}