// Modu³ implementuj¹cy klasy dokumentów

#include <iostream>
#include "documents.h"

/*------------------------------------------------------------------------------
   CDocument - implementacja klasy
  ----------------------------------------------------------------------------*/
void CDocument::PokazDane()
{
	// wyœwietlenie autora
	std::cout << "AUTOR: ";
	std::cout << m_strAutor << std::endl;

	// pokazanie tytu³u dokumentu
	// (sekwencja \" wstawia cudzys³ów do napisu)
	std::cout << "TYTUL: ";
	std::cout << "\"" << m_strTytul << "\"" << std::endl;

	// data utworzenia dokumentu
	/* (pDokument->Data() zwraca strukturê typu tm, do której pól
	mo¿na dostaæ siê tak samo, jak do wszystkich innych - za
	pomoc¹ operatora wy³uskania . (kropki)) */
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
	wiêc wywo³ujemy wersjê metody pochodz¹c¹ z tej klasy */
	CDocument::PokazDane();

	// dalej wyœwietlamy URLa
	std::cout << "URL: ";
	std::cout << m_strURL << std::endl;
}

/*------------------------------------------------------------------------------
   CBook - implementacja klasy
  ----------------------------------------------------------------------------*/
void CBook::PokazDane()
{
	// wyœwietlamy dane z CDocument
	CDocument::PokazDane();

	// pokazujemy numer ISBN
	std::cout << "ISBN: ";
	std::cout << m_strISBN << std::endl;
}