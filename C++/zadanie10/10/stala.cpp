#include "stala.h"
#include <iostream>

using namespace kalkulator;

// mapa zawieraj¹ca sta³e
std::map<std::string, double> stala::mapaStalych = {
            {"pi", 3.1416},
            {"e", 2.7183}
        };

// konstruktor z lista inicjalizacyjna
stala::stala(std::string nazwa, double wartosc) : wartosc(wartosc), nazwa(nazwa) {}

stala::~stala()
{
    //dtor
}

// ta metoda statyczna pobiera z mapy stalych wartosc dla danej nazwy
double stala::pobierzStala(std::string token)
{
    return stala::mapaStalych.at(token);
}

double stala::pobierzWartosc()
{
    return this->wartosc;
}
