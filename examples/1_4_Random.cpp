// Random - losowanie liczby

#include <iostream>
#include <ctime>
#include <conio.h>

int random(int nMin, int nMax) { return rand() % (nMax - nMin + 1) + nMin; }

void main()
{
	std::cout << "   KOSTKA   " << std::endl;
	std::cout << "------------" << std::endl;
	std::cout << std::endl;

	// zainicjowanie generatora liczb pseudolosowych aktualnym czasem
	srand(static_cast<unsigned int>(time(NULL)));

	// wylosowanie i pokazanie liczby
	std::cout << "Wylosowana liczba to " << random(1, 6) << std::endl;

	_getch();
}