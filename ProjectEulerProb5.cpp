
#include <iostream>
using namespace std;
int gcd(int n, int m) {
    int p = (n > m) ? m : n;
    while (p > 0) {
        if (n % p == 0 && m % p == 0) {
            break;
        }
        p--;
    }
    return p;
}
int main()
{
    long long int number = 1;
    for (int i = 2; i <= 20; i++) {
        number *= i / (gcd(i, number));
    }
    cout << number;
}
 