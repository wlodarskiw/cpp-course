// W³aœciwy kod gry

#include <iostream>
#include <ctime>
#include "game.h"

// zmienne
//------------------------------------------------------------------------------

// plansza w postaci tablicy 3x3
FIELD g_aPlansza[uRozmiar][uRozmiar];

// stan gry (nie rozpoczêta, ruch gracza, wygrana lub remis)
GAMESTATE g_StanGry = GS_NOTSTARTED;

// znak aktualnego gracza (kó³ko lub krzy¿yk)
SIGN g_AktualnyGracz;

// funkcje
//------------------------------------------------------------------------------

// funkcja wywo³ywana na starcie gry
bool StartGry()
{
	// najpierw sprawdzamy, czy gra ju¿ nie trwa;
	// je¿eli tak, to funkcja koñczy siê pora¿k¹
	if (g_StanGry != GS_NOTSTARTED) return false;

	// "wyzerowanie" planszy
	for (int i = 0; i < uRozmiar; ++i)
	{
		for (int j = 0; j < uRozmiar; ++j)
		{
			g_aPlansza[i][j] = FLD_EMPTY;
		}
	}

	// losujemy gracza, który bêdzie zaczyna³
	srand(static_cast<unsigned>(time(NULL)));
	g_AktualnyGracz = (rand() % 2 == 0 ? SGN_CIRCLE : SGN_CROSS);

	// ustawiamy stan gry na ruch graczy
	g_StanGry = GS_MOVE;

	// wszystko siê uda³o, zatem zwracamy true
	return true;
}

// rysowanie (albo raczej wypisywanie) pola gry
bool RysujPlansze()
{
	// sprawdzamy, czy gra rozpoczê³a siê
	if (g_StanGry == GS_NOTSTARTED)	return false;

	// czyœcimy okienko konsoli przy pomocy polecenia systemowego CLS
	system("cls");

	// pokazujemy szyld tytu³owy
	std::cout << "   KOLKO I KRZYZYK   " << std::endl;
	std::cout << "---------------------" << std::endl;
	std::cout << std::endl;

	// nastêpnie wypisujemy w³aœciw¹ planszê przy pomocy dwóch pêtli for
	// górna czêœæ ramki
	std::cout << "     ";
	for (int i = 0; i < uRozmiar * 2 + 3; ++i)
		std::cout << "-";
	std::cout << std::endl;

	// kolumna
	for (int i = 0; i < uRozmiar; ++i)
	{
		// lewa czêœæ ramki
		std::cout << "     | ";

		// wiersz
		for (int j = 0; j < uRozmiar; ++j)
		{
			// sprawdzamy, czy dane pole jest puste
			if (g_aPlansza[i][j] == FLD_EMPTY)
			{
				/* wtedy wyœwietlamy jego numerek tak,
				¿eby u¿ytkownik wiedzia³, jak¹ liczbê wpisaæ, gdy bêdzie chcia³
				postawiæ na nim kó³ko lub krzy¿yk */
				std::cout << i * uRozmiar + j + 1 << " ";
			}
			else
			{
				/* je¿eli natomiast pole jest zajête,
				wyœwietlamy odpowiadaj¹cy mu znak */
				std::cout << static_cast<char>(g_aPlansza[i][j]) << " ";
			}
		}

		// prawa czêœæ ramki
		std::cout << "|" << std::endl;
	}
	// dolna czêœæ ramki
	std::cout << "     ";
	for (int i = 0; i < uRozmiar * 2 + 3; ++i)
		std::cout << "-";
	std::cout << std::endl;
	std::cout << std::endl;

	/* wreszcie, pokazujemy dolny komunikat
	jest on albo proœb¹ o podanie ruchu, albo informacj¹ o stanie gry
	wszystko zale¿y o tego¿ stanu, a zatem stosujemy instrukcjê switch */
	switch (g_StanGry)
	{
		case GS_MOVE:
			// ruch gracza, a wiêc gra trwa
			// musimy wiêc poprosiæ o ruch
			std::cout << "Podaj numer pola, w ktorym" << std::endl;
			std::cout << "chcesz postawic ";
			std::cout << (g_AktualnyGracz == SGN_CIRCLE ?
						 "kolko" : "krzyzyk") << ": ";
			break;
		case GS_WON:
			// gra zakoñczona, ktoœ wygra³
			// wyœwietlamy odpowiedni¹ informacjê
			std::cout << "Wygral gracz stawiajacy ";
			std::cout << (g_AktualnyGracz == SGN_CIRCLE ?
						 "kolka" : "krzyzyki") << "!";
			break;
		case GS_DRAW:
			// mo¿e te¿ siê zdarzyæ remis
			// tak¿e pokazujemy wiadomoœæ
			std::cout << "Remis!";
			break;
	}
	// wszystko posz³o OK, zatem powiadamiamy o tym
	return true;
}

