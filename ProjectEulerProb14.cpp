
#include <iostream>
#include <vector>

using namespace std;

int findLength(uint64_t n , vector<int>& v) {
	if (n == 1)
		return 1;
	if (n < v.size() && v[n] != -1) {
		return v[n];
	}
	if (n % 2 == 0) {
		int s = 1 + findLength(n / 2, v);;
		if (n < v.size()) {
			v[n] = s;
		}
		return s;
	}
	int s = 1 + findLength(3 * n + 1, v);
	if (n < v.size())
		v[n] = s;
	return s;
}
int main()
{
	long int longestChain = 0;
	vector<int> v(100000, -1);
	int i = 1, l, index;
	while (i < 1000000) {
		l = findLength(i, v);
		if (l > longestChain) {
			longestChain = l;
			index = i;
		}
		i++;
	}
	cout << "longest chain: " << longestChain << endl
		<< "index: " << index;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
