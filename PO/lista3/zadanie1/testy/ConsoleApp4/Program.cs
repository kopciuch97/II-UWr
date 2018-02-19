using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Lista3;

namespace zadanie1
{
    class Testy
    {
        static void Main(string[] args)
        {
            Lista<int> obiekt = new Lista<int>();
            Console.WriteLine("TEST\n");
            Console.WriteLine("\nWynik wywołania IsEmpty dla pustej:");
            Console.WriteLine(obiekt.IsEmpty());
            Console.WriteLine("\nDodajemy 7 na koniec: ");
            obiekt.AppEnd(7);
            obiekt.ShowNodes();
            Console.WriteLine("\nDodajemy 3 na koniec: ");
            obiekt.AppEnd(3);
            obiekt.ShowNodes();
            Console.WriteLine("\nDodajemy 1 na początek: ");
            obiekt.AppStart(1);
            obiekt.ShowNodes();
            Console.WriteLine("\nDodajemy 4 na koniec: ");
            obiekt.AppEnd(5);
            obiekt.ShowNodes();
            Console.WriteLine("\nCała lista:\n");
            obiekt.ShowNodes();
            Console.WriteLine("\nWynik wywołania IsEmpty niepustej:");
            Console.WriteLine(obiekt.IsEmpty());
            Console.WriteLine("\nUsuwamy 1:\n");
            Console.WriteLine(obiekt.DelStart() + "\n");
            Console.WriteLine("Nowa lista:\n");
            obiekt.ShowNodes();
            Console.WriteLine("\nUsuwamy 5:\n");
            Console.WriteLine(obiekt.DelEnd()+"\n");
            Console.WriteLine("Nowa lista:\n");
            obiekt.ShowNodes();
            Console.ReadLine();
        }
    }
}
