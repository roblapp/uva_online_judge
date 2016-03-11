#include <iostream>

/*
Accepted: 0.006s
Category: math, simulation
Algorithm: ad-hoc, brute force
*/

using namespace std;

#define MAXN 1000000

long long next(long long n) {
    return (n & 1) ? 3*n + 1 : n >> 1;
}

int computeCycleLen(long long cache[], long long n) {
    if (n == 0 or n == 1)
        return n;
    if (n < MAXN and cache[n] != 0)
        return cache[n];
    long long len = 1 + computeCycleLen(cache, next(n));
    if (n < MAXN)
        cache[n] = len;
    return len;
}

int main() {
	int low, hi, cnt;
	long long cache[MAXN] = {0};

	while (cin >> low >> hi and (low != 0 or hi != 0)) {
        if (low > hi)
            swap(low, hi);
        int maxVal = 0, maxLen = 0;
        for (int i = low; i <= hi; i++) {
            cnt = computeCycleLen(cache, next(i));
            if (cnt > maxLen) {
                maxLen = cnt;
                maxVal = i;
            }
        }
        cout << "Between " << low << " and " << hi << ", " << maxVal
                << " generates the longest sequence of " << maxLen << " values." << endl;
	}
    return 0;
}
