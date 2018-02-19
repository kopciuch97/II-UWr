#include "Kontrahent.h"



Kontrahent::Kontrahent()
{
}


// konstruktor
Kontrahent::Kontrahent(string imie, string nazwisko, string NIP)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->NIP = NIP;
}

// przeciazony operator przypisania (kopiuje kolejne pola)
Kontrahent& Kontrahent::operator=(const Kontrahent& k)
{
	imie = k.imie;
	nazwisko = k.nazwisko;
	NIP = k.NIP;
	return *this;
}

Kontrahent::~Kontrahent()
{
}
