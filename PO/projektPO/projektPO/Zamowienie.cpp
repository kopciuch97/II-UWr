#include "Zamowienie.h"

Zamowienie::Zamowienie()
{
}


Zamowienie::~Zamowienie()
{
}

Zamowienie::Zamowienie(vector<Produkt> produkty, vector<int> liczbaSztuk, Kontrahent kontrahent)
{
	this->produkty = produkty;
	this->liczbaSztuk = liczbaSztuk;
	this->kontrahent = kontrahent;
	this->zatwierdzone = false;
}
// zatwierdzenie zamowienia
void Zamowienie::zatwierdz()
{
	zatwierdzone = true;
}

double Zamowienie::obliczKwoteNetto()
{
	double kwota = 0;
	for (unsigned i = 0; i < produkty.size(); i++)	
	{
		kwota += produkty[i].cena * liczbaSztuk[i];
	}
	return kwota;
}

double Zamowienie::obliczKwoteBrutto()
{
	return obliczKwoteNetto() + obliczPodatekVAT();
}

double Zamowienie::obliczPodatekVAT()
{
	return obliczKwoteNetto() * 0.23;
}

// wyswietlenie faktury VAT
void  Zamowienie::wyswietlFakture()
{
	cout << "---------------------------------------------\n";
	cout << "FAKTURA VAT" << endl;
	cout << "Dane kontrahenta: " << kontrahent.imie << " " << kontrahent.nazwisko << "\n";
	cout << "NIP: " << kontrahent.NIP << "\n";
	cout << "Produkty:" << endl;
	int i = 1;
	for (unsigned i = 0; i < produkty.size(); i++)
	{
		cout << i + 1 << ". " << produkty[i].nazwa << 
			", cena: " <<produkty[i].cena <<
			", sztuk: " << liczbaSztuk[i] << endl;
	}
	cout << "Kwota netto: \t" << obliczKwoteNetto() << endl;
	cout << "Podatek VAT: \t" << obliczPodatekVAT() << endl;
	cout << "Kwota brutto: \t" << obliczKwoteBrutto() << endl;
	cout << "---------------------------------------------\n";
}
