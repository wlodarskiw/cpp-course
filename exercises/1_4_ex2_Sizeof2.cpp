// Sizeof - pobranie rozmiaru zmiennej lub typu

#include <iostream>
#include <conio.h>

typedef short int SINT;
typedef long int LINT;

void main()
{
	std::cout << "   ROZMIARY TYPOW PODSTAWOWYCH   " << std::endl;
	std::cout << "---------------------------------" << std::endl;
	std::cout << std::endl;

	std::cout << "Typy liczb calkowitych:" << std::endl;
	std::cout << "- int: " << sizeof(int) << std::endl;
	std::cout << "- short int: " << sizeof(SINT) << std::endl;
	std::cout << "- long int: " << sizeof(LINT) << std::endl;
	std::cout << "- char: " << sizeof(char) << std::endl;
	std::cout << std::endl;

	std::cout << "Typy liczb zmiennoprzecinkowych:" << std::endl;
	std::cout << "- float: " << sizeof(float) << std::endl;
	std::cout << "- double: " << sizeof(double) << std::endl;

	_getch();
}