#pragma once

#include <iostream>
#include <string>
#include <map>

#include "Produkt.h"

using namespace std;

class Magazyn
{
public:
	map<Produkt, int> produkty;
	Magazyn();
	~Magazyn();

	void dodajProdukt(Produkt produkt, int liczbaSztuk);
	void edytujProdukt(int nr, Produkt produkt, int liczbaSztuk);
	bool czyProduktDostepny(string nazwa, int liczbaSztuk);
	Produkt pobierzProdukt(string nazwa, int liczbaSztuk);
	void wyswietlStan();
};

