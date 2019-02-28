// LinearEq - rozwi¹zywanie równañ liniowych

#include <iostream>
#include <conio.h>

void main()
{
	std::cout << "   ROWNANIE LINIOWE (ax + b = 0)   " << std::endl;
	std::cout << "-----------------------------------" << std::endl;

	float fA;
	std::cout << "Podaj wspolczynnik a: ";
	std::cin >> fA;

	float fB;
	std::cout << "Podaj wspolczynnik b: ";
	std::cin >> fB;

	// je¿eli a jest równe zeru...
	if (fA == 0.0)
	{
		// ...to równanie mo¿e mieæ nieskoñczenie wiele
		// rozwi¹zañ, lub nie mieæ ich wcale - zale¿nie od b
		if (fB == 0.0)
			// a i b równe zeru - nieskoñczenie wiele rozwi¹zañ
			std::cout << "Rownanie spelnia kazda liczba rzeczywista." << std::endl;
		else
			// brak rozwiazan
			std::cout << "Rownanie nie posiada rozwiazan." << std::endl;
	}
	else
		// je¿eli a jest ró¿ne od zera, to równanie posiada jedno
		// rozwi¹zanie, -b/a
		std::cout << "x = " << -fB / fA << std::endl;

	_getch();
}