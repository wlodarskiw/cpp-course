// Plik nag��wkowy z klas� kalkulatora bajt�w

// typ wyliczeniowy okre�laj�cy skal� temperatur
enum BYTE { BT_BYTES = 'b', BT_KILOBYTES = 'k', BT_MEGABYTES = 'm',
			BT_GIGABYTES = 'g', BT_TERABYTES = 't' };

class CByteCalc
{
	private:
		// temperatura w stopniach Celsjusza
		double m_fBajty;
	public:
		// ustawienie i pobranie temperatury
		void UstawBajty(double, BYTE);
		double PobierzBajty(BYTE);
};
