using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Zadanie4 {
    class Testy {
        static void Main(string[] args) {
            Console.WriteLine("\nListaLeniwa :\n");
            LeniwaLista L1 = new LeniwaLista();
            L1.wypisz();
            Console.WriteLine("5 element listy to " + L1.element(5));
            L1.wypisz();
            Console.WriteLine("10 element listy to " + L1.element(10));
            L1.wypisz();
            Console.WriteLine("2 element listy to " + L1.element(2));
            L1.wypisz();
            Console.WriteLine("100 element listy to " + L1.element(100));
            L1.wypisz();

            Console.WriteLine("\nLeniwePierwsze :\n");
            LeniwePierwsze L2 = new LeniwePierwsze();
            L2.wypisz();
            Console.WriteLine("5 element listy to " + L2.element(5));
            L2.wypisz();
            Console.WriteLine("10 element listy to " + L2.element(10));
            L2.wypisz();
            Console.WriteLine("2 element listy to " + L2.element(2));
            L2.wypisz();
            Console.WriteLine("100 element listy to " + L2.element(100));
            L2.wypisz();

            Console.ReadKey();
        }

    }
}
