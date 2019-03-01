// SimpleCast - proste rzutowanie typów

#include <iostream>
#include <conio.h>

void main()
{
	std::cout << "   TABLICA KODOW ASCII   " << std::endl;
	std::cout << "-------------------------" << std::endl;
	std::cout << std::endl;

	for (int i = 32; i < 256; i += 4)
	{
		std::cout << "| " << (char)(i) << " == " << i << " | ";
		std::cout << (char)(i + 1) << " == " << i + 1 << " | ";
		std::cout << (char)(i + 2) << " == " << i + 2 << " | ";
		std::cout << (char)(i + 3) << " == " << i + 3 << " |" << std::endl;
	}

	_getch();
}