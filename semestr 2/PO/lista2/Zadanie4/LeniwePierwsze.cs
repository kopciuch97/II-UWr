using System;

namespace Zadanie4{
    class LeniwePierwsze: LeniwaLista {

        public bool prime(int x) {
            if (x < 2)
                return false;
            for (int i = 2; i <= Math.Sqrt(x) && i < int.MaxValue; i++) {
                if (x % i == 0)
                    return false;
            }
            return true;
        }

        public override int nastepna(int n) {
            n+=1;
            while (!prime(n))
                n+=1;
            return n;
        }
    }
}
