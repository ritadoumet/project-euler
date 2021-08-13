
#include <iostream>
using namespace std;

int main()
{
    int f1 = 1, f2 = 2, f3, sum=2;
    while (f2 <= 4000000) {
        f3 = f2 + f1;
        if (f3 % 2 == 0) {
            sum += f3;
        }
        f1 = f2;
        f2 = f3;
    }
    cout << "Sum of the even valued terms of the fibonacci sequence, that do not exceed 4 mil: " << sum;
}
