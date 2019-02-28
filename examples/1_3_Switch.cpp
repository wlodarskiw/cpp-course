// Switch - instrukcja wyboru

#include <iostream>
#include <conio.h>

void main()
{
	std::cout << "   KALKULATOR   " << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << std::endl;

	// wczytanie pierwszej liczby
	float fLiczba1;
	std::cout << "Podaj pierwsza liczbe: ";
	std::cin >> fLiczba1;

	// wczytanie drugiej liczby
	float fLiczba2;
	std::cout << "Podaj druga liczbe: ";
	std::cin >> fLiczba2;

	std::cout << std::endl;

	// wyœwietlenie "menu" i proœba o wybór opcji
	int nOpcja;
	std::cout << "Wybierz dzialanie:" << std::endl;
	std::cout << "1. Dodawanie" << std::endl;
	std::cout << "2. Odejmowanie" << std::endl;
	std::cout << "3. Mnozenie" << std::endl;
	std::cout << "4. Dzielenie" << std::endl;
	std::cout << "0. Wyjscie" << std::endl;
	std::cout << "Twoj wybor: ";
	std::cin >> nOpcja;

	// sprawdzenie, jak¹ opcje wybrano i wykonanie dzia³ania
	switch (nOpcja)
	{
	case 1: std::cout << fLiczba1 << " + " << fLiczba2 << " = "
		<< fLiczba1 + fLiczba2; break;
	case 2: std::cout << fLiczba1 << " - " << fLiczba2 << " = "
		<< fLiczba1 - fLiczba2; break;
	case 3: std::cout << fLiczba1 << " * " << fLiczba2 << " = "
		<< fLiczba1 * fLiczba2; break;
	case 4:
		if (fLiczba2 == 0.0)
			std::cout << "Dzielnik nie moze byc zerem!";
		else
			std::cout << fLiczba1 << " / " << fLiczba2 << " = "
			<< fLiczba1 / fLiczba2;
		break;
	case 0: std::cout << "Dziekujemy :)"; break;
	default: std::cout << "Nieznana opcja!";
	}
	_getch();
}