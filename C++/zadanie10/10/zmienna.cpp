#include "zmienna.h"
#include <vector>
#include <algorithm>

using namespace kalkulator;

// deklarujemy uzycie mapy zmiennych
std::map<std::string, double> zmienna::mapaZmiennych;

// wektor zawierajacy slowa niedozwolone jako nazwy zmiennych
std::vector<std::string> wyjatki = {
    "print",
    "assign",
    "clear",
    "exit",
    "to"
};

// konstruktor z lista inicjalizacyjna
zmienna::zmienna(std::string nazwa) : nazwa(nazwa) {}

zmienna::~zmienna()
{
    //dtor
}

// pobieranie zmiennej po nazwie (metoda statyczna)
double zmienna::pobierzZmienna(std::string token)
{
    return zmienna::mapaZmiennych.at(token);
}

// metoda statyczna dodajaca zmienna o danej nazwie
void zmienna::dodajZmienna(std::string token, double wartosc)
{
    // szukamy czy nazwa nie jest niedozwolona
    if (std::find(wyjatki.begin(), wyjatki.end(), token) != wyjatki.end() || token.length() > 7)
    {
        throw std::invalid_argument("Niepoprawna nazwa zmiennej");
    }
    // przypisujemy do mapy - jesli taka zmienna juz istnieje, to zostanie ona nadpisana
    zmienna::mapaZmiennych[token] = wartosc;
}

void zmienna::wyczyscZmienne()
{
    zmienna::mapaZmiennych.clear();
}

// pobieranie zmiennej z obiektu - szukamy w mapie zmiennych po nazwie danej zmiennej
double zmienna::pobierzWartosc()
{
    return zmienna::mapaZmiennych[this->nazwa];
}
