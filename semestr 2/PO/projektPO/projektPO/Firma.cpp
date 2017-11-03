#include "Firma.h"

Firma::Firma()
{
	manager = new Manager();
	magazyn = new Magazyn();
}


Firma::~Firma()
{
}

// import danych z pliku tekstowego
void Firma::importuj()
{
	ifstream f("firma.txt");
	string linia;
	string imie, nazwisko;
	int n;
	string nazwa;
	int liczbaSztuk;

	// wczytanie managera
	getline(f, linia);
	stringstream ss(linia);
	ss >> *manager;

	// wczytanie liczby pracownikow
	getline(f, linia);
	ss.clear();
	ss.str(linia);
	ss >> n;

	// wczytanie kolejnych pracownikow
	for (int i = 0; i < n; i++)
	{
		getline(f, linia);
		ss.clear();
		ss.str(linia);
		Pracownik* pracownik = new Pracownik();
		ss >> *pracownik;
		pracownicy.push_back(pracownik);
	}

	// wczytanie liczby produktow
	getline(f, linia);
	ss.clear();
	ss.str(linia);
	ss >> n;

	// wczytanie kolejncych produktow
	for (int i = 0; i < n; i++)
	{
		getline(f, linia);
		ss.clear();
		ss.str(linia);
		Produkt produkt;
		ss >> produkt;
		ss >> liczbaSztuk;
		magazyn->dodajProdukt(produkt, liczbaSztuk);
	}

	f.close();
}

// eksport do pliku tekstowego
void Firma::eksportuj()
{
	ofstream f("firma.txt");
	// zapisujemy managera
	f << *manager << endl;
	// zapisujemy liczbe pracownikow
	f << pracownicy.size() << endl;
	// zapisujemy kolejnych pracownikow
	for (unsigned i = 0; i < pracownicy.size(); i++)
	{
		f << *pracownicy[i] << endl;
	}
	// zapisujemy liczbe produktow
	f << magazyn->produkty.size() << endl;

	// zapisujemy kolejne produkty
	for (auto const &e : magazyn->produkty)
	{
		f << e.first << " " << e.second << endl;
	}
}

void Firma::wyswietlDostepneProdukty()
{
	magazyn->wyswietlStan();
}

void Firma::wyswietlPracownikow()
{
	int i = 1;
	for (auto const &p : pracownicy)
	{
		cout << i++ << ". " << *p << endl;	
	}
}

Zamowienie* Firma::utworzZamowienie(vector<string> nazwy, vector<int> liczbaSztuk, Kontrahent kontrahent)
{
	// Manager wybiera pracownika ktora ma sie zajac zamowieniem
	Pracownik* pracownik = manager->wybierzPracownika(pracownicy);
	// pracownik przygotowuje zamowienie
	Zamowienie* zamowienie = pracownik->przygotujZamowienie(nazwy, liczbaSztuk, kontrahent, magazyn);

	// manager zatwierdza zamowienie
	manager->zatwierdzZamowienie(zamowienie);
	// i wyswietlona jest utworzona faktura
	zamowienie->wyswietlFakture();
	return zamowienie;
}

void Firma::dodajPracownika(string imie, string nazwisko)
{
	pracownicy.push_back(new Pracownik(imie, nazwisko));
}

void Firma::dodajProdukt(string nazwa, double cena, int liczbaSztuk)
{
	magazyn->dodajProdukt(Produkt(nazwa, cena), liczbaSztuk);
}

void Firma::edytujPracownika(int nr, string imie, string nazwisko)
{
	if (nr >= 0 && nr < pracownicy.size())
	{
		pracownicy[nr] = new Pracownik(imie, nazwisko);
	}
}

void Firma::edytujProdukt(int nr, string nazwa, double cena, int liczbaSztuk)
{
	magazyn->edytujProdukt(nr, Produkt(nazwa, cena), liczbaSztuk);
}