#include "symbol.h"
#include "liczba.h"
#include <stdexcept>

using namespace kalkulator;

symbol::symbol()
{
    //ctor
}

symbol::~symbol()
{
    //dtor
}

// funkcja okreœlaj¹ca ostateczny wynik, czyli ostatni (jedyny) element na stosie
double symbol::ostatecznyWynik()
{
    // Jeœli po wykonaniu wszystkich operacji jest mniej lub wiêcej elementów ni¿ jeden,
    // to znaczy ¿e dzia³anie by³o niepoprawne - rzucamy wyj¹tek
    if (symbol::stos.size() != 1)
        throw std::invalid_argument("Brak dzialania");
    // Rzutujemy ten symbol na liczbê. Jeœli nie jest to liczba, to rzucony zostanie wyj¹tek
    double wynik = static_cast<liczba*>(symbol::stos.top())->pobierzWartosc();
    // usuwamy ten element i zwracamy wynik
    stos.pop();
    return wynik;
}
