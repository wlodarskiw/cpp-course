// ByteCalc - kalkulator bajtów

#include <iostream>
#include <conio.h>
#include "calc.h"

void main()
{
	std::cout << "   KALKULATOR BAJTOW   " << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << std::endl;

	// zapytujemy o skalê, w której bêdzie wprowadzona wartoœæ
	char chSkala;
	std::cout << "Wybierz wejsciowa skale bajtow" << std::endl;
	std::cout << "(b - bajty, k - kilobajty, m - megabajty, g - gigabajty,";
	std::cout << "t - terabajty): ";
	std::cin >> chSkala;
	if (chSkala != 'b' && chSkala != 'k' && chSkala != 'm' && chSkala != 'g'
		&& chSkala != 't') return;

	// zapytujemy o bajty
	float fBajty;
	std::cout << "Podaj bajty: ";
	std::cin >> fBajty;

	// deklarujemy obiekt kalkulatora i przekazujemy doñ bajty
	CByteCalc Kalkulator;
	Kalkulator.UstawBajty(fBajty, static_cast<BYTE>(chSkala));

	// pokazujemy wynik - czyli temperaturê we wszystkich skalach
	std::cout << std::endl;
	std::cout << "- bajty: "
			  << Kalkulator.PobierzBajty(BT_BYTES) << std::endl;
	std::cout << "- kilobajty: "
			  << Kalkulator.PobierzBajty(BT_KILOBYTES) << std::endl;
	std::cout << "- megabajty: "
			  << Kalkulator.PobierzBajty(BT_MEGABYTES) << std::endl;
	std::cout << "- gigabajty: "
			  << Kalkulator.PobierzBajty(BT_GIGABYTES) << std::endl;
	std::cout << "- terabajty: "
			  << Kalkulator.PobierzBajty(BT_TERABYTES) << std::endl;

	// czekamy na dowolny klawisz
	_getch();
}