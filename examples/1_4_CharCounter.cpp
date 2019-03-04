// CharCounter - zliczanie znaków

#include <string>
#include <iostream>
#include <conio.h>

unsigned ZliczZnaki(std::string strTekst, char chZnak)
{
	unsigned uIlosc = 0;

	for (unsigned i = 0; i <= strTekst.length() - 1; ++i)
	{
		if (strTekst[i] == chZnak)
			++uIlosc;
	}

	return uIlosc;
}

void main()
{
	std::cout << "   LICZNIK ZNAKOW   " << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << std::endl;

	std::string strNapis;
	std::cout << "Podaj tekst, w ktorym maja byc zliczane znaki: ";
	std::cin >> strNapis;

	char chSzukanyZnak;
	std::cout << "Podaj znak, ktory bedzie liczony: ";
	std::cin >> chSzukanyZnak;

	std::cout << "Znak '" << chSzukanyZnak << "' wystepuje w tekscie "
		<< ZliczZnaki(strNapis, chSzukanyZnak) << " raz(y)." << std::endl;

	_getch();
}

