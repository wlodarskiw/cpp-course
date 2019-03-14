// TicTacToe - wielki projekt gry typu "kó³ko i krzy¿yk"

#include <iostream>
#include <conio.h>
#include "game.h"

void main()
{
	// rozpoczynamy grê
	StartGry();

	// pêtla nieskoñczona - czêsty element w grach
	// wyjdziemy z niej przy pomocy break w odpowiednim momencie
	for (;;)
	{
		// rysujemy planszê
		RysujPlansze();

		// sprawdzamy stan gry i czynimy odpowiednie dzia³ania
		if (g_StanGry == GS_MOVE)
		{
			// ruch któregoœ gracza
			// pobieramy go wiêc i wywo³ujemy funkcjê Ruch()
			// pobieramy znak który wstawi u¿ytkownik i castujemy go na unsigned
			char chNumerPola;
			std::cin >> chNumerPola;
			Ruch(static_cast<unsigned>(chNumerPola));
		}
		else if (g_StanGry == GS_WON || g_StanGry == GS_DRAW)
			// koniec gry (wygran¹ lub remisem)
			// wtedy przerywamy pêtlê
			break;
	}

	// czekamy na dowolny klawisz
	_getch();
}