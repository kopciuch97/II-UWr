class Main{

public static void wypisz(long[] LISTA){
    int i =0;
    while(LISTA[i]!=0){
        if(LISTA[i+1]==0){
            System.out.print(LISTA[i]);
        }
        else{
            System.out.print(LISTA[i]+" * ");
        }
        i+=1;
}
}

public static void main (String[] args) {
    for(String x:args){
        long var = Long.valueOf(x);
    if(LiczbyPierwsze.czyPierwsza(var)){
	System.out.println("Liczba " + var + " jest pierwsza.");
	}
    else{
	wypisz(LiczbyPierwsze.naCzynnikiPierwsze(var));
	}
    }
}
}
