/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithms;

/**
 *
 * @author Szymon
 */
public class Testy {
    public static void Main(){
        System.out.println("=======INTEGER======");
		BST<Integer> b = new BST<>();
		b.insert(new Integer(3));
                b.insert(new Integer(8));
		b.insert(new Integer(1));
                b.insert(new Integer(4));
                b.insert(new Integer(6));
                b.insert(new Integer(1));
                b.insert(new Integer(10));
                b.insert(new Integer(21));
		b.insert(new Integer(20));
                b.insert(new Integer(25));
                b.insert(new Integer(15));
                b.insert(new Integer(16));
		System.out.println("Original Tree : ");
		System.out.println(b.toString());	
                System.out.println("\nOriginal Tree Size : ");
                System.out.println(b.size());
		System.out.println();
		System.out.println("Check whether Node with value 4 exists : " + b.search(4));
		System.out.println("\nDelete Node with no children (2) : ");
                b.remove(2);		
		System.out.println(b.toString());
		System.out.println("\n Delete Node with one child (4) : ");
                b.remove(4);		
		System.out.println(b.toString());
		System.out.println("\n Delete Node with Two children (10) : ");
                b.remove(10);		
		System.out.println(b.toString());
                System.out.println("\n Finding minimum value: ");
                System.out.println(b.min());
                System.out.println("\n Finding maximum value: ");
                System.out.println(b.max());
		System.out.println("\n Clearing Tree : ");
                b.clear();
                System.out.println(b.toString());
                
                System.out.println("========STRING=======");
                
                BST<String> bs = new BST<>();
		bs.insert("c");
                bs.insert("h");
		bs.insert("a");
                bs.insert("d");
                bs.insert("f");
                bs.insert("b");
                bs.insert("j");
                bs.insert("i");
		bs.insert("t");
                bs.insert("z");
                bs.insert("o");
                bs.insert("p");
		System.out.println("Original Tree : ");
		System.out.println(bs.toString());	
                System.out.println("\nOriginal Tree Size : ");
                System.out.println(bs.size());
		System.out.println();
		System.out.println("Check whether Node with value 'd' exists : " + bs.search("d"));
		System.out.println("\nDelete Node with no children (b) : ");
                bs.remove("b");		
		System.out.println(bs.toString());
		System.out.println("\n Delete Node with one child (d) : ");
                bs.remove("d");		
		System.out.println(bs.toString());
		System.out.println("\n Delete Node with Two children (j) : ");
                bs.remove("j");		
		System.out.println(bs.toString());
                System.out.println("\n Finding minimum value: ");
                System.out.println(bs.min());
                System.out.println("\n Finding maximum value: ");
                System.out.println(bs.max());
		System.out.println("\n Clearing Tree : ");
                bs.clear();
                System.out.println(bs.toString());
    
}
    
}
