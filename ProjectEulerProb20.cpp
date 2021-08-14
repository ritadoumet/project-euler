
#include <iostream>
using namespace std;
int main()
{
	unsigned short int arr[600] = { 0 };
	int i = 100, rest;
	arr[597] = 1;
	int nbOfDigits = 3;
	while (i > 1) {
		i--;
		rest = 0;
		int j;
		for (j = 599; j >= 600 - nbOfDigits - 1; j--) {
			int prod = i * arr[j];
			arr[j] = (prod + rest)%10;
			rest = (prod + rest)/ 10;
			if (rest != 0 && j == 600 - nbOfDigits) {
				nbOfDigits++;
			}
		}
	}
	unsigned int sum = 0;
	cout << "nb of digits is " << nbOfDigits << endl;
	for (int j = 599 - nbOfDigits; j < 600; j++) {
		sum += arr[j];
		cout << arr[j];
	}
	cout << endl << "the sum is " << sum;

}