// wykonanie ruchu i sprawdzenie jego rezultatu
bool Ruch(unsigned uNumerPola)
{
	// sprawdzanie stanu gry
	if (g_StanGry != GS_MOVE) return false;

	/* sprawdzamy, czy numer podane pola mieœci siê w przedziale <1=49; 9=57>
	s¹ to wartoœci po castowaniu char na unsigned, powstrzymuje to te¿
	u¿ytkownika przed wprowadzeniem litery b¹dŸ innego znaku */
	if (!(uNumerPola >= 49 && uNumerPola <= (48 + uRozmiar * uRozmiar))) 
		return false;

	// zmieniamy zakres zmiennej na <1; 9>
	uNumerPola -= 48;

	/* jeœli doszliœmy dot¹d, to wszystko jest w porz¹dku i mo¿emy wykonaæ ruch 
	przeliczamy wiêc numer pola na indeksy tablicy i przypisujemy znak gracza
	(tylko wtedy, gdy pole jest puste) */
	unsigned uY = (uNumerPola - 1) / uRozmiar;
	unsigned uX = (uNumerPola - 1) % uRozmiar;
	if (g_aPlansza[uY][uX] == FLD_EMPTY)
		// wstaw znak aktualnego gracza w podanym polu
		g_aPlansza[uY][uX] = static_cast<FIELD>(g_AktualnyGracz);
	else
		// je¿eli próbowano dwukrotnie postawiæ znak w tym samym miejscu
		return false;

	// tablica przegl¹dowa wszystkich wygrywaj¹cych zestawów pól
	// generujemy j¹ przy pomocy dwóch pêtli for i warunków
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
			// przek¹tna backslashowa
			else if (j == uRozmiar * 2)
			{
				LINIE[j][i][0] = i;
				LINIE[j][i][1] = i;
			}
			// przek¹tna slashowa
			else
			{
				LINIE[j][i][0] = uRozmiar - 1 - i;
				LINIE[j][i][1] = i;
			}
		}
	}

	// sprawdzanie czy u¿ytkownik u³o¿y³ liniê
	FIELD Pole, ZgodnePole;
	unsigned uLiczbaZgodnychPol;
	for (int i = 0; i < uRozmiar * 2 + 2; ++i)
	{
		// i przebiega po kolejnych mo¿liwych liniach (jest ich osiem)

		// zerujemy zmienne pomocnicze
		Pole = ZgodnePole = FLD_EMPTY; // obie zmienne == FLD_EMPTY
		uLiczbaZgodnychPol = 0;

		for (int j = 0; j < uRozmiar; ++j)
		{
			// j przebiega po trzech polach w ka¿dej linii

			// pobieramy rzeczone pola
			Pole = g_aPlansza[LINIE[i][j][0]][LINIE[i][j][1]];

			// jeœli sprawdzane pole ró¿ne od tego, które ma siê zgadzaæ...
			if (Pole != ZgodnePole)
			{
				// to zmieniamy zgodne pole na to aktualne
				ZgodnePole = Pole;
				uLiczbaZgodnychPol = 1;
			}
			else
				/* jeœli natomiast oba pola siê zgadzaj¹,
				ikrementujemy licznik zgodnych pól */
				++uLiczbaZgodnychPol;
		}

		// teraz sprawdzamy, czy uda³o nam siê zgodziæ linie
		if (uLiczbaZgodnychPol == uRozmiar && ZgodnePole != FLD_EMPTY)
		{
			// je¿eli tak, ustawiamy stan gry na wygran¹
			g_StanGry = GS_WON;

			// przerywamy pêtlê i funkcjê
			return true;
		}
	}

	/* istnieje jeszcze mo¿liwoœæ, ¿e nast¹pi³ remis wtedy funkcja dojdzie
	tutaj i ca³a plansza bêdzie pokryta krzy¿ykami i kó³kami 
	sprawdzamy to przy pomocy odpowiedniej pêtli, zliczaj¹cej zape³nione pola 
	je¿eli jest ich tyle, ile wszystkich mo¿liwych pól, koñczymy remisem */
	unsigned uLiczbaZapelnionychPol = 0;
	for (int i = 0; i < uRozmiar; ++i)
		for (int j = 0; j < uRozmiar; ++j)
			if (g_aPlansza[i][j] != FLD_EMPTY)
				++uLiczbaZapelnionychPol;
	if (uLiczbaZapelnionychPol == uRozmiar * uRozmiar)
	{
		// ustawiamy stan gry na remis
		g_StanGry = GS_DRAW;

		// koñczymy funkcjê
		return true;
	}

	// oczywiœcie, mo¿e siê zdarzyæ, i¿ gra po prostu toczy siê dalej
	// w takim wypadku zmieniamy jedynie aktualnego gracza
	g_AktualnyGracz = (g_AktualnyGracz == SGN_CIRCLE ? SGN_CROSS : SGN_CIRCLE);

	// zwracamy true
	return true;
}