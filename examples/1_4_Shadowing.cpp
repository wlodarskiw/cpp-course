// Shadowing - przes³anianie nazw

#include <iostream>
#include <conio.h>

int nX = 4;

void main()
{
	std::cout << "   PRZESLANIANIE NAZW   " << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;

	int nX = 7;
	std::cout << "Lokalna zmienna nX: " << nX << std::endl;
	std::cout << "Modulowa zmienna nX: " << ::nX << std::endl;

	_getch();
}