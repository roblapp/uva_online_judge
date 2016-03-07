

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


/* returns true if s is a palindrome, false otherwise */
bool isPalindrome(string &s) {
    int N = (int) s.length(), halfLen = N >> 1;
    for (int i = 0; i < halfLen; i++)
        if (s[i] != s[N-1-i])
            return false;
    return true;
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


/* KMP */
void computePrefixSuffixTable(vector<int> &t, string &p) {
    int N = (int) p.length();
    int pos = 2;
    int cnd = 0;

    t.assign(N, 0);
    t[0] = -1;
    t[1] = 0;
    while (pos < N) {
        if (p[pos-1] == p[cnd]) {
            t[pos] = cnd + 1;
            cnd++;
            pos++;
        } else if (cnd > 0) {
            cnd = t[cnd];
        } else {
            t[pos] = 0;
            pos++;
        }
    }
}


int kmpStringSearch(string &s, string &p) {
    vector<int> t;
    computePrefixSuffixTable(t, p);
    int i = 0, m = 0, N = (int) s.length(), NP = (int) p.length();
    while (m + i < N) {
        if (p[i] == s[m+i]) {
            if (i == NP - 1) {
                return m;
            }
            i++;
        } else {
            if (t[i] > 0) {
                m = m + i - t[i];
                i = t[i];
            } else {
                i = 0;
                m++;
            }
        }
    }
    return N;
}
/* END KMP */


/* searches an nrows x ncols "matrix" of chars in all 8 possible directions for string s */
bool searchMatrix(vector<string> &v, int nrows, int ncols, string &s, int &solnRow, int &solnCol) {
    const int N = 8;
    int row, col, sindex, len = (int) s.length();
    int rowInc[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int colInc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (tolower(v[i][j]) == tolower(s[0])) {
                for (int k = 0; k < N; k++) {
                    row = i; col = j; sindex = 0;
                    while (row >= 0 and row < nrows and col >= 0 and col < ncols and
                            tolower(v[row][col]) == tolower(s[sindex])) {
                        sindex++;
                        if (sindex == len) {
                            solnRow = i + 1;
                            solnCol = j + 1;
                            return true;
                        }
                        row += rowInc[k];
                        col += colInc[k];
                    }
                }
            }
        }
    }
    return false;
}

