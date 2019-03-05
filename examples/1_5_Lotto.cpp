// Lotto - u¿ycie prostej tablicy liczb

#include <iostream>
#include <ctime>
#include <conio.h>

const unsigned ILOSC_LICZB = 6;
const int MAKSYMALNA_LICZBA = 49;

void main()
{
	std::cout << "   LOTTO   " << std::endl;
	std::cout << "-----------" << std::endl;
	std::cout << std::endl;

	// deklaracja i wyzerowanie tablicy liczb
	unsigned aLiczby[ILOSC_LICZB];
	for (int i = 0; i < ILOSC_LICZB; ++i)
		aLiczby[i] = 0;

	// losowanie liczb
	srand(static_cast<int>(time(NULL)));
	for (int i = 0; i < ILOSC_LICZB; )
	{
		// wylosowanie liczby
		aLiczby[i] = rand() % MAKSYMALNA_LICZBA + 1;

		// sprawdzenie, czy siê ona nie powtarza
		bool bPowtarzaSie = false;
		for (int j = 0; j < i; ++j)
		{
			if (aLiczby[j] == aLiczby[i])
			{
				bPowtarzaSie = true;
				break;
			}
		}

		// je¿eli siê nie powtarza, przechodzimy do nastêpnej liczby
		if (!bPowtarzaSie) ++i;
	}

	// wyœwietlamy wylosowane liczby
	std::cout << "Wyniki losowania:" << std::endl;
	for (int i = 0; i < ILOSC_LICZB; ++i)
		std::cout << aLiczby[i] << " ";

	// czekamy na dowolny klawisz
	_getch();
}