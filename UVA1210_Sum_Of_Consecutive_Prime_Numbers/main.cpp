#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Category: math-prime numbers
*/

using namespace std;

#define MAXN 10000

void primeSieve(int N, vector<int> &primes) {
    vector<bool> temp(N+1, true);
    temp[0] = temp[1] = false;
    for (int i = 2; i <= N; i++)
        for (int j = 2*i; j <= N; j += i)
            temp[j] = false;

    for (int i = 2; i <= N; i++)
        if (temp[i])
            primes.push_back(i);
}

int main() {
	int x;
	long long sum;
    vector<int> primes;
    vector<int> nways(MAXN + 1, 0);
    primeSieve(MAXN, primes);

    for (int i = 0; i < (int) primes.size(); i++) {
        sum = 0;
        for (int j = i; j < (int) primes.size(); j++) {
            sum += primes[j];
            if (sum <= MAXN)
                nways[sum]++;
        }
    }

    while (cin >> x and x != 0)
        cout << nways[x] << endl;

    return 0;
}
