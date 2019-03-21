// Modu� implementuj�cy klasy dokument�w

#include <iostream>
#include "documents.h"

/*------------------------------------------------------------------------------
   CDocument - implementacja klasy
  ----------------------------------------------------------------------------*/
void CDocument::PokazDane()
{
	// wy�wietlenie autora
	std::cout << "AUTOR: ";
	std::cout << m_strAutor << std::endl;

	// pokazanie tytu�u dokumentu
	// (sekwencja \" wstawia cudzys��w do napisu)
	std::cout << "TYTUL: ";
	std::cout << "\"" << m_strTytul << "\"" << std::endl;

	// data utworzenia dokumentu
	/* (pDokument->Data() zwraca struktur� typu tm, do kt�rej p�l
	mo�na dosta� si� tak samo, jak do wszystkich innych - za
	pomoc� operatora wy�uskania . (kropki)) */
	std::cout << "DATA: ";
	std::cout << m_Data.tm_mday << "." << (m_Data.tm_mon + 1) << "."
			  << (m_Data.tm_year + 1900) << std::endl;
}

/*------------------------------------------------------------------------------
   COnlineDocument - implementacja klasy
  ----------------------------------------------------------------------------*/
void COnlineDocument::PokazDane()
{
	/* najpierw pokazujemy dane odziedziczone z CDocument,
	wi�c wywo�ujemy wersj� metody pochodz�c� z tej klasy */
	CDocument::PokazDane();

	// dalej wy�wietlamy URLa
	std::cout << "URL: ";
	std::cout << m_strURL << std::endl;
}

/*------------------------------------------------------------------------------
   CBook - implementacja klasy
  ----------------------------------------------------------------------------*/
void CBook::PokazDane()
{
	// wy�wietlamy dane z CDocument
	CDocument::PokazDane();

	// pokazujemy numer ISBN
	std::cout << "ISBN: ";
	std::cout << m_strISBN << std::endl;
}