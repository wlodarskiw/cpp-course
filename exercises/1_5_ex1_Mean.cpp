// Mean - program licz¹cy œredni¹ arytmetyczn¹

/* wykonano trudniejszy wariant,
uzytkownik wprowadza liczby az do wpisania znaku 'x' */

/* wynonano bardzo trudny wariant zadania,
nie wykorzystujac do liczenia tak prostej rzeczy tablicy */

#include <iostream>
#include <conio.h>
#include <string>

void main()
{
	std::cout << "   Mean   " << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << std::endl;

	std::cout << "Podaj kolejne liczby do obliczenia sredniej arytmetycznej";
	std::cout << std::endl;
	std::cout << "Aby zakonczyc wpisz 'x'." << std::endl;

	unsigned uIlosc = 0; // zmienna przechowuj¹ca iloœæ liczb
	float fSuma = 0.0; // zmienna przechowuj¹ca sumê liczb
	std::string sInput = ""; // zmienna pomocnicza do wprowadzania liczb

	for (;;)
	{
		std::cout << "Podaj liczbe: ";
		std::cin >> sInput;

		if (sInput == "x") break;
		// warunek przerywajacy petle jezeli uzytkownik wprowadzil 'x'
		else
		{
			// wprowadzanie liczb do tabeli i zliczanie ich sumy
			fSuma += std::stof(sInput);
			++uIlosc;
		}
	}
	// wyswietlanie wyniku
	std::cout << "Srednia wynosi: " << fSuma << "/" << uIlosc << "=";
	std::cout << fSuma / uIlosc << std::endl;

	_getch();
}