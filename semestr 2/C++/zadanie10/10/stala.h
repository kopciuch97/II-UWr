#ifndef STALA_H
#define STALA_H

#include "operand.h"
#include <string>
#include <map>

namespace kalkulator
{
    // klasa reprezentujaca stale wbudowane w program
    class stala : public operand
    {
        public:
            // ka¿dy obiekt sta³ej ma swoj¹ nazwê (pi, e)
            const std::string nazwa;
            // i wartosc
            const double wartosc;

            // metoda statyczna, ktorej zadaniem jest pobranie wartosci stalej
            // po jej nazwie
            static double pobierzStala(std::string token);
            stala(std::string, double);
            virtual ~stala();
            // deklaracja implementacji metody pobierajacej wartosc
            double pobierzWartosc();

        protected:

        private:
            // statyczna mapa, ktora zawiera wszystkie stale dostepne w kalkulatorze
            static std::map<std::string, double> mapaStalych;
    };
}


#endif // STALA_H
