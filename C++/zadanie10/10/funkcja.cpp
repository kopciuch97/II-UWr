#include "funkcja.h"
#include "operand.h"
#include "liczba.h"
#include <math.h>
#define PI 3.1415926535897

//powyzej definiujemy PI, potrzebne do niektorych funkcji
using namespace kalkulator;

// deklarujemy ze bedziemy tu uzywali statycznego stosu z klasy symbol
std::stack<symbol*> symbol::stos;

// deklarujemy mape funkcji - symbole na rodzaj
std::map<std::string, funkcja::rodzaj> funkcja::mapaFunkcji = {
    {"+", f_add},
    {"-", f_sub},
    {"*", f_mul},
    {"/", f_div},
    {"%", f_modulo},
    {"min", f_min},
    {"max", f_max},
    {"log", f_log},
    {"pow", f_pow},
    {"abs", f_abs},
    {"sgn", f_sgn},
    {"floor", f_floor},
    {"ceil", f_ceil},
    {"frac", f_frac},
    {"sin", f_sin},
    {"cos", f_cos},
    {"atan", f_atan},
    {"acot", f_acot},
    {"ln", f_ln},
    {"exp", f_exp}
};

// konstruktor z lista inicjalizacyjna
funkcja::funkcja(rodzaj dzialanie) : dzialanie(dzialanie) {}

funkcja::~funkcja()
{
    //dtor
}

funkcja::rodzaj funkcja::pobierzFunkcje(std::string token)
{
    return funkcja::mapaFunkcji.at(token);
}

// funkcja pomocnicza, ktora pobiera dwie wartosci ze stosu i zwraca je jako pare wartosci
std::pair<double, double> funkcja::popTwo()
{
    // moze rzucic tu wyjatek jesli nie jest to operand, ale to dobrze, bo to znaczy ze dzialanie jdst niepoprawne
    operand* pierwszy = static_cast<operand*>(symbol::stos.top());
    // oczywiscie usuwamy ze stosu po pobraniu
    symbol::stos.pop();
    operand* drugi = static_cast<operand*>(symbol::stos.top());
    symbol::stos.pop();
    return std::pair<double, double>(pierwszy->pobierzWartosc(), drugi->pobierzWartosc());
}

// tak samo jak wyzej, tylko dla funkcji jednoargumentowych
double funkcja::popOne()
{
    operand* pierwszy = static_cast<operand*>(symbol::stos.top());
    symbol::stos.pop();
    return pierwszy->pobierzWartosc();
}

// implementacja metody wirtualnej wykonaj dla funkcji
void funkcja::wykonaj()
{
    // deklarujemy przydatne pozniej zmienne
    std::pair<double, double> wartosci;
    double wartosc;
    double wynik;
    // wykonujemy dzialanie w zaleznosci od jego typu
    switch(this->dzialanie)
    {
        case f_add:
            // pobieramy dwie wartosci ze stosu
            wartosci = popTwo();
            // wykonujemy dzialanie
            wynik = wartosci.first + wartosci.second;
            // wrzucamy na stos wynik
            symbol::stos.push(new liczba(wynik));
            break;
        case f_sub:
            wartosci = popTwo();
            wynik = wartosci.first - wartosci.second;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_mul:
            wartosci = popTwo();
            wynik = wartosci.first * wartosci.second;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_div:
            wartosci = popTwo();
            // w razie gdyby ktos dzielil przez 0
            if (wartosci.second == 0)
                throw std::overflow_error("Zero division");
            wynik = wartosci.first / wartosci.second;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_modulo:
            wartosci = popTwo();
            wynik = fmod(wartosci.first, wartosci.second);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_min:
            wartosci = popTwo();
            wynik = wartosci.first > wartosci.second ? wartosci.first : wartosci.second;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_max:
            wartosci = popTwo();
            wynik = wartosci.first < wartosci.second ? wartosci.first : wartosci.second;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_log:
            wartosci = popTwo();
            wynik = log(wartosci.first)/log(wartosci.second);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_pow:
            wartosci = popTwo();
            wynik = pow(wartosci.first, wartosci.second);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_abs:
            wartosc = popOne();
            wynik = wartosc > 0 ? wartosc : -wartosc;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_sgn:
            wartosc = popOne();
            wynik = wartosc > 0 ? 1 : -1;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_floor:
            wartosc = popOne();
            wynik = floor(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_ceil:
            wartosc = popOne();
            wynik = ceil(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_frac:
            wartosc = popOne();
            wynik = wartosc - trunc(wartosc);
            wynik = wynik > 0 ? wynik : -wynik;
            symbol::stos.push(new liczba(wynik));
            break;
        case f_sin:
            wartosc = popOne();
            wynik = sin(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_cos:
            wartosc = popOne();
            wynik = cos(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_atan:
            wartosc = popOne();
            wynik = atan(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_acot:
            wartosc = popOne();
            wynik = PI/2 - atan(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_ln:
            wartosc = popOne();
            wynik = log(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        case f_exp:
            wartosc = popOne();
            wynik = exp(wartosc);
            symbol::stos.push(new liczba(wynik));
            break;
        default:
            // w razie gdyby token nie pasowal do zadnego
            throw std::invalid_argument("Brak dzialania");
    }
}
