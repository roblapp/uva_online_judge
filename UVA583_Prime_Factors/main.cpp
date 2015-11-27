#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>

/*
Accepted: 0.269s
Description: factoring
*/

using namespace std;

#define read cin

int generatePrimes(vector<int> &v) {
    v.clear();
    int MAXP = 46341; /* sqrt(int_max) + 1 */
    bool primes[MAXP];
    for (int i = 0; i <= MAXP; i++ )
        primes[i] = true;
    primes[0] = primes[1] = false;
    for (int i = 2; i <= MAXP; i++)
        for (int j = 2*i; j <= MAXP; j += i)
            primes[j] = false;
    int nfactors = 0;
    for (int i = 0; i <= MAXP; i++ ) {
        if (primes[i]) {
            v.push_back(i);
            nfactors++;
        }
    }
    return nfactors;
}

void factor(int n, vector<int> &primes, vector<int> &factors) {
    factors.clear();
    if (n < 0)
        factors.push_back(-1);
    n = abs(n);
    if (n <= 2) {
        factors.push_back(2);
        return;
    }
    int p;
    for (vector<int>::iterator it = primes.begin(); it != primes.end(); it++) {
        p = *it;
        if (p*p > n) break;
        while (n % p == 0) {
            factors.push_back(p);
            n /= p;
        }
    }
    if (n > 1)
        factors.push_back(n);
}

int main() {
    vector<int> primes, factors;
    int n;
    generatePrimes(primes);
    while (read >> n && n != 0) {
        factor(n, primes, factors);
        stringstream ss("");
        ss << n << " = ";
        for (int i = 0, len = factors.size(); i < len; i++) {
            if (i == 0) ss << factors[i];
            else ss << " x " << factors[i];
        }
        cout << ss.str() << endl;
    }
    return 0;
}
