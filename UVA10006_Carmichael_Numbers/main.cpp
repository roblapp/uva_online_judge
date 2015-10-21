#include <iostream>
#include <cmath>

/*
Accepted: 0.166s
Description: prime sieve, mod pow
*/

#define MAXN 65000

using namespace std;

bool p[MAXN + 1];

unsigned long long modpow(unsigned long long base, unsigned long long exp, unsigned long long mod) {
    base %= mod;
    unsigned long long result = 1;
    while (exp > 0) {
        if (exp & 1) result = (result*base) % mod;
        base = (base*base) % mod;
        exp >>= 1;
    }
    return result;
}

bool isCarmichael(unsigned long long n) {
    if (p[n]) return false;
    for (unsigned long long i = 2; i < n; i++)
        if (i != modpow(i, n, n)) return false;
    return true;
}

int main(){
    unsigned long long x, i, j;
    for (i = 0; i <= MAXN; i++) p[i] = true;
    p[0] = p[1] = false;
    for (i = 2; i <= MAXN; i++) {
        for (j = 2*i; j <= MAXN; j += i) {
            p[j] = false;
        }
    }
    while (cin >> x && x != 0) {
        if (isCarmichael(x)) cout << "The number " << x << " is a Carmichael number." << endl;
        else cout << x << " is normal." << endl;
    }

    return 0;
}
