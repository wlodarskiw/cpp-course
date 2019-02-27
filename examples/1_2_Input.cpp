// Input - u¿ycie zmiennych i strumienia wejœcia

#include <string>
#include <iostream>
#include <conio.h>

void main()
{
	std::string strName;

	std::cout << "Please state your name: ";
	std::cin >> strName;
	std::cout << "Your name is " << strName << "." << std::endl;

	_getch();
}