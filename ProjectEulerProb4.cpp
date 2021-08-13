
#include <iostream>
using namespace std;

int digits(int n) {
    if (n == 0) {
        return 1;
    }
    int dig = 0;
    while (n > 0) {
        dig++;
        n = n / 10;
    }
    return dig;
}

int nthDig(int n, int p) {
    for (int i = 1; i < p; i++) {
        n = n / 10;
    }
    return n % 10;
}
bool isPalindrome(int n) {
    int dig = digits(n);
    bool palindrome = true;
    int i = dig / 2;
    for (int j = 1; j <= i; j++) {
        if (nthDig(n, j) != nthDig(n, dig - j + 1)) {
            palindrome = false;
            break;
        }
    }
    if (palindrome)
        return true;
    else return false;
}
int main()
{
    int nbPal = 0;
    long int* pals = new long int[20000];
    for (int i = 999; i > 99; i--) {
        for (int j = 999; j > 99; j--) {
            if (isPalindrome(j * i))
                pals[nbPal++] = i * j;
        }
    }
    int max = 0;
    for (int i = 0; i < nbPal; i++) {
        if (pals[i] > max) {
            max = pals[i];
        }
    }
    cout << max;
}
