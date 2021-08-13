
#include <iostream>
using namespace std;

bool isPrime(long long int n) {
    if (n == 1) {
        return true;
    }
    long long int i = n / 2;
    bool divisor = false;
    while (i > 1) {
        if (n % i == 0) {
            divisor = true;
            break;
        }
        i--;
    }
    if (divisor) return false;
    else return true;
}
long long int largestPrimeFactor(long long int n) {
    long long int i = n / 2;
    while (i > 0) {
        if (n % i == 0 && isPrime(i)) {
            return i;
        }
        i--;
    }
}

int main()
{
   cout << largestPrimeFactor(600851475143);
}
