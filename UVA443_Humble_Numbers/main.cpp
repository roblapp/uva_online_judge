#include <iostream>
#include <vector>

/*
Accepted: 0.009s
Category: math, sequences
Algorithm: ugly numbers algorithm (UVa #136), dynamic programming
*/

using namespace std;

#define MAXN 5842

long long min4(long long a, long long b, long long c, long long d) {
    return min(min(a, b), min(c, d));
}

void computeHumbleNumbers(vector<long long> &v) {
        v.assign(MAXN, 0);
        v[0] = 1;

        long long last2 = 0;
        long long last3 = 0;
        long long last5 = 0;
        long long last7 = 0;

        for (int i = 1; i < MAXN; i++) {
            long long prev = v[i-1];

            while (2*v[last2] <= prev)
                last2++;
            while (3*v[last3] <= prev)
                last3++;
            while (5*v[last5] <= prev)
                last5++;
            while (7*v[last7] <= prev)
                last7++;

            v[i] = min4(2*v[last2], 3*v[last3], 5*v[last5], 7*v[last7]);
        }
}

int main() {
	int x;
	long long res;
	vector<long long> v;

	computeHumbleNumbers(v);
	while (cin >> x and x != 0) {
        res = v[x-1];
        if (x % 10 == 2 and x % 100 != 12)
            cout << "The " << x << "nd humble number is " << res << "." << endl;
        else if (x % 10 == 1 and x % 100 != 11)
            cout << "The " << x << "st humble number is " << res << "." << endl;
        else if (x % 10 == 3 and x % 100 != 13)
            cout << "The " << x << "rd humble number is " << res << "." << endl;
        else
            cout << "The " << x << "th humble number is " << res << "." << endl;
	}
    return 0;
}
