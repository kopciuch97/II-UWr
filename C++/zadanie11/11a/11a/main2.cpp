
#include "FA.h"
using namespace std;

void funkcjaPrzejsc(vector<string>& stany, set<int>& alfabet, string wejscie)
{
	stringstream pamiec;
	string stan = stany[0];

	char poprzedni = '\0';

	char BACKSLASH = '\\';
	char SLASH = '/';
	char APOSTROF = '\'';
	char CUDZYSLOW = '"';
	char GWIAZDKA = '*';
	char NOWA_LINIA = '\n';

	for (char c : wejscie)
	{
		if (alfabet.count(c) == 0)
		{
			throw SymbolNieJestWAlfabecieException();
		}

		// KOD
		if (stan == stany[0])
		{
			// KOD -> LITERAL_NAPISOWY
			if (c == CUDZYSLOW && poprzedni != BACKSLASH && poprzedni != APOSTROF)
			{
				stan = stany[1];
			}
			// KOD -> KOMENTARZ_LINIOWY
			else if (c == SLASH && poprzedni == SLASH)
			{
				stan = stany[2];
			}
			// KOD -> KOMENTARZ_GLOBALNY
			else if (c == GWIAZDKA && poprzedni == SLASH)
			{
				stan = stany[3];
			}
			// KOD -> LITERAL_LICZBOWY
			else if ((c == '.' && poprzedni != '.') || (c >= '0' && c <= '9'))
			{
				stan = stany[4];
			}
		}

		// LITERAL_NAPISOWY
		else if (stan == stany[1])
		{
			// LITERAL_NAPISOWY -> KOD
			if (c == CUDZYSLOW && poprzedni != BACKSLASH && poprzedni != APOSTROF)
			{
				stan = stany[0];
			}
		}
		// KOMENTARZ_LINIOWY
		else if (stan == stany[2])
		{
			// KOD -> KOMENTARZ_LINIOWY
			if (c == NOWA_LINIA)
			{
				stan = stany[0];
			}
		}
		// KOMENTARZ_GLOBALNY
		else if (stan == stany[3])
		{
			// KOD -> KOMENTARZ_GLOBALNY
			if (c == SLASH && poprzedni == GWIAZDKA)
			{
				stan = stany[0];
			}
		}
		// LITERAL_LICZBOWY
		else if (stan == stany[4])
		{
			// LITERAL_LICZBOWY -> KOD
			if (c < '0' || c > '9')
			{
				stan = stany[0];

				string s;
				pamiec >> s;

				if (s.size() > 1 || s[0] != '.')
				{
					cout << s << endl;
				}

				pamiec.str(string());
				pamiec.clear();
			}
		}

		if (stan == stany[4])
		{
			pamiec << c;
		}

		poprzedni = c;
	}
}


int main(int argc, char* argv[])
{
	/*
	(jako KOD traktujemy wszystko co nie jest innego typu)
	*/
	vector<string> stany;
	stany.push_back("KOD");
	stany.push_back("LITERAL_NAPISOWY");
	stany.push_back("KOMENTARZ_LINIOWY");
	stany.push_back("KOMENTARZ_GLOBALNY");
	stany.push_back("LITERAL_LICZBOWY");


	stringstream ss;
	if (argc != 2)
	{
		cout << "Nie podano pliku wejsciowego!";
		return 1;
	}
	// wczytujemy caly plik
	ss << ifstream(argv[1]).rdbuf();
	string wejscie = ss.str();

	// tworzymy alfabet (wszystkie wartosci ASCII)
	set<int> alfabet;
	for (int i = 0; i < 256; i++) alfabet.insert(i);

	try
	{
		// tworzymy obiekt FA
		FA* fa = new FA(stany, alfabet, &funkcjaPrzejsc);
		// i wywolujemy jego metode start
		fa->start(wejscie);
	}
	catch (exception& ex)
	{
		// jesli powstal wyjatek to wypisujemy jest tresc
		cout << ex.what() << endl;
	}
	getchar();
}