// Square - wyœwietlanie liczb od 1 do 100 i ich kwadratów

#include <iostream>
#include <conio.h>

void main()
{
	for (int i = 1; i <= 100; ++i)
	{
		std::cout << i << " " << i * i << std::endl;
	}

	std::cout << "Nacisnij dowolny klawisz." << std::endl;
	_getch();
}