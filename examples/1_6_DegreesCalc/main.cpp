// DegreesCalc - kalkulator temperatur

#include <iostream>
#include <conio.h>
#include "calc.h"

void main()
{
	std::cout << "   KALKULATOR TEMPERATUR   " << std::endl;
	std::cout << "---------------------------" << std::endl;
	std::cout << std::endl;

	// zapytujemy o skalê, w której bêdzie wprowadzona wartoœæ
	char chSkala;
	std::cout << "Wybierz wejsciowa skale temperatur" << std::endl;
	std::cout << "(c - Celsjusza, f - Fahrenheita, k - Kelvina): ";
	std::cin >> chSkala;
	if (chSkala != 'c' && chSkala != 'f' && chSkala != 'k') return;

	// zapytujemy o rzeczon¹ temperaturê
	float fTemperatura;
	std::cout << "Podaj temperature: ";
	std::cin >> fTemperatura;

	// deklarujemy obiekt kalkulatora i przekazujemy doñ temperaturê
	CDegreesCalc Kalkulator;
	Kalkulator.UstawTemperature(fTemperatura, static_cast<SCALE>(chSkala));

	// pokazujemy wynik - czyli temperaturê we wszystkich skalach
	std::cout << std::endl;
	std::cout << "- stopnie Celsjusza: "
			  << Kalkulator.PobierzTemperature(SCL_CELSIUS) << std::endl;
	std::cout << "- stopnie Fahrenheit: "
			  << Kalkulator.PobierzTemperature(SCL_FAHRENHEIT) << std::endl;
	std::cout << "- kelwiny: "
			  << Kalkulator.PobierzTemperature(SCL_KELVIN) << std::endl;

	// czekamy na dowolny klawisz
	_getch();
}