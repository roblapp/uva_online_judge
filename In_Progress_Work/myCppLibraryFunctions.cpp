

/* Generates primes up to N */
void primeSieve(int N, vector<bool> &primes) {
    primes.clear();
    primes.assign(N+1, true);
    primes[0] = primes[1] = false;
    for (int i = 2; i <= N; i++) {
        for (int j = 2*i; j <= N; j += i) {
            primes[j] = false;
        }
    }
}

