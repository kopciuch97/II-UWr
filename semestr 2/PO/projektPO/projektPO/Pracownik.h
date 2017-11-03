#pragma once

#include <iostream>
#include <string>

#include "Zamowienie.h"
#include "Magazyn.h"

using namespace std;

class Pracownik
{

public:
	string imie;
	string nazwisko;
	Pracownik();
	Pracownik(string imie, string nazwisko);
	~Pracownik();

	Zamowienie* przygotujZamowienie(vector<string> nazwy, vector<int> liczbaSztuk,
		Kontrahent kontrahent, Magazyn* magazyn);

	// strumieniowy operator wczytywania danych
	friend istream& operator>> (istream& in, Pracownik& pracownik)
	{
		in >> pracownik.imie >> pracownik.nazwisko;
		return in;
	}

	// strumieniowy operator zapisywania danych
	friend ostream& operator<< (ostream& out, const Pracownik& pracownik)
	{
		out << pracownik.imie << " " << pracownik.nazwisko;
		return out;
	}
};

