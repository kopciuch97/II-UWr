#include <iostream>
#include <deque>
#include <random>
#include <ctime>
#include <random>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

// predykat ktory zwraca wartosc true
// jesli liczba jest dodatnia oraz mniejsza od 3
// uzyte zostaly tu wbudowane predykaty greater oraz less
template <class T> struct predykat
{
	bool operator() (const T& x) const
	{ 
		return greater<T>()(x, 0) && less<T>()(x, 3);
	}
};

int main()
{
	deque<double> d;
	random_device rd;
	mt19937 rng(rd());
	// liczby beda generowane zgodnie z rozkladem normalnym 
	normal_distribution<double> normal(0.0, 10.0);

	int n = 50;

	// Dodajemy kolejne liczby
	for (int i = 0; i < n; i++)
	{
		double x = normal(rng);
		d.push_back(x);
		cout << x << " ";
	}
	cout << endl;

	// zlicamy dodatnie i mniejsze od 3
	int cnt = count_if(d.begin(), d.end(), predykat<double>());
	cout << "\nDodatnich i mniejszych od 3: " << cnt << endl;

	// znajdujemy pierwsza dodatnia i mniejsza od 3
	deque<double>::iterator it = find_if(d.begin(), d.end(), predykat<double>());
	cout << "Pierwsza dodadnia i mniejsza od 3: ";
	if (it != d.end())
	{
		cout << *it << endl;
	}

	getchar();
	return 0;
}