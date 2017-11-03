#ifndef OPERAND_H
#define OPERAND_H

#include "symbol.h"

namespace kalkulator
{
    // klasa abstrakcyjna, która okreœla operandy (liczby, sta³e, zmienne)
    class operand : public symbol
    {
        public:
            operand();
            virtual ~operand();
            // metoda czysto wirtualna, która ma za zadanie pobraæ wartoœæ z operandu,
            // dziêki temu mo¿emy traktowaæ operandy t¹ metod¹ i otrzymaæ w³aœciw¹ wartoœæ
            // niezale¿nie czy mamy do czynienia z liczb¹, zmienn¹ czy sta³¹
            virtual double pobierzWartosc() = 0;
            // deklarujemy implementacjê metody wirtualnej wykonaj() z klasy symbol.
            void wykonaj();

        protected:

        private:
    };
}

#endif // OPERAND_H
