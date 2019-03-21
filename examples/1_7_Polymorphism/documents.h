// Plik nag³ówkowy z definicjami klas dokumentów

#include <string>
#include <time.h>
//------------------------------------------------------------------------------
// klasa dowolnego dokumentu
class CDocument
{
	protected:
		// podstawowe dane dokumentu
		std::string m_strAutor; // autor dokumentu
		std::string m_strTytul; // tytu³ dokumentu
		tm m_Data; // data stworzenia
	public:
		// kontruktory
		CDocument()
		{
			m_strAutor = m_strTytul = "???";
			time_t Czas = time(NULL);
			//m_Data = *localtime(&Czas);
			localtime_s(&m_Data, &Czas);
		}

		CDocument(std::string strTytul)
		{
			CDocument();
			m_strTytul = strTytul;
		}

		CDocument(std::string strAutor, std::string strTytul)
		{
			CDocument();
			m_strAutor = strAutor;
			m_strTytul = strTytul;
		}
//------------------------------------------------------------------------------
		// metody
		virtual void PokazDane();

		// metody dostêpowe do pól
		std::string Autor() const { return m_strAutor; }
		std::string Tytul() const { return m_strTytul; }
		tm Data() const { return m_Data; }
};
//------------------------------------------------------------------------------
// dokument internetowy
class COnlineDocument : public CDocument
{
	protected:
		std::string m_strURL; // adres internetowy dokumentu
	public:
		// kontruktory
		COnlineDocument(std::string strAutor, std::string strTytul)
		{
			m_strAutor = strAutor;
			m_strTytul = strTytul;
		}

		COnlineDocument(std::string strAutor,
						std::string strTytul,
						std::string strURL)
		{
			m_strAutor = strAutor;
			m_strTytul = strTytul;
			m_strURL = strURL;
		}
//------------------------------------------------------------------------------
		// metody
		void PokazDane(); // wirtualna metoda przedefiniowana z CDocument

		// metody dostêpowe do pól
		std::string URL() const { return m_strURL; }
};
//------------------------------------------------------------------------------
// ksi¹¿ka
class CBook : public CDocument
{
	protected:
		std::string m_strISBN; // numer ISBN ksi¹¿ki
	public:
		// kontruktory
		CBook(std::string strAutor, std::string strTytul)
		{
			m_strAutor = strAutor;
			m_strTytul = strTytul;
		}

		CBook(std::string strAutor, std::string strTytul, std::string strISBN)
		{
			m_strAutor = strAutor;
			m_strTytul = strTytul;
			m_strISBN = strISBN;
		}
//------------------------------------------------------------------------------
		// metody
		void PokazDane(); // tak¿e wirtualna, przedefiniowana metoda

		// metody dostêpowe do pól
		std::string ISBN() const { return m_strISBN; }
};