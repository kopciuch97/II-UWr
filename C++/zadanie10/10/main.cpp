#include <iostream>
#include "zmienna.h"
#include "stala.h"
#include "liczba.h"
#include <ctype.h>
#include "funkcja.h"
#include <vector>
#include <memory>

using namespace std;
using namespace kalkulator;

// wykonanie komendy print, ktora zwraca wartosc wyrazenia po przejsciu przez kalkulator
double komenda_print(string wyrazenie)
{
    // wektor inteligentnych wskaznikow do symboli napotkanych przy przechodzeniu przez wyrazenie
    // dzieki inteligentnym wskaznikom nie musismy martwic sie zwalnianiem pamieci
    vector<shared_ptr<symbol>> wektor;

    // poczatkowy index na 0
    int index = 0;
    int koniec;
    // szukamy symboli
    do
    {
        // koniec nastepnego symbolu (sa one oddzielone spacja)
        koniec = wyrazenie.find(' ', index);
        // pobeiramy ten symbol
        string token = wyrazenie.substr(index, koniec-index);
        // ustawiamy index na poczatek koljenego ewentualnego symbolu
        index += token.length()+1;

        // jesli pierwszy element symbolu jest cyfra lub znak minus, to przyjmujemy ze to liczba
        if (isdigit(token.at(0)) || token.at(0) == '-')
        {
            // jesli w symbolu sa tez jakies litery, to przy rzutowaniu bedziemy mieli wyjatek
            int wartosc = stoi(token);
            shared_ptr<symbol> s;
            s.reset(new liczba(wartosc));
            // wrzucamy to wartosc do wektora symboli
            wektor.push_back(s);
        } else
        {
            // w przeciwnym wypadku sprawdzamy czy jest to zmienna, stala lub funkcja
            bool znaleziono = false;

            try
            {
                // probujemy pobrac zmienna po jej nazwie - jesli nie to rzuca wyjatek i sprawdza dalej
                double wartosc = zmienna::pobierzZmienna(token);
                shared_ptr<symbol> s;
                s.reset(new zmienna(token));
                wektor.push_back(s);
                znaleziono = true;
            } catch (out_of_range) {}

            // jesli w poprzednim szukaniu nie znalezlismy, to probujemy wsrod stalych (analogicznie)
            if (!znaleziono)
            try
            {
                double wartosc = stala::pobierzStala(token);
                shared_ptr<symbol> s;
                s.reset(new stala(token, wartosc));
                wektor.push_back(s);
                znaleziono = true;
            } catch (out_of_range) {}

            // na koniec sprawdzamy czy jest to funkcja
            if (!znaleziono)
            try
            {
                funkcja::rodzaj rodzajFunkcji = funkcja::pobierzFunkcje(token);
                shared_ptr<symbol> s;
                s.reset(new funkcja(rodzajFunkcji));
                wektor.push_back(s);
            } catch (out_of_range)
            {
                // tym razem jesli nie jest to funkcja, to znaczy ze ktos podal zle wyrazenie
                clog << "Nieznany symbol!" << endl;
                throw std::invalid_argument("Blad w symbolu");
            }
        }
        // koneic przyjmuje wartosc -1 gdy dojdzie do konca ( nie bedzie wiecej symboli )
    } while (koniec != -1);


    // Teraz gdy mamy symbole w wektorze, to po kolei wywolujemy na nich metode wykonaj().
    // Poniewaz symbole maja rozne implementacje tej metody czysto wirtualnej, to dla kazdego
    // zostanie wywolana odpowiednia
    for (auto it = wektor.begin(); it != wektor.end(); it++)
    {
        it->get()->wykonaj();
    }

    // teraz sprawdzamy ostateczna wartosc ktora zostala na stosie (lub inaczej zostanie rzucony wyjatek)
    double ostatecznyWynik = symbol::ostatecznyWynik();
    return ostatecznyWynik;
}

void komenda_assign(string wyrazenie, string zmienna)
{
    try
    {
        // wykonujemy najpierw komende print, bo ona zwraca wartosc wyrazenia. Dzieki temu mozemy przypisac cale wyrazenie do zmiennej
        double wynik = komenda_print(wyrazenie);
        zmienna::dodajZmienna(zmienna, wynik);
    } catch (invalid_argument)
    {
        clog << "Niepoprawna nazwa zmiennej - nie moze zawierac slow kluczowych oraz powinna miec maksymalnie 7 znakow" << endl;
    }
}

void komenda_clear()
{
    zmienna::wyczyscZmienne();
}

// metoda glowna
int main()
{
    // petla w ktorej dziala kalkulator
    while (true)
    {
        cout << "Kalkulator ONP. Wprowadz komende." << endl;
        string komenda;
        // pobieramy komende od uzytkownika
        getline(cin, komenda);
        // blok try-catch w razie gdyby uzytkownik podal zle dane
        try
        {
            // szukamy miejsca w ktorym wystepuje spacja w komendzie
            int miejscePodzialu = komenda.find(' ');
            // bierzemy wartosc lewej od spacji
            string pierwszyElement = komenda.substr(0, miejscePodzialu);
            // jesli pierwszyElement == 'print', to:
            if (pierwszyElement == "print")
            {
                // jesli miejscePodzialu == -1 to oznacza ze jest tylko jedno slowo w komendzie,
                // wiec komenda print nie jest kompletna
                if (miejscePodzialu == -1)
                {
                    clog << "Komenda 'print' powinna zawierac prawidlowe wyrazenie!" << endl;
                    continue;
                }
                // w przeciwnym wypadku pobieramy reszte zdania i przekazujemy do funkcji ktora wykonuje
                // komende print
                double wynik = komenda_print(komenda.substr(6, komenda.length()));
                // nastepnie wypisujemy wynik
                cout << wynik << endl;
            } else if (pierwszyElement == "assign")
            {
                // analogicznie tutaj, tylko mamy wiecej czlonow do zbadania
                if (miejscePodzialu == -1)
                {
                    clog << "Komenda 'print' powinna zawierac prawidlowe wyrazenie!" << endl;
                    continue;
                }
                string reszta = komenda.substr(7, komenda.length());
                miejscePodzialu = reszta.find(" to ");
                if (miejscePodzialu == -1)
                {
                    clog << "Niekompletna komenda!" << endl;
                    continue;
                }
                string wyrazenie = reszta.substr(0, miejscePodzialu);
                string zmienna = reszta.substr(miejscePodzialu + 4, reszta.length());
                komenda_assign(wyrazenie, zmienna);
                cout << "Przypisano" << endl;
            } else if (pierwszyElement == "clear")
            {
                // to samo
                komenda_clear();
                cout << "Wyczyszczono zmienne" << endl;
            } else if (pierwszyElement == "exit")
            {
                // to samo
                cout << "Koniec programu" << endl;
                break;
            } else
            {
                // jesli nie pasuje do komendy, to dajemy blad
                clog << "Nieprawidlowa komenda!" << endl;
            }
        }
        // lapiemy tu wszystkie wyjatki i wypisujemy ze wyrazenie jest bledne
        catch(...)
        {
            clog << "Blad w wyrazeniu!" << endl;
        }
    }
}
