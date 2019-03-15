// Plik nag��wkowy z klas� kalkulatora stopni

// typ wyliczeniowy okre�laj�cy skal� temperatur
enum SCALE { SCL_CELSIUS = 'c', SCL_FAHRENHEIT = 'f', SCL_KELVIN = 'k' };

class CDegreesCalc
{
	private:
		// temperatura w stopniach Celsjusza
		double m_fStopnieC;
	public:
		// ustawienie i pobranie temperatury
		void UstawTemperature(double, SCALE);
		double PobierzTemperature(SCALE);
};
