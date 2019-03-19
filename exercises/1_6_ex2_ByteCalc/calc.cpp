// Modu³ z kodem klasy CByteCalc

#include <cmath>
#include "calc.h"

/*------------------------------------------------------------------------------
   CByteCalc - implementacja klasy
  ----------------------------------------------------------------------------*/

void CByteCalc::UstawBajty(double fBajty, BYTE Skala)
{
	// przeliczamy wszystkie podane wartoœci na bajty
	// i zapisujemy w prywatnym polu
	switch (Skala)
	{
	case BT_BYTES:	   m_fBajty = fBajty;				break;
	case BT_KILOBYTES: m_fBajty = fBajty / pow(1000,1); break;
	case BT_MEGABYTES: m_fBajty = fBajty / pow(1000,2); break;
	case BT_GIGABYTES: m_fBajty = fBajty / pow(1000,3); break;
	case BT_TERABYTES: m_fBajty = fBajty / pow(1000,4); break;
	}
}

double CByteCalc::PobierzBajty(BYTE Skala)
{
	// przeliczamy bajty i zwracamy
	switch (Skala)
	{
	case BT_BYTES:	   return m_fBajty;
	case BT_KILOBYTES: return m_fBajty * pow(1000,1);
	case BT_MEGABYTES: return m_fBajty * pow(1000,2);
	case BT_GIGABYTES: return m_fBajty * pow(1000,3);
	case BT_TERABYTES: return m_fBajty * pow(1000,4);
	default:		   return 0;
	}
}