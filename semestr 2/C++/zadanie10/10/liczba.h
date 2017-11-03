#ifndef LICZBA_H
#define LICZBA_H

#include "operand.h"

namespace kalkulator
{
    // klasa okreœlaj¹ca zwyk³¹ liczbê w dzia³aniu
    class liczba : public operand
    {
        public:
            const double wartosc;
            liczba(double wartosc);
            virtual ~liczba();
            // deklaracja implementacji metody wirtualnej z klasy operand
            double pobierzWartosc();

        protected:

        private:
    };
}


#endif // LICZBA_H
