using System;

namespace Zadanie1 {
    class Testy {
        public static void Main(string[] args) {

            System.Console.WriteLine("\nIntStream");
            IntStream inst = new IntStream();
            System.Console.WriteLine(inst.nastepny());
            System.Console.WriteLine(inst.nastepny());
            System.Console.WriteLine(inst.nastepny());
            System.Console.WriteLine(inst.eos());
            inst.reset();
            System.Console.WriteLine(inst.nastepny());

            System.Console.WriteLine("\nPrimeStream");
            PrimeStream ps = new PrimeStream();
            System.Console.WriteLine(ps.nastepny());
            System.Console.WriteLine(ps.nastepny());
            System.Console.WriteLine(ps.nastepny());
            System.Console.WriteLine(ps.eos());
            ps.reset();
            System.Console.WriteLine(ps.nastepny());

            System.Console.WriteLine("\nRandomStream");
            RandomStream rs = new RandomStream();
            System.Console.WriteLine(rs.nastepny());
            System.Console.WriteLine(rs.nastepny());
            System.Console.WriteLine(rs.nastepny());
            System.Console.WriteLine(rs.eos());
            rs.reset();
            System.Console.WriteLine(rs.nastepny());

            System.Console.WriteLine("\nRandomWordStream");
            RandomWordStream rws = new RandomWordStream();
            System.Console.WriteLine(rws.next());
            System.Console.WriteLine(rws.next());
            System.Console.WriteLine(rws.next());
            System.Console.WriteLine(rws.eos());
            rws.reset();
            System.Console.WriteLine(rws.next());
            Console.ReadKey();
        }

    }
}