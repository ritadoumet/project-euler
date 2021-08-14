
#include <iostream>
#include <map>
using namespace std;

map <int, int> nbToLetter; //key: number, value: nb of letters;

void fillMAP() {
    nbToLetter.insert(pair<int, int>(1, 3));
    nbToLetter.insert(pair<int, int>(2, 3));
    nbToLetter.insert(pair<int, int>(3, 5));
    nbToLetter.insert(pair<int, int>(4, 4));
    nbToLetter.insert(pair<int, int>(5, 4));
    nbToLetter.insert(pair<int, int>(6, 3));
    nbToLetter.insert(pair<int, int>(7, 5));
    nbToLetter.insert(pair<int, int>(8, 5));
    nbToLetter.insert(pair<int, int>(9, 4));
    nbToLetter.insert(pair<int, int>(10, 3));
    nbToLetter.insert(pair<int, int>(11, 6));
    nbToLetter.insert(pair<int, int>(12, 6));
    nbToLetter.insert(pair<int, int>(13, 8));
    nbToLetter.insert(pair<int, int>(14, 8));
    nbToLetter.insert(pair<int, int>(15, 7));
    nbToLetter.insert(pair<int, int>(16, 7));
    nbToLetter.insert(pair<int, int>(17, 9));
    nbToLetter.insert(pair<int, int>(18, 8));
    nbToLetter.insert(pair<int, int>(19, 8));
    nbToLetter.insert(pair<int, int>(20, 6));
    nbToLetter.insert(pair<int, int>(30, 6));
    nbToLetter.insert(pair<int, int>(40, 5));
    nbToLetter.insert(pair<int, int>(50, 5));
    nbToLetter.insert(pair<int, int>(60, 5));
    nbToLetter.insert(pair<int, int>(70, 7));
    nbToLetter.insert(pair<int, int>(80, 6));
    nbToLetter.insert(pair<int, int>(90, 6));
    nbToLetter.insert(pair<int, int>(100, 7));
    nbToLetter.insert(pair<int, int>(1000, 8));
    nbToLetter.insert(pair<int, int>(1001, 3)); //and
}
int MAP(int x) {
    return (*nbToLetter.find(x)).second;
}

int nbOfLetters(int x) {
    int hundreds = x / 100;
    int tens = (x - hundreds*100) / 10;
    int units = x % 10;
    int nb = 0;
    if (hundreds != 0) {
        nb += MAP(hundreds) + MAP(100);
        if (tens != 0 || units!=0) {
            nb += MAP(1001);
        }
    }
    if (tens > 1) {
        nb += MAP(tens * 10);
        if (units != 0) {
            nb += MAP(units);
        }
    }
    else {
        if (tens!=0 || units!=0)
            nb += MAP(tens * 10 + units);
    }
    return nb;
}
int main()
{
    fillMAP();
    int i = 0;
    int sum = 0;
    while (i < 999) {
        i++;
        sum += nbOfLetters(i);
    }
    
    sum += MAP(1) + MAP(1000);
    cout << sum;
    
}
