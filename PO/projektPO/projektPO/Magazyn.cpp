#include "Magazyn.h"

Magazyn::Magazyn()
{
}


Magazyn::~Magazyn()
{
}

// dodaje produkt do magazynu
void Magazyn::dodajProdukt(Produkt produkt, int liczbaSztuk)
{
	produkty[produkt] = liczbaSztuk;
}

void Magazyn::edytujProdukt(int nr, Produkt produkt, int liczbaSztuk)
{
	int i = 0;
	for (map<Produkt, int>::iterator it = produkty.begin(); it != produkty.end(); it++)
	{
		if (i == nr)
		{
			cout << produkty.size() << endl;
			produkty.erase(it);
			cout << produkty.size() << endl;
			break;
		}
		i++;
	}
	produkty[produkt] = liczbaSztuk;
}

bool Magazyn::czyProduktDostepny(string nazwa, int liczbaSztuk)
{
	// iteruje po wszystkich produktach i sprawdza czy jest on dostepny
	for (map<Produkt, int>::iterator it = produkty.begin(); it != produkty.end(); it++)
	{
		if (it->first.nazwa == nazwa &&  it->second >= liczbaSztuk)
		{
			return true;
		}
	}
	return false;
}

// pobiera produkt z magazynu
Produkt Magazyn::pobierzProdukt(string nazwa, int liczbaSztuk)
{
	for (auto &&e : produkty)
	{
		if (e.first.nazwa == nazwa)
		{
			e.second -= liczbaSztuk; // aktualizuje liczbe sztuk
			return e.first; // zwraca produkt
		}
	}
	return Produkt();
}

// wyswietla stan magazynu
void Magazyn::wyswietlStan()
{
	int i = 1;
	for (auto const &e : produkty)
	{
		cout << i++ << ". " << e.first.nazwa << ", cena: " << e.first.cena << ", sztuk: " << e.second << endl;
	}
}
