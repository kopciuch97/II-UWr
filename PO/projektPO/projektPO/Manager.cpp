#include "Manager.h"



Manager::Manager()
{
}

Manager::Manager(string imie, string nazwisko)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
}

// manager wybiera pracownika do wykonania zlecenia
Pracownik* Manager::wybierzPracownika(vector<Pracownik*> pracownicy)
{
	cout << "Wybierz pracownika:\n";
	int i = 1;
	for (auto const &p : pracownicy)
	{
		cout << i++ << ". " << *p << endl;
	}
	int wybrany;
	cin >> wybrany;

	if (wybrany >= 0 && wybrany < pracownicy.size())
	{
		return pracownicy[wybrany - 1];
	}
	else // jesli wybor nie byl poprawny to zwracamy pierwszego pracownika
	{
		return pracownicy[0];
	}
}

// zatwierdzenie zamowienia przez managera
void Manager::zatwierdzZamowienie(Zamowienie* zamowienie)
{
	zamowienie->zatwierdz();
}

Manager::~Manager()
{
}
