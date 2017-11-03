def zespolona(x,y): #Tworzenie liczby zespolonej o czesci rzeczywistej x i urojonej y
    return (x,y)

def dodawanie(x,y): #gdzie x,y sa nizej zaproponowanym typem tj. krotka o dlugosci 2 (1 element to czesc rzeczywista a 2 urojona)
    try:
        wynik = [0,0]
        wynik[0] = x[0] + y[0]
        wynik[1] = x[1] + y[1]
        return tuple(wynik)
    except TypeError:
        print('Ten program obsluguje tylko liczby zespolone w postaci algebraicznej o typie krotki')
def odejmowanie(x,y):
    try:
        wynik = [0,0]
        wynik[0] = x[0] - y[0]
        wynik[1] = x[1] - y[1]
        return tuple(wynik)
    except TypeError:
        print('Ten program obsluguje tylko liczby zespolone w postaci algebraicznej o typie krotki')
def mnozenie(x,y):
    try:
        wynik = [0,0]
        wynik[0] = x[0] * y[0] - x[1] * y[1]
        wynik[1] = x[0] * y[1] + y[0] * x[1]
        return tuple(wynik)
    except TypeError:
        print('Ten program obsluguje tylko liczby zespolone w postaci algebraicznej o typie krotki')
def dzielenie(x,y):
    try:
        wynik = [0,0]
        wynik[0] = (x[0] * y[0] + x[1] * y[1]) / (((y[0])**2) + ((y[1])**2))
        wynik[1] = (x[1] * y[0] - x[0] * y[1]) / (((y[0])**2) + ((y[1])**2))
        return tuple(wynik)
    except TypeError:
        print('Ten program obsluguje tylko liczby zespolone w postaci algebraicznej o typie krotki')
