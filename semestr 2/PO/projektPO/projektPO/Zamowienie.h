#pragma once

#include <iostream>
#include <vector>

#include "Produkt.h"
#include "Kontrahent.h"

using namespace std;

class Zamowienie
{
private:
	vector<Produkt> produkty;
	vector<int> liczbaSztuk;
	Kontrahent kontrahent;
	bool zatwierdzone;
public:
	Zamowienie();
	Zamowienie(vector<Produkt> produkty, vector<int> liczbaSztuk, Kontrahent kontrahent);
	~Zamowienie();

	void zatwierdz();
	double obliczKwoteNetto();
	double obliczKwoteBrutto();
	double obliczPodatekVAT();
	void  wyswietlFakture();
};

