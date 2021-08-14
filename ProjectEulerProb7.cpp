
#include <iostream>
using namespace std;
bool isPrime(long int n) {
    int i = n / 2;
    bool prime = true;
    while (i > 1) {
        if (n % i == 0)
            return false;
        i--;
    }
    return true;
}
int main()
{
    int nbPrime = 0;
    int i = 2;
    while (nbPrime < 10001) {
        if (isPrime(i)) {
            nbPrime++;
        }
        i++;
    }
    cout << i - 1;
}