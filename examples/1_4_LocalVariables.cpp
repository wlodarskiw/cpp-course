// LocalVariables - zmienne lokalne

#include <iostream>
#include <conio.h>

void Funkcja1()
{
	int nX = 7;
	std::cout << "Zmienna lokalna nX funkcji Funkcja1(): " << nX << std::endl;
}

void Funkcja2()
{
	int nX = 5;
	std::cout << "Zmienna lokalna nX funkcji Funkcja2(): " << nX << std::endl;
}

void main()
{
	std::cout << "   ZMIENNE LOKALNE   " << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	int nX = 3;

	Funkcja1();
	Funkcja2();
	std::cout << "Zmienna lokalna nX funkcji main(): " << nX << std::endl;

	_getch();
}