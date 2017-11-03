#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;
using namespace std::chrono;

class osoba
{
public:
	string imie;
	string nazwisko;
	system_clock::time_point ur;

	osoba(string imie, string nazwisko, system_clock::time_point ur)
	{
		this->imie = imie;
		this->nazwisko = nazwisko;
		this->ur = ur;
	}
	osoba(const osoba& o)
	{
		this->imie = o.imie;
		this->nazwisko = o.nazwisko;
		this->ur = o.ur;
	}

	osoba& operator=(const osoba& o)
	{
		this->imie = o.imie;
		this->nazwisko = o.nazwisko;
		this->ur = o.ur;
		return *this;
	}

	friend ostream &operator<<(ostream &output, const osoba &o)
	{
		auto tp = system_clock::to_time_t(o.ur);
		//time_t t = system_clock::to_time_t(o.ur);
		output << o.imie << " " << o.nazwisko << ", ur: " << asctime(std::gmtime(&tp));
		return output;
	}
};

int main()
{
	vector<osoba> osoby;
	ifstream f("plik.txt");
	string imie, nazwisko;
	int n;
	f >> n;

	

	mt19937 rng(time(0)); // genrator Mersenne-Twister

	// ponizsze liczby to ile sekund uplynelo od punktu Unix epoch
	// dla dat 01.09.1939
	// oraz 31.05.2017
	// losujemy liczbe z tego przedzialu i w ten sposob otrzymamy losowa
	// liczbe z zakresu tych dat
	uniform_int_distribution<int64_t> uni(-97761600000000, 1496188800000000);


	system_clock::time_point t = system_clock::now();
	t -= t.time_since_epoch();

	for (int i = 0; i < n; i++)
	{
		f >> imie >> nazwisko;
		
		// imie i nazwisko z pliku
		// a data urodzenia losowa z przedzialu
		osoba o(imie, nazwisko, t += system_clock::duration(uni(rng)));
		osoby.push_back(o);
	}

	cout << "Poczatkowa lista:\n";
	for (auto osoba : osoby)
	{
		cout << osoba;
	}

	std::sort(osoby.begin(), osoby.end(),
		[](const osoba& a, const osoba& b) -> bool
	{
		if (a.nazwisko == b.nazwisko)
		{
			return a.imie.compare(b.imie) < 0;
		}
		else
		{
			return a.nazwisko.compare(b.nazwisko) < 0;
		}
	});

	cout << "\nPosortowane po nazwisku i imieniu:\n";
	for (auto osoba : osoby)
	{
		cout << osoba;
	}

	std::sort(osoby.begin(), osoby.end(),
		[](const osoba& a, const osoba& b) -> bool
	{
		return a.ur.time_since_epoch() < b.ur.time_since_epoch();
	});

	cout << "\nPosortowane po dacie urodzenia:\n";
	for (auto osoba : osoby)
	{
		cout << osoba;
	}

	getchar();
}