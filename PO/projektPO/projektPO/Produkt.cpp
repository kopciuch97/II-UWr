#include "Produkt.h"


Produkt::Produkt()
{
}

Produkt::Produkt(string nazwa, double cena)
{
	this->nazwa = nazwa;
	this->cena = cena;
}

// przeciazony operator przypisania
Produkt& Produkt::operator=(const Produkt& p)
{
	nazwa = p.nazwa;
	cena = p.cena;
	return *this;
}

// przeciazony operator porowywania
bool Produkt::operator<(const Produkt& rhs) const
{
	return nazwa < rhs.nazwa;
}

// przeciazony operator sprawdzania czy dwa produkty sa rowne
bool Produkt::operator==(const Produkt& rhs) const
{
	return nazwa == rhs.nazwa;
}

Produkt::~Produkt()
{
}
