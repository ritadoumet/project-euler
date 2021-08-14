
#include <iostream>
using namespace std;

unsigned long long int findNbPaths(int i, int j, int n, unsigned long long int** a) {
    if (i == n && j == n)
        return 1;
    if (i == n) {
        if (a[i][j+1] != 0)
            return a[i][j+1];
        return a[i][j + 1] = findNbPaths(i, j + 1, n, a);
    }
    if (j == n) {
        if (a[i + 1][j] != -1)
            return a[i + 1][j];
        return a[i + 1][j] = findNbPaths(i + 1, j, n, a);
    }
    a[i + 1][j] = findNbPaths(i + 1, j, n,a);
    a[i][j + 1] = findNbPaths(i, j + 1, n, a);;
    return a[i + 1][j] + a[i][j + 1];
}
int main()
{
    int N;
    cout << "Enter N: ";
    cin >> N;
    unsigned long long int** a = new unsigned long long int* [N+1];
    for (int i = 0; i < N+1; ++i)
        a[i] = new unsigned long long int[N+1];
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            a[i][j] = 0;
        }
    }
    cout << findNbPaths(0, 0, N, a);
}
