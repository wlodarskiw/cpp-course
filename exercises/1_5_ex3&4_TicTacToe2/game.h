// Plik nag³ówkowy w³aœciwego kodu gry

// zabezpieczenie przez wielokrotnym do³¹czeniem
#pragma once

// typy
//------------------------------------------------------------------------------

// znak - czyli kó³ko lub krzy¿yk
enum SIGN { SGN_CIRCLE = 'O', SGN_CROSS = 'X' };

// pojedyncze pole (mo¿e byæ puste, mieæ kó³ko lub krzy¿yk)
enum FIELD { FLD_EMPTY = 0,				// puste
			 FLD_CIRCLE = SGN_CIRCLE,	// kó³ko
			 FLD_CROSS = SGN_CROSS };	// krzy¿yk

// stan gry
enum GAMESTATE { GS_NOTSTARTED,	// nie rozpoczêta
				 GS_MOVE,		// ruch gracza
				 GS_WON,		// wygrana gracza
				 GS_DRAW };		// remis

// deklaracje zmiennych
//------------------------------------------------------------------------------

// zmienna okreœlaj¹ca stan gry musi byæ widoczna tak¿e na zewn¹trz
// modu³u game.cpp; poni¿sza deklaracja czyni zadoœæ tej potrzebie

// stan gry
extern GAMESTATE g_StanGry;

// rozmiar planszy
const unsigned uRozmiar = 3;

// prototypy funkcji
//------------------------------------------------------------------------------

// rozpoczêcie gry
bool StartGry();

// narysowanie planszy
bool RysujPlansze();

// wykonanie ruchu
bool Ruch(unsigned);