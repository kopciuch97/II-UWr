using System;
using System.Collections.Generic;

namespace Zadanie4 {
    class LeniwaLista {
        public int length;
        public List<int> L;
        public Random n;

        public LeniwaLista() {
            length = 0;
            L = new List<int>();
            n = new Random();
        }

        public int size() {
            return length;
        }

        public virtual int nastepna(int n) {
            return this.n.Next();
        }

        public int element(int n) {
            if (n < length) return L[n];
            else {
                length = n;

                if (L.Count == 0) L.Add(0);

                for (int i = L.Count - 1; i < n; i++) {
                    L.Add(nastepna(L[i]));
                }

                return L[n];
            }
        }

        public void wypisz() {
            System.Console.WriteLine("Rozmiar listy to " + length);
        }

    }
}