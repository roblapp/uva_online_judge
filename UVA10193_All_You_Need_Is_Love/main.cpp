#include <iostream>
#include <cmath>

/*
Accepted: 0.000s
Category: math
Algorithm: Euclid's GCD algorithm
*/

#define DIFF '0'

using namespace std;

unsigned gcd(unsigned a, unsigned b) {
    return (b == 0) ? a : gcd(b, a%b);
}

int main() {
    int ncases, N = 1, len;
    unsigned a, b;
    string sa, sb;

    cin >> ncases;
    while (ncases--) {
        cin >> sa >> sb;
        a = b = 0;
        len = (int) sa.length();
         for (int j = 0; sa[j]; j++)
            a += (sa[j] - DIFF) * pow(2, (len - j - 1));
        len = (int) sb.length();
        for (int j = 0; sb[j]; j++)
            b += (sb[j] - DIFF) * pow(2, (len - j - 1));
        if (a == b or gcd(a,b) > 1)
            cout << "Pair #" << N++ << ": All you need is love!" << endl;
        else
            cout << "Pair #" << N++ << ": Love is not all you need!" << endl;
    }
    return 0;
}
