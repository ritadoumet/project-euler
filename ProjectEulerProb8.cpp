
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	ifstream f("number.txt",ios::in);
	int numbs[13];
	char c;
	for (int i = 0; i < 12; i++) {
		f.get(c);
		numbs[i] = c-'0';
	}
	long long int maxProd = 0, prod;
	for (int i = 13; i <=1000; i++) {
		f.get(c);
		numbs[12] = c-'0';
		prod = 1;
		for (int j = 0; j < 13; j++) {
			prod *= numbs[j];
		}
		if (prod > maxProd)
			maxProd = prod;

		for (int i = 0; i < 12; i++) {
			numbs[i] = numbs[i + 1];
		}
	}
	cout << maxProd;
}
