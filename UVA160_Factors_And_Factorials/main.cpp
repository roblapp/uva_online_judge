#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>

/*
Accepted: 0.000s
Description: prime sieve

I was clueless about this problem for over a year until I read this article:
    http://mathforum.org/library/drmath/view/67291.html
which explained the theory behind this problem.
*/

using namespace std;

void seive(int n, vector<int> &primeList) {
    int i, j;
    bool p[n + 1];
    memset(p, true, sizeof(p));
    p[0] = p[1] = false;
    for (i = 2; i <= n; i++)
        for (j = 2*i; j <= n; j += i)
            p[j] = false;
    primeList.clear();
    for (i = 0; i <= n; i++)
        if (p[i]) primeList.push_back(i);
}

int main(){
    int i, n, p, sum, numCount;
    vector<int> primes;
    vector<int>::iterator it;
    seive(100, primes);
    while (cin >> n and n != 0) {
        printf("%3i! =", n);
        numCount = 0;
        for (it = primes.begin(); it != primes.end() and *it <= n; it++) {
            i = p = *it;
            sum = 0;
            while (i <= n) {
                sum += n/i;
                i *= p;
            }
            if (numCount > 0 and numCount % 15 == 0)
                printf("\n      ");
            printf("%3i", sum);
            numCount++;
        }
        printf("\n");
    }
    return 0;
}
