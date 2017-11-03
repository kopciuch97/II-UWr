using System;

namespace Zadanie1 {

    public class RandomStream:IntStream {

        Random rnd = new Random();

        public override int nastepny() {
            return rnd.Next(0, int.MaxValue);
        }

        public override bool eos() {
            return false;
        }
    }
}