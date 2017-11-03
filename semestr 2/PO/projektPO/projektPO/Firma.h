#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

#include "Manager.h"
#include "Pracownik.h"
#include "Magazyn.h"
#include "Zamowienie.h"

using namespace std;

class Firma
{
private:
	// firma na managera, pracownikow oraz magazyn na ktorym sa produkty
	Manager* manager;
	Magazyn* magazyn;
	vector<Pracownik*> pracownicy;
public:
	Firma();
	~Firma();

	void importuj();
	void eksportuj();
	void wyswietlDostepneProdukty();
	void wyswietlPracownikow();
	void dodajPracownika(string imie, string nazwisko);
	void dodajProdukt(string nazwa, double cena, int liczbaSztuk);
	void edytujPracownika(int nr, string imie, string nazwisko);
	void edytujProdukt(int nr, string nazwa, double cena, int liczbaSztuk);
	Zamowienie* utworzZamowienie(vector<string> nazwy, vector<int> liczbaSztuk, Kontrahent kontrahent);
};

