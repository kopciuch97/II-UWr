using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lista3
{
    public class Node<T>
    {
        public T value;
        public Node<T> next;

        public Node()
        {
            next = null;
            value = default(T);
        }
    }

    public class Lista<T>
    {

        public Node<T> head;

        public Lista()
        {
            head = null;
        }


        public void AppStart(T x)
        {
            if (head == null)
            {
                head = new Node<T>();
                head.value = x;
            }
            else
            {
                Node<T>  n = new Node<T>();
                n.value = x;
                n.next = head;
                head = n;
            }
        }

        public void AppEnd(T x)
        {
            if (head == null)
            {
                head = new Node<T>();
                head.value = x;
            }
            else
            {
                Node<T> n = new Node<T>();
                n.value = x;
                if (head.next == null)
                {
                    head.next = n;
                }
                else
                {
                    Node<T> temp = head;
                    while (temp.next != null)
                    {
                        temp = temp.next;
                    }
                    temp.next = n;
                }
            }

        }

        public T DelStart()
        {
            if (head == null)
            {
                Console.WriteLine("Nie potrafię odejmować od pustej listy!");
                return default(T);
            }
            else
            {
                T tempval = head.value;
                head = head.next;
                return tempval;
            }
        }

        public T DelEnd()
        {
            T tempval;
            Node<T> temp = head;

            if (head == null)
            {
                Console.WriteLine("Nie potrafie odejmować od listy pustej");
                return default(T);
            }
            else
            {
                if (temp.next == null)
                {
                    tempval = temp.value;
                    temp = null;
                    return tempval;
                }
                while (temp.next.next != null)
                {
                    temp = temp.next;
                }
                tempval = temp.next.value;
                temp.next = null;
                return tempval;
            }
        }

        public bool IsEmpty()
        {
            if (head == null)
                return true;
            else
                return false;
        }

        public void ShowNodes()
        {
            Node<T> temp = head;
            while (temp.next != null)
            {
                Console.WriteLine(temp.value);
                temp = temp.next;
            }
            Console.WriteLine(temp.value);
        }

    }
}

