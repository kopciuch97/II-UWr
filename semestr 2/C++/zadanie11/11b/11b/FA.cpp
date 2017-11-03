#include "FA.h"

// konstruktor przyjmujacy zbior stanow, alfabet oraz
// wskaznik na funkcje przejsc
FA::FA(vector<string>& stany, set<int>& alfabet, void(*funkcjaPrzejsc) (vector<string>& s, set<int>& a, string w))
{
	this->stany = stany;
	this->alfabet = alfabet;
	this->funkcjaPrzejsc = funkcjaPrzejsc;
}
void FA::start(string wejscie)
{
	// wywolujemy funkcje przejsc
	this->funkcjaPrzejsc(stany, alfabet, wejscie);
}