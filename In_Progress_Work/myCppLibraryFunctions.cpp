

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

/* returns number of divisors and places divisors in divisors vector */
void getDivisors(int n, vector<int> &divisors) {
    divisors.clear();
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(), divisors.end());
}

/* found @ http://www.geeksforgeeks.org/searching-for-patterns-set-3-rabin-karp-algorithm/ */
/* q is a prime number (105943 works ok for smaller inputs) */
bool rabinKarp(string &s, string &pattern, int alphabetSize, int q) {
    int N = (int) s.length();
    int M = (int) pattern.length();
    int p = 0; /* has value for pattern */
    int t = 0; /* hash value for text */
    int h = 1;

    if (M > N) return false;
    /* the value of h would be pow(d, M-1) % q */
    for (int i = 0; i < M - 1; i++)
        h = (h * alphabetSize) % q;
    /* calculate the has value of pattern and first substring */
    for (int i = 0; i < M; i++) {
        p = (alphabetSize * p + pattern[i]) % q;
        t = (alphabetSize * t + s[i]) % q;
    }

    for (int i = 0; i <= N - M; i++) {
        if (p == t) {
            int j = 0;
            for ( ; j < M; j++)
                if (s[i+j] != pattern[j])
                    break;
            if (j == M)
                return true;
        }

        if (i < N - M) {
            t = (alphabetSize * (t - s[i]*h) + s[i+M]) % q;
            if (t < 0)
                t = t + q;
        }
    }
    return false;
}
