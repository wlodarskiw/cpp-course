// LinearEq - rozwi�zywanie r�wna� liniowych

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

	// je�eli a jest r�wne zeru...
	if (fA == 0.0)
	{
		// ...to r�wnanie mo�e mie� niesko�czenie wiele
		// rozwi�za�, lub nie mie� ich wcale - zale�nie od b
		if (fB == 0.0)
			// a i b r�wne zeru - niesko�czenie wiele rozwi�za�
			std::cout << "Rownanie spelnia kazda liczba rzeczywista." << std::endl;
		else
			// brak rozwiazan
			std::cout << "Rownanie nie posiada rozwiazan." << std::endl;
	}
	else
		// je�eli a jest r�ne od zera, to r�wnanie posiada jedno
		// rozwi�zanie, -b/a
		std::cout << "x = " << -fB / fA << std::endl;

	_getch();
}