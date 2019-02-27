/* TextDisplay - pierwsze æwiczenie, wyœwietlanie trzech linijek tekstu	
i oczekiwanie na dowolny klawisz po ka¿dej z nich */ 

#include <iostream>
#include <conio.h>

void main()
{
	std::cout << "First line of text, push any button." << std::endl;
	_getch();

	std::cout << "Second line of text, push any button." << std::endl;
	_getch();

	std::cout << "Third and final line, push any button." << std::endl;
	_getch();
}