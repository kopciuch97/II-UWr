#pragma once

#include "Pracownik.h"

#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

class Manager
{
private:
	string imie;
	string nazwisko;
public:

	Manager();
	Manager(string imie, string nazwisko);
	~Manager();

	Pracownik* wybierzPracownika(vector<Pracownik*> pracownicy);
	void zatwierdzZamowienie(Zamowienie* zamowienie);

	// strumieniowy operator wczytywania danych
	friend istream& operator>> (istream& in, Manager& manager)
	{
		in >> manager.imie >> manager.nazwisko;
		return in;
	}

	// strumieniowy operator zapisywania danych
	friend ostream& operator<< (ostream& out, const Manager& manager)
	{
		out << manager.imie << " " << manager.nazwisko;
		return out;
	}
};

