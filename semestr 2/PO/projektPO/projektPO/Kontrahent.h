#pragma once
#include <string>

using namespace std;

class Kontrahent
{
public:
	string imie;
	string nazwisko;
	string NIP;

	Kontrahent();
	Kontrahent(string imie, string nazwisko, string NIP);
	Kontrahent& operator=(const Kontrahent& k);
	~Kontrahent();
};

