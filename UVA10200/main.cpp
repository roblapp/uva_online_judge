#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <climits>

/* ACCEPTED 0.052s */
/*
Algorithm:

mathematics, prime numbers, prime checking, designing efficient algorithms
*/

#define MAXN 10000

using namespace std;

bool is_prime(int n) {
    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 or n % 3 == 0) {
        return false;
    }
    for (int i = 5; i*i <= n + 1; i += 6) {
        if (n % i == 0 or n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    int nprimes[MAXN + 1];
    int np = 0, a, b, res;
    memset(nprimes, 0, sizeof(nprimes));
    for (int i = 0; i <= MAXN; i++) {
        if (is_prime(i*i + i + 41)) {
            np++;
        }
        nprimes[i] = np;
    }

    while (scanf("%i %i", &a, &b) == 2) {
        res = nprimes[b] - nprimes[a] + 1;
        if (!is_prime(a*a + a + 41)) res--;
       printf("%.2lf\n", (100.0*(res)) / (b - a + 1)+ 1e-9);
    }

    return 0;
}
