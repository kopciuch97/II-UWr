#ifndef SYMBOL_H
#define SYMBOL_H

#include <stack>

namespace kalkulator
{
    // klasa abstrakcyjna określająca symbole dostępne w kalkulatorze (operandy, funkcje)
    class symbol
    {
        public:
            static double ostatecznyWynik();

            symbol();
            virtual ~symbol();
            // metoda czysto wirtualna. Ma ona za zadanie wykonać działanie specyficzne dla danego symbolu
            // np, odłożenie na stosie dla liczby czy pobranie elementów, wykonanie działania i odłożenie
            // wyniku na stosie dla funkcji. Dzięki temu że jest wirtualna, będziemy mogli korzystać z faktu,
            // że stos zawiera symbole i na każdym wywołamy tą samą funkcję, ale jej działanie będzie inne
            virtual void wykonaj() = 0;

        protected:
            // statyczny stos, na którym oparte jest działanie
            // kalkulatora. Dostep protected, poniewaz klasy pochodne beda z niego korzystac
            static std::stack<symbol*> stos;
        private:
    };
}

#endif // SYMBOL_H
