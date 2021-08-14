
#include <iostream>
using namespace std;
int main()
{
	unsigned short int arr[500] = { 0 };
	int i = 0, rest;
	arr[499] = 1;
	int nbOfDigits = 1;
	while (i < 1000) {
		rest = 0;
		int j;
		for (j = 499; j >= 500-nbOfDigits-1; j--) {
			int prod = 2 * arr[j];
			arr[j] = prod % 10 + rest;
			rest = prod / 10;
			if (rest != 0 && j == 500 - nbOfDigits) {
				nbOfDigits++;
			}
		}
		i++;
	}
	unsigned int sum = 0;
	cout << "nb of digits is " << nbOfDigits << endl;
	for (int j = 499 - nbOfDigits; j < 500; j++) {
		sum += arr[j];
		cout << arr[j];
	}
	cout << endl << "the sum is " << sum;

}
