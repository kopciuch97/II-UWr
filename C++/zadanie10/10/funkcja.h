#ifndef FUNKCJA_H
#define FUNKCJA_H

#include "symbol.h"
#include <map>

namespace kalkulator
{
    class funkcja : public symbol
    {
        public:

            //typ wyliczeniowy (dziala jak int tylko mamy wygodne nazwy)
            enum rodzaj
            {
                // f_ dodane przed nazwa, bo czasem nazwy zachodzily na te uzywane w bibliotece
                // matematycznej.
                f_add = 0,
                f_sub = 1,
                f_mul = 2,
                f_div = 3,
                f_modulo = 4,
                f_min = 5,
                f_max = 6,
                f_log = 7,
                f_pow = 8,
                f_abs = 9,
                f_sgn = 10,
                f_floor = 11,
                f_ceil = 12,
                f_frac = 13,
                f_sin = 14,
                f_cos = 15,
                f_atan = 16,
                f_acot = 17,
                f_ln = 18,
                f_exp = 19
            };

            // deklarujemy zmienna typu powyzszego enuma. Bedzie to rodzaj naszej funkcji
            funkcja::rodzaj dzialanie;

            // funkcja statyczna pobierajaca funkcje po jej symbolu
            static funkcja::rodzaj pobierzFunkcje(std::string);
            funkcja(rodzaj);
            virtual ~funkcja();
            // deklaracja implementacji metody wirtualnej wykonaj
            void wykonaj();

        protected:

        private:
            // metody pomocnicze dla funkcji jedno- i dwuargumentowych
            std::pair<double, double> popTwo();
            double popOne();
            // mapa zawierajaca funkcje przypisane ich symbolom
            static std::map<std::string, rodzaj> mapaFunkcji;
    };
}

#endif // FUNKCJA_H
