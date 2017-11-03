using System;
using System.Collections;

namespace Zadanie2
{
    public class Primes : IEnumerator
    {
        private int licznik;

        private bool PrimeCheck(int n) //sprawdzamy czy jest pierwsza
        {
            if (n < 2) return false;

            for (int i = 2; i < n - 1; i++)
            {
                if (n % i == 0) return false;
            }

            return true;
            }

        public Primes()  //konstruktor
        {
            licznik = 1;
        }

        public bool MoveNext() //nastepny element kolekcji, az do max value inta
        {
            licznik++;
            while (!PrimeCheck(licznik)) licznik++;
            return licznik < int.MaxValue;
        }

        public void Reset() //ustawia licznik na 1 (reset)
        {
            licznik = 1;
        }

        public object Current //pobiera biezacy element kolekcji
        {
            get
            {
                return licznik;
            }
        }
    }


    class PrimeCollection : IEnumerable
    {
        public IEnumerator GetEnumerator()
        {
            return new Primes();
        }
    }
}