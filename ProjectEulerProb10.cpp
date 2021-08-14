
#include <iostream>
using namespace std;

bool isPrime(long long int n) {
    if (n == 1) {
        return true;
    }
    long long int i = n / 2;
    while (i > 1) {
        if (n % i == 0) {
            return false;
        }
        i--;
    }
    return true;
}
int main()
{
    int i = 2;
    long long int sum = 0;
    while (i < 2000000) {
        if (isPrime(i)) {
            sum += i;
        }
        i++;
    }
    cout << sum;
}
