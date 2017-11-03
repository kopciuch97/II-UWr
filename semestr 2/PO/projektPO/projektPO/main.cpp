#include <iostream>
#include <map>

#include "Firma.h"

using namespace std;

int main()
{
	Firma firma;
	firma.importuj(); // na samym nastepuje import danych z pliku

	while (true)
	{
		cout << "\nWybierz operacje: " << endl;
		cout << "1 - Wyswietl dostepne produkty" << endl;
		cout << "2 - Wyswietl pracownikow" << endl;
		cout << "3 - Dodaj pracownika" << endl;
		cout << "4 - Dodaj produkt" << endl;
		cout << "5 - Edytuj pracownika" << endl;
		cout << "6 - Edytuj produkt" << endl;
		cout << "7 - Zrealizuj zamowienie" << endl;
		cout << "8 - Koniec" << endl;

		int wybor;
		cin >> wybor;

		string imie, nazwisko, NIP;
		double cena;
		string nazwa;
		int sztuk;
		int nr;

		if (wybor == 1)
		{
			cout << endl;
			firma.wyswietlDostepneProdukty();
		}
		else if (wybor == 2)
		{
			cout << endl;
			firma.wyswietlPracownikow();
		}
		else if (wybor == 3)
		{
			cout << "Podaj dane\n";
			cout << "Imie: "; cin >> imie;
			cout << "Nazwisko: "; cin >> nazwisko;
			firma.dodajPracownika(imie, nazwisko);
		}
		else if (wybor == 4)
		{
			cout << "Podaj dane\n";
			cout << "Nazwa: "; cin >> nazwa;
			cout << "Cena: "; cin >> cena;
			cout << "Liczba sztuk: "; cin >> sztuk;
			firma.dodajProdukt(nazwa, cena, sztuk);
		}
		else if (wybor == 5)
		{
			cout << "Wybierz pracownika\n";
			firma.wyswietlPracownikow();
			cin >> nr;
			cout << "Nowe imie: "; cin >> imie;
			cout << "Nowe nazwisko: "; cin >> nazwisko;
			firma.edytujPracownika(nr - 1, imie, nazwisko);
		}
		else if (wybor == 6)
		{
			cout << "Wybierz produkt\n";
			firma.wyswietlDostepneProdukty();
			cin >> nr;
			cout << "Nowa nazwa: "; cin >> nazwa;
			cout << "Nowa cena: "; cin >> cena;
			cout << "Nowa liczba sztuk: "; cin >> sztuk;
			firma.edytujProdukt(nr - 1, nazwa, cena, sztuk);
		}
		else if (wybor == 7)
		{
			cout << "Podaj dane\n";
			cout << "Imie kontrahenta: "; cin >> imie;
			cout << "Nazwisko kontrahenta: "; cin >> nazwisko;
			cout << "NIP: "; cin >> NIP;

			vector<string> nazwy;
			vector<int> liczbaSztuk;


			char c;

			while (true)
			{
				cout << "Nazwa produktu: "; cin >> nazwa;
				cout << "Liczba sztuk: "; cin >> sztuk;
				nazwy.push_back(nazwa);
				liczbaSztuk.push_back(sztuk);

				cout << "Czy chcesz dodac kolejny produkt? (T / N)" << endl;
				cin >> c;

				if (c != 'T' && c != 't')
				{
					break;
				}
			}

			firma.utworzZamowienie(nazwy, liczbaSztuk, Kontrahent(imie, nazwisko, NIP));
			
		}
		else
		{
			break;
		}

		firma.eksportuj();
	}
	return 0;
}