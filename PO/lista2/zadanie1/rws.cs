using System;

namespace Zadanie1 {

    public class RandomWordStream : PrimeStream {

        public new string next() {
            if (poprzedni == int.MaxValue)
                return "Error";
            poprzedni += 1;
            while (!prime(poprzedni) && poprzedni < int.MaxValue)
                poprzedni += 1;
            if (poprzedni == int.MaxValue)
                return "Error";
            else {
                string x = "";
                for(int i=0; i<poprzedni;i++) {
                    x += RandomLetter.GetLetter();
                }
                return x;
            }
        }
    }
}
