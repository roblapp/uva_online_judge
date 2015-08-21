#include <iostream>
#include <cstdio>
#include <cstdlib>

/* ACCEPTED 0.472s */
/*
Algorithm:

Euclids algorithm... taken directly from
Wikipedia...
*/

using namespace std;

void euclids(long long int a, long long int b) {
    long long int s = 0, olds = 1, t = 1, oldt = 0, r = b, oldr = a, quotient;
    long long int temp;

    while (r > 0) {
        quotient = oldr / r;
        temp = r;
        r = oldr - quotient * r;
        oldr = temp;

        temp = s;
        s = olds - quotient * s;
        olds = temp;

        temp = t;
        t = oldt - quotient * t;
        oldt = temp;
    }

    cout << olds << " " << oldt << " " << oldr << endl;
}


int main() {

    long long int a, b;

    while (cin >> a >> b) {
        euclids(a, b);
    }

    return 0;
}
