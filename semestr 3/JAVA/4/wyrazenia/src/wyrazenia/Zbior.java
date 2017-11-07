package wyrazenia;

/**
 *  Klasa reprezentujaca zbior par o unikalnym kluczu
 * @author Szymon
 * 
 */
public class Zbior {
    Para[] tab; //Definicja tablicy par
    int iloscpar=0;
    
    Zbior(){ //Konstruktor bezparametrowy klasy Zbior tworzacy tablice o dlugosci 100
        this.tab = new Para[100];
   }
    
    Zbior(int len){ //Konstruktor klasy Zbior tworzacy tablice o dlugosci 'len' przesłaną w parametrze.
        this.tab = new Para[len];
    }
    
    /**
     *
     * @param key
     * @return
     * @throws IllegalArgumentException
     */
    public Para szukaj(String key) throws IllegalArgumentException{
        for(Para p : tab){
            if (p.key == key){
                return p;
            }
        }
        throw new IllegalArgumentException("Podanego klucza nie ma w zbiorze");
    }
    
    private boolean czyjest(Para szukana){ //metoda pomocnicza, która w argumencie przyjmuje obiekt Para zwraca wartosc boolowską mówiącą czy obiekt ten jest  w Zbiorze czy nie
        for(Para p : tab){
            if(szukana.equals(p)){
                return true;
            }
        }
        return false;
    }
    
    /**
     *
     * @param p
     * @throws IllegalArgumentException
     */
    public void wstaw (Para p) throws IllegalArgumentException{ //metoda wstawiajaca Pare do zbioru, jesli para o danym kluczu juz istnieje rzucany jest wyjatek
        if (czyjest(p)){
            throw new IllegalArgumentException("Para o tym kluczu jest juz w zbiorze!");
        }
        else{
            tab[iloscpar]=p;
            iloscpar+=1;
        }
    }
    
    /**
     *
     * @param key
     * @return
     * @throws IllegalArgumentException
     */
    public double czytaj(String key) throws IllegalArgumentException{ //metoda zwracajaca wartosc obiektu Para o podanym kluczu ze zbioru 
        for(Para p : tab){
            if(p.key==key){
                return p.getValue();
            }
        }
        throw new IllegalArgumentException("Pary o podanym kluczu nie ma w zbiorze!");
    }
    
    /**
     *
     * @param p
     * @throws IllegalArgumentException
     */
    public void ustal(Para p) throws IllegalArgumentException{ //metoda wstawiajaca obiekt Para do zbioru lub jesli w zbiorze jest Para o tym samym kluczu aktualizuje jego wartosc
        if(czyjest(p)){
            for (Para szukana : tab){
                if(p.key == szukana.key){
                    szukana.setValue(p.getValue());
                }
            }
        }
        else {
            if(iloscpar==tab.length)
            {
                throw new IllegalArgumentException("Tablica jest juz pelna, nie mozna dodac nowej pary");
            }
            wstaw(p);
        }  
    }
    /**
    *metoda zwracajaca ilosc obiektow Para w zbiorze
    * @return iloscpar
    **/
    public int ile(){ //metoda zwracajaca ilosc obiektow Para w zbiorze
        return iloscpar;
    }
    
    /**
     *
     */
    public void czysc(){ //metocza czyszczaca zbior
        for(Para p : tab){
            p = null;
        }
    }
    
}
