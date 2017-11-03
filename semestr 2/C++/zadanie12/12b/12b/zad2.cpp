#include <iostream>
#include <list>
#include <random>
#include <ctime>
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

// obiekt funkcyjny (funktor) ktory 
// zapamietuje min, max oraz sume
// (z sumy na koniec liczona jest srednia za pomoca funkcji avg())
struct Func
{
	int min, max, sum, n;
	Func() : min(INT_MAX), max(INT_MIN), sum(0), n(0) { }
	void operator()(int x)
	{
		n++;
		sum += x;
		if (x < min)
		{
			min = x;
		}
		if (x > max)
		{
			max = x;
		}
	}

	double avg()
	{
		return (double)sum / n;
	}
};

void czesc1()
{
	random_device rd; // do zainicjowania generatora
	mt19937 rng(rd()); // genrator Mersenne-Twister
	uniform_int_distribution<int> uni(2, 100); // n i k generujemy zgodnie z rozkladem jednostajnym

	// generujemy n i k
	int n = uni(rng);
	int k = uni(rng);

	// kolejne liczby generujemy zgodnie z rozkladem dwumianowym
	binomial_distribution<int> bin(k, 0.5);

	ofstream f("liczby.txt");
	for (int i = 0; i < n; i++)
	{
		// zapsanie liczb do pliku
		f << bin(rng) << " ";
	}
}



void czesc2()
{
	list<int> lista;

	ifstream f("liczby.txt");

	int liczba;
	// wczytanie liczb z pliku i dodanie do listy
	while (f >> liczba)
	{
		lista.push_back(liczba);
	}

	for (auto x : lista)
	{
		cout << x << " ";
	}


	// wywolanie for_each z funktorem
	Func func = std::for_each(lista.begin(), lista.end(), Func());

	// wypisujemy wyznacozne min, max oraz wartosc srednia
	cout << "\nmin: " << func.min << "\n";
	cout << "max: " << func.max << "\n";
	cout << "srednia: " << func.avg() << "\n";
}

int main()
{
	czesc1();
	czesc2();

	getchar();
	return 0;
}