#include <iostream>

/*
Accepted: 0.000s
Category: math simulation
Algorithm: median finding
Info: they guarantee the numbers will be sorted ascending
or descending and that there will be an odd number of
players... so this problem is trivial
*/

using namespace std;

int main() {
	int ncases, np, soln, x, index;

	cin >> ncases;
	for (int i = 1; i <= ncases; i++) {
        cin >> np;
        index = np >> 1;
        for (int j = 0; j < np; j++) {
            cin >> x;
            if (j == index)
                soln = x;
        }
        cout << "Case " << i << ": " << soln << endl;
	}
    return 0;
}
