import java.util.Hashtable;

public class Main
{
	public static void main(String[] args)
	{
		Hashtable<String, Integer> Tree = new Hashtable<String, Integer>();
		Tree.put("x",2);
		System.out.println("x = " + Tree.get("x"));
		Tree.put("y",6);
		System.out.println("y = " + Tree.get("y"));

		Wyrazenie str = new Dodaj(new Stala(2), new Zmienna("x", Tree));
		str = new Pomnoz(new Stala(4), str);
		str = new Podziel(str, new Zmienna("y", Tree));
		str = new Odejmij(str, new Stala(3));
		System.out.println(str.toString() + " = " + str.Oblicz());
	}
}