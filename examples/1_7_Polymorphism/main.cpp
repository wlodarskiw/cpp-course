// Polymorphism - wykorzystanie techniki polimorfizmu

#include <iostream>
#include <conio.h>
#include "documents.h"

void main()
{
	std::cout << "   POLIMORFIZM   " << std::endl;
	std::cout << "-----------------" << std::endl;

	// wskaŸnik na obiekty dokumentów
	CDocument* pDokument;

	// pierwszy dokument - internetowy
	std::cout << std::endl << "--- 1. pozycja ---" << std::endl;
	pDokument = new COnlineDocument("Regedit", "Cyfrowe przetwarzanie tekstu",
			   "http://programex.risp.pl/?strona=cyfrowe_przetwarzanie_tekstu");
	pDokument->PokazDane();
	delete pDokument;

	// drugi dokument - ksi¹¿ka
	std::cout << std::endl << "--- 2. pozycja ---" << std::endl;
	pDokument = new CBook("Sam Williams", "W obronie wolnosci",
						  "83-7361-247-5");
	pDokument->PokazDane();
	delete pDokument;

	_getch();
}