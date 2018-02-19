#include "Pracownik.h"



Pracownik::Pracownik()
{
}

Pracownik::Pracownik(string imie, string nazwisko)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
}

// przygotowanie zamowienia przez pracownika
Zamowienie* Pracownik::przygotujZamowienie(vector<string> nazwy, vector<int> liczbaSztuk,
	Kontrahent kontrahent, Magazyn* magazyn)
{
	cout << "Zamowienie jest przygotowywane przez: " << imie << " " + nazwisko << endl;

	vector<Produkt> produkty;

	for (unsigned i = 0; i < nazwy.size(); i++)
	{
		if (magazyn->czyProduktDostepny(nazwy[i], liczbaSztuk[i]))
		{
			// jesli tak to produkt jest pobierany
			Produkt produkt = magazyn->pobierzProdukt(nazwy[i], liczbaSztuk[i]);
			produkty.push_back(produkt);
		}
	}

	return new Zamowienie(produkty, liczbaSztuk, kontrahent);
}

Pracownik::~Pracownik()
{
}
