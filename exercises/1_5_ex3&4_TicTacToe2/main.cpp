// TicTacToe - wielki projekt gry typu "k�ko i krzy�yk"

#include <iostream>
#include <conio.h>
#include "game.h"

void main()
{
	// rozpoczynamy gr�
	StartGry();

	// p�tla niesko�czona - cz�sty element w grach
	// wyjdziemy z niej przy pomocy break w odpowiednim momencie
	for (;;)
	{
		// rysujemy plansz�
		RysujPlansze();

		// sprawdzamy stan gry i czynimy odpowiednie dzia�ania
		if (g_StanGry == GS_MOVE)
		{
			// ruch kt�rego� gracza
			// pobieramy go wi�c i wywo�ujemy funkcj� Ruch()
			// pobieramy znak kt�ry wstawi u�ytkownik i castujemy go na unsigned
			char chNumerPola;
			std::cin >> chNumerPola;
			Ruch(static_cast<unsigned>(chNumerPola));
		}
		else if (g_StanGry == GS_WON || g_StanGry == GS_DRAW)
			// koniec gry (wygran� lub remisem)
			// wtedy przerywamy p�tl�
			break;
	}

	// czekamy na dowolny klawisz
	_getch();
}