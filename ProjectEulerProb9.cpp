
#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    for (c = 333; c < 1000; c++) {
        for (b = 1; b < c; b++) {
            for (a = 0; a < b; a++) {
                if (((a + b + c) == 1000) && ((a * a + b * b) == (c * c))) {
                    cout << a << " " << b << " " << c<<endl<<a*b*c;
                    break;
                }
            }
        }
    }
   
}
