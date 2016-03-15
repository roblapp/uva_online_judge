#include <iostream>
#include <iomanip>
#include <cmath>

/*
Accepted: 0.000s
Category: math
*/

using namespace std;

int main() {
	int ncases;
	double d, v, u, t1, t2;

	cin >> ncases;
	for (int i = 1; i <= ncases; i++) {
        cin >> d >> v >> u;
        if (v == 0 or u == 0 or v >= u) {
            cout << "Case " << i << ": can't determine" << endl;
        } else {
            t1 = d/u;
            t2 = d/sqrt(u*u - v*v);
           cout << "Case " << i << ": " << fixed << setprecision(3) << fabs(t1-t2) << endl;
        }
	}
    return 0;
}
