using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace zad2lista3
{
    public class slownik<K, V> where K : IComparable<K>
    {
        slownik<K, V> next;
        protected K key;
        protected V val;

        public slownik()
        {
            next = null;
            key = default(K);
            val = default(V);
        }

        public void Add(K key, V val)
        {
            if (this.next != null)
            {
                this.next.Add(key, val);
            }
            else
            {
                this.next = new slownik<K, V>();
                this.next.key = key;
                this.next.val = val;
            }

        }
        public void Delete(K key)
        {
            if (key.CompareTo(this.next.key) == 0)
            {
                Console.WriteLine("element usuwany - {0}", this.next.key);
                this.next = this.next.next;
            }
            else
            {
                if (this.next != null)
                    this.next.Delete(key);
            }

        }

        public V Find(K key)
        {
            slownik<K, V> current = this;
            // while(current.key != key)
            while (key.CompareTo(current.key) != 0)
            {
                Console.WriteLine("sprawdzany key - {0}", current.key);
                current = current.next;
                if (current == null)
                    return default(V);
            }
            Console.WriteLine("Znaleziony key - {0}", current.key);
            return current.val;

        }
        public void print()
        {
            if (this.next != null)
            {
                Console.WriteLine("{0} {1}", this.key, this.val);
                this.next.print();
            }
            else
            {
                Console.WriteLine("{0} {1}", this.key, this.val);
            }
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            var Dictionary = new slownik<int, string>();

            Dictionary.Add(13, "maciek");
            Dictionary.Add(2, "marta");
            Dictionary.Add(32, "wojtek");

            Dictionary.print();

            Dictionary.Delete(13);

            Dictionary.print();

            Dictionary.Find(13);
            Dictionary.Find(32);
            Console.ReadKey();
        }
    }
}

