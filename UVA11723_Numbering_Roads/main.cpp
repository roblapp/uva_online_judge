#include <iostream>
#include <iomanip>
#include <cmath>

/*
Accepted: 0.016s
Category: math
Algorithm: ad-hoc math
*/

using namespace std;

int main() {
	int r, n, N = 1;

	while (cin >> r >> n and (r != 0 or n != 0)) {
        if (n + 26*n < r)
            cout << "Case " << N++ << ": impossible" << endl;
        else
            cout << "Case " << N++ << ": " << fixed << setprecision(0) << ceil(1.0*r/n)-1 << endl;
	}
    return 0;
}
