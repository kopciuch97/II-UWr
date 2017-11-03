#include <iostream>
#include <deque>
#include <random>
#include <ctime>
#include <random>
#include <fstream>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	deque<int> d;
	random_device rd;
	mt19937 rng(rd());
	// liczby generujemy zgodnie z rozkladem dwumianowym
	binomial_distribution<int> bin(10, 0.5);

	int n = 100;

	cout << "Poczatkowa lista:\n";
	for (int i = 0; i < n; i++)
	{
		int x = bin(rng);
		d.push_back(x);
		cout << x << " ";
	}
	cout << endl;

	// usuwamy wszystkie liczby miejszy od oraz wszystkie liczby wieksze od 8
	d.erase(remove_if(d.begin(), d.end(), [](double x) {return x < 2 || x > 8;}), d.end());
	cout << "Po usunieciu mniejszych od 2 i wiekszych od 8:\n";

	for (auto x : d)
	{
		cout << x << " ";
	}

	cout << endl;

	// zliczamy wszystkie liczby wieksze od 4 i mniejsze od 6
	int cnt = count_if(d.begin(), d.end(), [](double x) {return x > 4 && x < 6;});
	cout << "Wiekszych od 4 i mniejszych od 6: " << cnt << endl;
	
	getchar();
	return 0;
}