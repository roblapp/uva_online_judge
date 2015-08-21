#include <iostream>
#include <cmath>

/* ACCEPTED 0.049s */
/*
Algorithm:
Some math trickery.
Exploited Goldbach's conjecture as well as
the fact that any answer will work... If
they had restrictions on the answers this
would not work.

From UVA boards:

If N < 8 answer = impossible
if N is even answer = 2 + 2 + (N - 4)
    (N - 4) is even so it can be expressed as sum of 2 primes.
if N is odd answer = 2 + 3 + (N - 5)
    (N - 5) is even so it can be expressed as sum of 2 primes.
*/

using namespace std;

bool isprime(int x) {
    if (x == 2) return true;
    if (x <= 1 || x % 2 == 0) return false;
    int bound = sqrt(x);
    for (int i = 3; i <= bound; i += 2)
        if (x % i == 0) return false;
    return true;
}

void goldbachs(int x) {
    for (int i = 2; i < x - 1; i++) {
        if (isprime(i) && isprime(x - i)) {
            cout << i << " " << (x - i) << endl;
            return;
        }
    }
}

int main() {

    int a;
    while (cin >> a) {
        if (a < 8) {
            cout << "Impossible." << endl;
        } else if (a % 2 == 0) {
                cout << "2 2 ";
                goldbachs(a - 4);
        } else {
            cout << "2 3 ";
            goldbachs(a - 5);
        }
    }

    return 0;
}
