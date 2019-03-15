// Modu³ z kodem klasy CDegreesCalc

#include "calc.h"

/*------------------------------------------------------------------------------
   CDegreesCalc - implementacja klasy
  ----------------------------------------------------------------------------*/

void CDegreesCalc::UstawTemperature(double fTemperatura, SCALE Skala)
{
	// przeliczamy wszystkie temperatury na stopnie Celsjusza
	// i zapisujemy w prywatnym polu
	switch (Skala)
	{
	case SCL_CELSIUS:	 m_fStopnieC = fTemperatura; break;
	case SCL_FAHRENHEIT: m_fStopnieC = (5.0 / 9.0) * (fTemperatura - 32); break;
	case SCL_KELVIN:	 m_fStopnieC = fTemperatura - 273.15; break;
	}
}

double CDegreesCalc::PobierzTemperature(SCALE Skala)
{
	// przeliczamy temperaturê zapisan¹ w prywatnym polu w stopniach Celsjusza
	// i zwracamy
	switch (Skala)
	{
	case SCL_CELSIUS:	 return m_fStopnieC;
	case SCL_FAHRENHEIT: return (9.0 / 5.0) * m_fStopnieC + 32;
	case SCL_KELVIN:	 return m_fStopnieC + 273.15;
	default:			 return 0;
	}
}