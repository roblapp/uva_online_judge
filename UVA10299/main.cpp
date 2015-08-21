#include <iostream>
#include <set>
#include<cmath>

/* ACCEPTED 0.938s */
/*
Algorithm:

Math

*/

using namespace std;

void factor(long long int x, set<long long int>& u_factors) {

    while (x % 2 == 0) {
        x /= 2;
        u_factors.insert(2);
    }

    for (long long int i = 3; i <= sqrt(x); i += 2) {
        while (x % i == 0) {
            x /= i;
            u_factors.insert(i);
        }
    }

    if (x > 2) {
        u_factors.insert(x);
    }
}

void phi(int x) {

    set<long long int> s;
    double a, b, res = (1.0 * x);

    factor(x, s);

    for (set<long long int>::iterator it = s.begin(); it != s.end(); it++) {
        a = (1.0) * (*it);
        b = (1 - 1/(a));
        res *= b;
    }

    cout << ((long long int) res) << endl;
}

int main() {

    int x;

    while (cin >> x and x != 0) {
        if (x <= 1) cout << "0" << endl;
        else phi(x);
    }

    return 0;
}
