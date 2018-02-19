#pragma once

#include <string>

using namespace std;

class Produkt
{
public:
	string nazwa;
	double cena;


	Produkt();
	
	Produkt(string nazwa, double cena);
	Produkt& operator=(const Produkt& p);
	bool operator<(const Produkt& rhs) const;
	bool operator==(const Produkt& rhs) const;

	// strumieniowy operator wczytywania danych
	friend istream& operator>> (istream& in, Produkt& produkt)
	{
		in >> produkt.nazwa >> produkt.cena;
		return in;
	}

	// strumieniowy operator zapisywania danych
	friend ostream& operator<< (ostream& out, const Produkt& produkt)
	{
		out << produkt.nazwa << " " << produkt.cena;
		return out;
	}

	~Produkt();
};

