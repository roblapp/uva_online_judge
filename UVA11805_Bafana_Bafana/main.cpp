#include <iostream>

/*
Accepted: 0.000s
Category: ad-hoc
*/

using namespace std;

int main() {
	int ncases, n, k, p, soln, N = 1;

	cin >> ncases;
	while (ncases--) {
        cin >> n >> k >> p;
        soln  = (k + p) % n;
        if (soln == 0) soln = n;
        cout << "Case " << N++ << ": " << soln << endl;
	}
    return 0;
}
