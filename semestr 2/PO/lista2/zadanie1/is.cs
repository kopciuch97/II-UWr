using System;

namespace Zadanie1 {
    public class IntStream {

        public int poprzedni;

        public IntStream() {
            poprzedni = -1;
        }

        public virtual int nastepny() {
            if (poprzedni == int.MaxValue)
                return -1;
            poprzedni++;
            return poprzedni;
        }

        public virtual bool eos() {
            if (poprzedni == int.MaxValue)
                return true;
            else
                return false;
        }

        public void reset() {
            poprzedni = -1;
        }

    }
}
