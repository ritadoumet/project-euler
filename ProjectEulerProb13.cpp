
#include <iostream>
#include <fstream>
using namespace std;
void fillMatrix(short int a[][50]) {
    ifstream f("number.txt", ios::in);
    char c;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 50; j++) {
            f.get(c);
            while (c == '\n' || c == ' ') {
                f.get(c);
            }
            a[i][j] = c - '0';
        }
    }
}
int main()
{
    int* summ = new int[50];
    int s;
    for (int i = 0; i < 50; i++) {
        summ[i] = 0;
    }
    short int a[100][50];
    fillMatrix(a);
    for (int j = 49; j >= 0; j--) {
        s = 0;
        for (int i = 0; i < 100; i++) {
            s += a[i][j];
        }
        int tot = s + summ[j];
        if (j != 0) {
            summ[j] = tot%10;
            summ[j - 1] += (tot/10);
        }
        else {
            summ[j] = tot;
        }
    }

    cout << endl;
    for (int j = 0; j <= 49; j++) {
        cout << summ[j] << ' ';
    }
}
