package wyrazenia;

public class Main {
	
	public static void main(String[] args) {
	Zmienna.addVariable("x",-1.618);
	Zmienna.addVariable("y",2);
	
	// 3+5
	Wyrazenie w1 = new Dodawanie(
		new Stala(3),
		new Stala(5)
	);
	
	System.out.println("3+5");
	System.out.println(w1.toString());
	System.out.println(w1.oblicz());
	System.out.println();
	
	//2+x*7
	Wyrazenie w2 = new Dodawanie(
		new Stala(3),
		new Mnozenie(
			new Zmienna("x"),
			new Stala(7)
		)
	);
	
	System.out.println("2+x*7");
	System.out.println(w2.toString());
	System.out.println(w2.oblicz());
	System.out.println();
	
	//(3*11-1)/(7+5)
	Wyrazenie w3 = new Dzielenie(
		new Odejmowanie(
			new Mnozenie(
				new Stala(3),
				new Stala(11)
			),
			new Stala(1)
		),
		new Dodawanie(
			new Stala(7),
			new Stala(5)
		)	
	);
	
	System.out.println("(3*11-1)/(7+5)");
	System.out.println(w3.toString());
	System.out.println(w3.oblicz());
	System.out.println();
	
	//arctan(((x+13)*x)/2)
	Wyrazenie w4 = new Arctan(
		new Dzielenie(
			new Mnozenie(
				new Dodawanie(
					new Zmienna("x"),
					new Stala(13)
				),
				new Zmienna("x")
			),
			new Stala(2)
		)
	);
	
	System.out.println("arctan(((x+13)*x)/2)");
	System.out.println(w4.toString());
	System.out.println(w4.oblicz());
	System.out.println();

	
	//pow(2,5)+x*log(2,y)
	Wyrazenie w5 = new Dodawanie(
		new Potegowanie(
			new Stala(2),
			new Stala(5)
		),
		new Mnozenie(
			new Zmienna("x"),
			new Logarytmowanie(
				new Stala(2),
				new Zmienna("y")
			)
		)
	
	);
	
	System.out.println("pow(2,5)+x*log(2,y)");
	System.out.println(w5.toString());
	System.out.println(w5.oblicz());
	System.out.println();
	
	}



}
