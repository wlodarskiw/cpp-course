// Mean - program licz�cy �redni� arytmetyczn�

/* wykonano trudniejszy wariant,
uzytkownik wprowadza liczby az do wpisania innego znaku */

/* wynonano bardzo trudny wariant zadania,
nie wykorzystujac do liczenia tak prostej rzeczy tablicy */

#include <iostream>
#include <conio.h>

void main()
{
	std::cout << "   Mean   " << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << std::endl;

	std::cout << "Podaj kolejne liczby do obliczenia sredniej arytmetycznej";
	std::cout << std::endl;
	std::cout << "Aby zakonczyc wpisz inny znak niz liczba." << std::endl;

	unsigned uIlosc = 0; // zmienna przechowuj�ca ilo�� liczb
	float fSuma = 0.0; // zmienna przechowuj�ca sum� liczb
	float fInput = 0.0; // zmienna przechowuj�ca co wprowadzi� u�ytkownik

	std::cout << "Podaj liczbe: ";
	while (std::cin >> fInput)
	{
		std::cout << "Podaj liczbe: ";
		fSuma += fInput;
		++uIlosc;
	}
	// wyswietlanie wyniku
	std::cout << "Srednia wynosi: " << fSuma << "/" << uIlosc << "=";
	std::cout << fSuma / uIlosc << std::endl;

	_getch();
}