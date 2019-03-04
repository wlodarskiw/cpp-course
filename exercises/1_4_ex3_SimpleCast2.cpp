// SimpleCast2 - proste rzutowanie typów

#include <iostream>
#include <conio.h>

void main()
{
	std::cout << "   TABLICA KODOW ASCII   " << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << std::endl;

	int k = 0; // licznik przejsc petli

	for (int i = 32; i < 256; i += 4)
	{
		std::cout << "| ";

		// wyswietlanie linijki petla for
		for (int j = 0; j < 4; ++j)
		{
			std::cout << static_cast<char>(i + j) << " == " << i + j << " | ";
		}

		++k; // liczenie przejsc petli

		std::cout << std::endl;
		
		// wstrzymanie wyswietlania konsoli po 27 wierszach
		if (k == 27)
		{
			_getch();
		}
	}
	// czekanie na reakcje uzytkownika na koniec programu
	_getch();
}