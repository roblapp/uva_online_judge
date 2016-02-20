#include <iostream>
#include <vector>

/*
Accepted: 0.006s
Category: string processing, frequency counting
Algorithm(s): prime sieve, frequency counting
*/

using namespace std;

#define MAXN 2000
#define DIGIT_OFFSET 0
#define UPPER_CASE_OFFSET 10
#define LOWER_CASE_OFFSET (10+26)

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

int main() {
	int n, N = MAXN, freqLength = 10+26+26;
	string line;
	vector<bool> primes;
	primeSieve(N, primes);

	cin >> n;
	for (int i = 1; i <= n; i++) {
        cin >> line;
        vector<int> freq(freqLength, 0); /* the order is digits, uppercase, lowercase */
        for (int j = 0; line[j]; j++) {
            if (isdigit(line[j])) {
                freq[line[j]-'0'+DIGIT_OFFSET]++;
            } else if (isupper(line[j])) {
                freq[line[j]-'A'+UPPER_CASE_OFFSET]++;
            } else {
                freq[line[j]-'a'+LOWER_CASE_OFFSET]++;
            }
        }
        int charAsInt;
        bool foundOne = false;
        cout << "Case " << i << ": ";
        for (int j = 0; j < freqLength; j++) {
            if (primes[freq[j]]) {
                if (j < UPPER_CASE_OFFSET) { /* char is digit */
                    charAsInt = j + '0';
                } else if (j < LOWER_CASE_OFFSET) { /* char is upper case */
                    charAsInt = j - UPPER_CASE_OFFSET + 'A';
                } else { /* char is lower case */
                    charAsInt = j - LOWER_CASE_OFFSET + 'a';
                }
                cout << (char)(charAsInt);
                foundOne = true;
            }
        }
        if (!foundOne)
            cout << "empty";
        cout << endl;
	}
    return 0;
}
