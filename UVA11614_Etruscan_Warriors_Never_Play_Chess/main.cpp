#include <iostream>
#include <iomanip>
#include <cmath>

/*
Accepted: 0.000s
Category: math
Algorithm: quadratic formula
Info: given the problem description, we can see we are looking for a number, n
such that n(n+1)/2 = x, given x. We are using the formula because the warriors are
forming the following pattern:
1
2 3
4 5 6
7 8 9 10
...
x = n(n+1)/2 -> n^2 + n -2x = 0, so we can use the quadratic formula
with A = 1, B = 1 and C = -2*x. We simplify, solve and take the floor
of the solution.
*/

using namespace std;

int main() {
	int ncases;
	double x;

	cin >> ncases;
	while (ncases--) {
        cin >> x;
        cout << fixed << setprecision(0) << floor((-1 + sqrt(1 + 8.0*x))/2) << endl;
	}
    return 0;
}
