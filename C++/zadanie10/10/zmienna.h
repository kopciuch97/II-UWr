#ifndef ZMIENNA_H
#define ZMIENNA_H

#include "operand.h"
#include <string>
#include <map>

namespace kalkulator
{
    // klasa reprezentujaca zmienne, ktore mozna dodawac, zmieniac i usuwac
    class zmienna : public operand
    {
        public:
            // nazwa zmiennej
            const std::string nazwa;

            // statyczna metoda, ktora pobiera wartosc zmiennej po jej nazwie
            static double pobierzZmienna(std::string);
            // metoda statyczna dodajaca zmienna do mapy zmiennych
            static void dodajZmienna(std::string, double);
            // metoda statyczna usuwajaca wszystkie zmienne
            static void wyczyscZmienne();
            zmienna(std::string);
            virtual ~zmienna();
            // deklaracja implementacji metody wirtualnej do pobierania wartosci z obiektu zmiennej
            double pobierzWartosc();

        private:
            // statyczna mapa zawierajaca wszystkie zmienne dostepne w programie
            static std::map<std::string, double> mapaZmiennych;
    };
}

#endif // ZMIENNA_H
