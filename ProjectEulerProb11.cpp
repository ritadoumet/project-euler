#include <iostream>
#include <fstream>
using namespace std;

void fillMatr(int arr[][20]) {
    ifstream e("matrix.txt", ios::in);
    char c1, c2, c3;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            e.get(c1);
            e.get(c2);
            arr[i][j] = (c1 - '0') * 10 + (c2 - '0');
            e.get(c3);
        }
    }
}
int main()
{
    
    long int max = 0; 
    int arr[20][20] = { 0 };

    //filling the matrix from the file
    fillMatr(arr);

    //finding the max of the rows max1
    
     for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 17; j++) {
            long int p = 0;
            p= arr[i][j] * arr[i][j + 1] * arr[i][j + 2] * arr[i][j + 3];
            if (p > max)
                max= p;
        }
    }
    //finding the max of the columns max2
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 20; j++) {
            long int p = arr[i][j] * arr[i + 1][j] * arr[i + 2][j] * arr[i + 3][j];
            if (p > max)
                max = p;
        }
    }

    
    
    //finding the max of the diagonals max3 (upper left -> lower right)
    //upper triangle
    for (int i = 0; i < 17; i++) {
        for (int j = i; j < 17; j++) {
            if ((i > 2 || j < 17) && (i < 17 || j>2)){
                long int p = arr[i][j] * arr[i + 1][j + 1] * arr[i + 2][j + 2] * arr[i + 3][j + 3];
                if (p > max)
                    max = p;
            }
            
        }
    }
   
    //finding the max of the diagonals max3 (upper right ->lower left)
    //upper triangle
    for (int i = 0; i < 17; i++)
        for (int j = 3; j < 20; j++) {
            if ((i > 2 || j > 2) && (i < 17 || j < 17)) {
                long int p = arr[i][j] * arr[i + 1][j - 1] * arr[i + 2][j - 2] * arr[i + 3][j - 3];
                if (p > max)
                    max = p;
            }
            
        }
  
    cout << max;
}
