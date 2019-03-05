// QuadraticEq - rozwi�zywanie r�wna� kwadratowych

#include <iostream>
#include <conio.h>
#include <cmath>

void main()
{
	std::cout << "   ROWNANIE KWADRATOWE (ax^2 + bx + c = 0)   " << std::endl;
	std::cout << "---------------------------------------------" << std::endl;

	float fA;
	std::cout << "Podaj wspolczynnik a: ";
	std::cin >> fA;

	float fB;
	std::cout << "Podaj wspolczynnik b: ";
	std::cin >> fB;

	float fC;
	std::cout << "Podaj wspolczynnik c: ";
	std::cin >> fC;

	// je�eli a jest r�wne zeru...
	if (fA == 0.0)
	{
		// ...to r�wnanie traktujemy jak liniowe
		// je�eli b jest r�wne zeru...
		if (fB == 0.0)
		{
			// ...to r�wnanie mo�e mie� niesko�czenie wiele
			// rozwi�za�, lub nie mie� ich wcale - zale�nie od c
			if (fC == 0.0)
				// b i c r�wne zeru - niesko�czenie wiele rozwi�za�
				std::cout << "Rownanie spelnia kazda liczba rzeczywista." << std::endl;
			else
				// brak rozwiazan
				std::cout << "Rownanie nie posiada rozwiazan." << std::endl;
		}
		else
			// je�eli b jest r�ne od zera, to r�wnanie posiada jedno
			// rozwi�zanie, -c/b
			std::cout << "x = " << -fC / fB << std::endl;
	}
	else
	{
		// obliczamy wyr�nik r�wnania kwadratowego
		float fDelta = 0;
		fDelta = pow(fB, 2) - 4 * fA * fC;

		// nale�y sprawdzi� znak wyr�nika
		if (fDelta < 0)
			// r�wnanie nie ma rozwi�zan
			std::cout << "Rownanie nie ma rozwiazan rzeczywistych." << std::endl;
		else if (fDelta == 0)
			// istnieje jedno rozwiazanie x1 = x2 = -b/2a
			std::cout << "x1 = x2 = " << -fB / 2 * fA << std::endl;
		else
		{
			// je�eli a jest r�zne od zera, to rownanie posiada dwa rozwiazania
			std::cout << "x1 = " << (-fB - sqrt(fDelta)) / (2 * fA) << std::endl;
			std::cout << "x2 = " << (-fB + sqrt(fDelta)) / (2 * fA) << std::endl;
		}
	}

	_getch();
}