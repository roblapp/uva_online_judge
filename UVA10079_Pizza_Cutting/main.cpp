#include <iostream>

/*
Accepted: 0.000s
Category: ad-hoc
Algorithm: See http://www.algorithmist.com/index.php/UVa_10079
*/

using namespace std;

int main() {
	long long x;

	while (cin >> x and x >= 0)
        cout << (x*x + x) / 2 + 1 << endl;

    return 0;
}
