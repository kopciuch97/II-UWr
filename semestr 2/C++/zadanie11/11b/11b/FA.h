#pragma once
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "SymbolNieJestWAlfabecieException.h"

class FA
{
private:
	// zbior stanow
	vector<string> stany;

	// uzywany alfabet
	set<int> alfabet;

	// wskaznik na funkcje przejsc
	void(*funkcjaPrzejsc) (vector<string>& s, set<int>& a, string wejscie);
public:
	// konstruktor przyjmujacy zbior stanow, alfabet oraz
	// wskaznik na funkcje przejsc
	FA(vector<string>& stany, set<int>& alfabet, void(*funkcjaPrzejsc) (vector<string>& s, set<int>& a, string w));
	void start(string wejscie);
};

