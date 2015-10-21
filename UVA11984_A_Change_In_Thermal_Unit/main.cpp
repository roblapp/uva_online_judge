#include <iostream>
#include <cstdio>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

int main() {
    int ncases, N = 1;
    double a, b;
    cin >> ncases;
    while (ncases--) {
        cin >> a >> b;
        printf("Case %i: %.2lf\n", N++, (5.0/9)*b + a);
    }
    return 0;
}
