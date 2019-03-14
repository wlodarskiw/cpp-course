// W�a�ciwy kod gry

#include <iostream>
#include <ctime>
#include "game.h"

// zmienne
//------------------------------------------------------------------------------

// plansza w postaci tablicy 3x3
FIELD g_aPlansza[uRozmiar][uRozmiar];

// stan gry (nie rozpocz�ta, ruch gracza, wygrana lub remis)
GAMESTATE g_StanGry = GS_NOTSTARTED;

// znak aktualnego gracza (k�ko lub krzy�yk)
SIGN g_AktualnyGracz;

// funkcje
//------------------------------------------------------------------------------

// funkcja wywo�ywana na starcie gry
bool StartGry()
{
	// najpierw sprawdzamy, czy gra ju� nie trwa;
	// je�eli tak, to funkcja ko�czy si� pora�k�
	if (g_StanGry != GS_NOTSTARTED) return false;

	// "wyzerowanie" planszy
	for (int i = 0; i < uRozmiar; ++i)
	{
		for (int j = 0; j < uRozmiar; ++j)
		{
			g_aPlansza[i][j] = FLD_EMPTY;
		}
	}

	// losujemy gracza, kt�ry b�dzie zaczyna�
	srand(static_cast<unsigned>(time(NULL)));
	g_AktualnyGracz = (rand() % 2 == 0 ? SGN_CIRCLE : SGN_CROSS);

	// ustawiamy stan gry na ruch graczy
	g_StanGry = GS_MOVE;

	// wszystko si� uda�o, zatem zwracamy true
	return true;
}

// rysowanie (albo raczej wypisywanie) pola gry
bool RysujPlansze()
{
	// sprawdzamy, czy gra rozpocz�a si�
	if (g_StanGry == GS_NOTSTARTED)	return false;

	// czy�cimy okienko konsoli przy pomocy polecenia systemowego CLS
	system("cls");

	// pokazujemy szyld tytu�owy
	std::cout << "   KOLKO I KRZYZYK   " << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	// nast�pnie wypisujemy w�a�ciw� plansz� przy pomocy dw�ch p�tli for
	// g�rna cz�� ramki
	std::cout << "     ";
	for (int i = 0; i < uRozmiar * 2 + 3; ++i)
		std::cout << "-";
	std::cout << std::endl;

	// kolumna
	for (int i = 0; i < uRozmiar; ++i)
	{
		// lewa cz�� ramki
		std::cout << "     | ";

		// wiersz
		for (int j = 0; j < uRozmiar; ++j)
		{
			// sprawdzamy, czy dane pole jest puste
			if (g_aPlansza[i][j] == FLD_EMPTY)
			{
				/* wtedy wy�wietlamy jego numerek tak,
				�eby u�ytkownik wiedzia�, jak� liczb� wpisa�, gdy b�dzie chcia�
				postawi� na nim k�ko lub krzy�yk */
				std::cout << i * uRozmiar + j + 1 << " ";
			}
			else
			{
				/* je�eli natomiast pole jest zaj�te,
				wy�wietlamy odpowiadaj�cy mu znak */
				std::cout << static_cast<char>(g_aPlansza[i][j]) << " ";
			}
		}

		// prawa cz�� ramki
		std::cout << "|" << std::endl;
	}
	// dolna cz�� ramki
	std::cout << "     ";
	for (int i = 0; i < uRozmiar * 2 + 3; ++i)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << std::endl;

	/* wreszcie, pokazujemy dolny komunikat
	jest on albo pro�b� o podanie ruchu, albo informacj� o stanie gry
	wszystko zale�y o tego� stanu, a zatem stosujemy instrukcj� switch */
	switch (g_StanGry)
	{
		case GS_MOVE:
			// ruch gracza, a wi�c gra trwa
			// musimy wi�c poprosi� o ruch
			std::cout << "Podaj numer pola, w ktorym" << std::endl;
			std::cout << "chcesz postawic ";
			std::cout << (g_AktualnyGracz == SGN_CIRCLE ?
						 "kolko" : "krzyzyk") << ": ";
			break;
		case GS_WON:
			// gra zako�czona, kto� wygra�
			// wy�wietlamy odpowiedni� informacj�
			std::cout << "Wygral gracz stawiajacy ";
			std::cout << (g_AktualnyGracz == SGN_CIRCLE ?
						 "kolka" : "krzyzyki") << "!";
			break;
		case GS_DRAW:
			// mo�e te� si� zdarzy� remis
			// tak�e pokazujemy wiadomo��
			std::cout << "Remis!";
			break;
	}
	// wszystko posz�o OK, zatem powiadamiamy o tym
	return true;
}

