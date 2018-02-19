#include "liczba.h"
#include <iostream>

using namespace kalkulator;

// konstruktor z list¹ inicjalizacyjn¹
liczba::liczba(double wartosc) : wartosc(wartosc) {}

liczba::~liczba()
{
    //dtor
}

// dla tej klasy pobranie wartoœci to po prostu zwrócenie tej, któr¹ zawiera
double liczba::pobierzWartosc()
{
    return this->wartosc;
}
