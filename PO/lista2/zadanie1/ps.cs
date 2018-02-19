using System;
namespace Zadanie1 {

    public class PrimeStream : IntStream {

        public bool prime(int x) {
            if (x < 2)
                return false;
            for(int i=2; i<=Math.Sqrt(x) && i<int.MaxValue; i++) {
                if (x % i == 0)
                    return false;
            }
            return true;
        }

        public override int nastepny() {
            if (poprzedni == int.MaxValue)
                return -1;
            poprzedni += 1;
            while(!prime(poprzedni) && poprzedni < int.MaxValue)
                poprzedni += 1;
            if (poprzedni == int.MaxValue)
                return -1;
            else
                return poprzedni;
        }
    }   
}