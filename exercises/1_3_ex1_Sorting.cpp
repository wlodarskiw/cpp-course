/* Sorting - program sortuj�cy podan� liczb� ca�kowit� to jednego z czterech
przedzia��w: ujemnych, jednocyfrowych, dwucyfrowych lub pozosta�ych. */

#include <iostream>
#include <conio.h>

void main()
{
	std::cout << "   SORTOWANIE   " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;

	// wprowadzenie liczby
	int nLiczba;
	std::cout << "Podaj liczbe calkowita: ";
	std::cin >> nLiczba;
	std::cout << std::endl;

	// sprawdzenie do kt�rego przedzia�u nale�y podana liczba
	if (nLiczba < 0)
		std::cout << "Liczba jest ujemna." << std::endl;
	else if (nLiczba < 10)
		std::cout << "Liczba jest jednocyfrowa." << std::endl;
	else if (nLiczba < 100)
		std::cout << "Liczba jest dwucyfrowa." << std::endl;
	else
		std::cout << "Liczba jest z innego przedzia�u." << std::endl;

	std::cout << "Nacisnij dowolny klawisz." << std::endl;
	_getch();
}