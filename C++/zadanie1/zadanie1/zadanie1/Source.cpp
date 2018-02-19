#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

int arabskie[] = { 9000,5000,4000,1000,900,500,400,100,90,50,40,10,9,5,4,1 };
string rzymskie[] = { "|IX|","|V|","M|V|","M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
int wynik;
string liczbaR,rzym;

int arab2bin(const char* x) {
	int i = 0;
	if (x[i] == 0)
		return 0;
	while (x[i] != '\0')
	{
		if ((int(x[i] < 48)) || (int(x[i] > 57)))
		{
			return 0;
		}
		if ((int(x[0]) == 48))
		{
			return 0;
		}
		i++;
	}
	if (i > 4)
		return 0;
	return atoi(x);
}
string bin2rzym(int x) {
	int i = 0;
		if ((x <= 9999) && (x > 0))
		{
			while (x > 0) {
				if (arabskie[i] <= x) {
					liczbaR += rzymskie[i];
					x -= arabskie[i];
				}
				else
					i++;
			}
		}
		return liczbaR;
}
int main(int argc, char * argv[]) {
	cout << "Zamiana liczb arabskich na rzymskie" << endl;
	for (int k = 1; k < argc; k++)
	{
		wynik = arab2bin(argv[k]);
		if (wynik == 0)
			cerr << argv[k] << " Bledna liczba" << endl;
		else
		{
			rzym = bin2rzym(wynik);
			cout << rzym << "=" << argv[k] << endl;
			liczbaR = "";
		}
	}
	return 0;
}
	
	