// wykonanie ruchu i sprawdzenie jego rezultatu
bool Ruch(unsigned uNumerPola)
{
	// sprawdzanie stanu gry
	if (g_StanGry != GS_MOVE) return false;

	/* sprawdzamy, czy numer podane pola mie�ci si� w przedziale <1=49; 9=57>
	s� to warto�ci po castowaniu char na unsigned, powstrzymuje to te�
	u�ytkownika przed wprowadzeniem litery b�d� innego znaku */
	if (!(uNumerPola >= 49 && uNumerPola <= (48 + uRozmiar * uRozmiar))) 
		return false;

	// zmieniamy zakres zmiennej na <1; 9>
	uNumerPola -= 48;

	/* je�li doszli�my dot�d, to wszystko jest w porz�dku i mo�emy wykona� ruch 
	przeliczamy wi�c numer pola na indeksy tablicy i przypisujemy znak gracza
	(tylko wtedy, gdy pole jest puste) */
	unsigned uY = (uNumerPola - 1) / uRozmiar;
	unsigned uX = (uNumerPola - 1) % uRozmiar;
	if (g_aPlansza[uY][uX] == FLD_EMPTY)
		// wstaw znak aktualnego gracza w podanym polu
		g_aPlansza[uY][uX] = static_cast<FIELD>(g_AktualnyGracz);
	else
		// je�eli pr�bowano dwukrotnie postawi� znak w tym samym miejscu
		return false;

	// tablica przegl�dowa wszystkich wygrywaj�cych zestaw�w p�l
	// generujemy j� przy pomocy dw�ch p�tli for i warunk�w
	int LINIE[uRozmiar * 2 + 2][uRozmiar][2];

	// kolumny
	for (int i = 0; i < uRozmiar; ++i)
	{
		// wiersze
		for (int j = 0; j < uRozmiar * 2 + 2; ++j)
		{
			// poziome linie
			if (j < uRozmiar)
			{
				LINIE[j][i][0] = j;
				LINIE[j][i][1] = i;
			}
			// pionowe linie
			else if (j < uRozmiar * 2)
			{
				LINIE[j][i][0] = i;
				LINIE[j][i][1] = j % uRozmiar;
			}
			// przek�tna backslashowa
			else if (j == uRozmiar * 2)
			{
				LINIE[j][i][0] = i;
				LINIE[j][i][1] = i;
			}
			// przek�tna slashowa
			else
			{
				LINIE[j][i][0] = uRozmiar - 1 - i;
				LINIE[j][i][1] = i;
			}
		}
	}

	// sprawdzanie czy u�ytkownik u�o�y� lini�
	FIELD Pole, ZgodnePole;
	unsigned uLiczbaZgodnychPol;
	for (int i = 0; i < uRozmiar * 2 + 2; ++i)
	{
		// i przebiega po kolejnych mo�liwych liniach (jest ich osiem)

		// zerujemy zmienne pomocnicze
		Pole = ZgodnePole = FLD_EMPTY; // obie zmienne == FLD_EMPTY
		uLiczbaZgodnychPol = 0;

		for (int j = 0; j < uRozmiar; ++j)
		{
			// j przebiega po trzech polach w ka�dej linii

			// pobieramy rzeczone pola
			Pole = g_aPlansza[LINIE[i][j][0]][LINIE[i][j][1]];

			// je�li sprawdzane pole r�ne od tego, kt�re ma si� zgadza�...
			if (Pole != ZgodnePole)
			{
				// to zmieniamy zgodne pole na to aktualne
				ZgodnePole = Pole;
				uLiczbaZgodnychPol = 1;
			}
			else
				/* je�li natomiast oba pola si� zgadzaj�,
				ikrementujemy licznik zgodnych p�l */
				++uLiczbaZgodnychPol;
		}

		// teraz sprawdzamy, czy uda�o nam si� zgodzi� linie
		if (uLiczbaZgodnychPol == uRozmiar && ZgodnePole != FLD_EMPTY)
		{
			// je�eli tak, ustawiamy stan gry na wygran�
			g_StanGry = GS_WON;

			// przerywamy p�tl� i funkcj�
			return true;
		}
	}

	/* istnieje jeszcze mo�liwo��, �e nast�pi� remis wtedy funkcja dojdzie
	tutaj i ca�a plansza b�dzie pokryta krzy�ykami i k�kami 
	sprawdzamy to przy pomocy odpowiedniej p�tli, zliczaj�cej zape�nione pola 
	je�eli jest ich tyle, ile wszystkich mo�liwych p�l, ko�czymy remisem */
	unsigned uLiczbaZapelnionychPol = 0;
	for (int i = 0; i < uRozmiar; ++i)
		for (int j = 0; j < uRozmiar; ++j)
			if (g_aPlansza[i][j] != FLD_EMPTY)
				++uLiczbaZapelnionychPol;
	if (uLiczbaZapelnionychPol == uRozmiar * uRozmiar)
	{
		// ustawiamy stan gry na remis
		g_StanGry = GS_DRAW;

		// ko�czymy funkcj�
		return true;
	}

	// oczywi�cie, mo�e si� zdarzy�, i� gra po prostu toczy si� dalej
	// w takim wypadku zmieniamy jedynie aktualnego gracza
	g_AktualnyGracz = (g_AktualnyGracz == SGN_CIRCLE ? SGN_CROSS : SGN_CIRCLE);

	// zwracamy true
	return true;
}