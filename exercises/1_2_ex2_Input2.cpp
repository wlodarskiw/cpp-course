// Input2 - zmodyfikowany Input ¿eby pyta³ siê równie¿ o nazwisko

#include <string>
#include <iostream>
#include <conio.h>

using namespace std;

void main()
{
	string strName;

	cout << "Please state your name: ";
	cin >> strName;

	string strSurname;

	cout << "State your surname: ";
	cin >> strSurname;

	cout << "Your name is " << strName << " " << strSurname << "." << endl;

	_getch();
}