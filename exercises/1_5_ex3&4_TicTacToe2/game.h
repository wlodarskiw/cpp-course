// Plik nag��wkowy w�a�ciwego kodu gry

// zabezpieczenie przez wielokrotnym do��czeniem
#pragma once

// typy
//------------------------------------------------------------------------------

// znak - czyli k�ko lub krzy�yk
enum SIGN { SGN_CIRCLE = 'O', SGN_CROSS = 'X' };

// pojedyncze pole (mo�e by� puste, mie� k�ko lub krzy�yk)
enum FIELD { FLD_EMPTY = 0,				// puste
			 FLD_CIRCLE = SGN_CIRCLE,	// k�ko
			 FLD_CROSS = SGN_CROSS };	// krzy�yk

// stan gry
enum GAMESTATE { GS_NOTSTARTED,	// nie rozpocz�ta
				 GS_MOVE,		// ruch gracza
				 GS_WON,		// wygrana gracza
				 GS_DRAW };		// remis

// deklaracje zmiennych
//------------------------------------------------------------------------------

// zmienna okre�laj�ca stan gry musi by� widoczna tak�e na zewn�trz
// modu�u game.cpp; poni�sza deklaracja czyni zado�� tej potrzebie

// stan gry
extern GAMESTATE g_StanGry;

// rozmiar planszy
const unsigned uRozmiar = 3;

// prototypy funkcji
//------------------------------------------------------------------------------

// rozpocz�cie gry
bool StartGry();

// narysowanie planszy
bool RysujPlansze();

// wykonanie ruchu
bool Ruch(unsigned);