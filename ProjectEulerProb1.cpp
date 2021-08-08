
#include <iostream>
using namespace std;

bool isMultipleOf3(int n) {
    if (n % 3 == 0) {
        return true;
    }
    return false;
}

bool isMultipleOf5(int n) {
    if (n % 5 == 0) {
        return true;
    }
    return false;
}
int main()
{
    int sum = 0;
    for (int i = 1; i < 1000; i++) {
        if (isMultipleOf3(i) || isMultipleOf5(i)) {
            sum += i;
        }
    }
    cout << "the sum of all the multiples of 3 or 5 below 1000: " << sum;
}
