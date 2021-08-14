// ProjectEulerProb12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int nbDivisors(long long int n) {
    
    long long int i = n / 2;
    int nb = 2;
    int min = 1;
    while (i > min) {
        if (n % i == 0) {
            nb += 2;
            min = n / i;
        }
        i--;
    }
    return nb;
}
int main()
{
    long long int sum = 0;
    int i = 1;
    while (sum < 1000) {
        sum += i;
        i++;
    }
    while (nbDivisors(sum) < 500) {
        sum += i;
        i++;
    }
    cout << sum;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
