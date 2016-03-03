#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.000s
Category: string processing, ad-hoc
Algorithm: use the fact that the length of any substring that is periodic must be a
divisor of the length of the string. Thus, compute the divisors and for each divisor
try matching strLen/div number of substrings to the string in question. For example,
if we have a string of len 20, the solution must be 1, 2, 4, 5, 10 or 20. So, if
we were trying to match substrings of len 4 we know that there will be 20/4 = 5 of them
to match.
*/

using namespace std;

/* returns number of divisors and places divisors in divisors vector */
int getDivisors(int n, vector<int> &divisors) {
    divisors.clear();
    int res = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            divisors.push_back(n/i);
            res += 2;
        }
    }
    sort(divisors.begin(), divisors.end());
    return res;
}

int main() {
	int ncases, ndiv, strLen, subStrLen, bound, startIndex, j, N = 0;
	bool found;
	string s, periodStr;
	vector<int> divisors;

	cin >> ncases;
	while (ncases--) {
        cin >> s;
        strLen = (int) s.length();
        ndiv = getDivisors(strLen, divisors) - 1; /* don't try last divisor... this is simply the length of the string and is the worst case scenario */
        found = false;
        for (int i = 0; i < ndiv and !found; i++) {
            subStrLen = divisors[i];
            bound = strLen / subStrLen - 1; /* try each of the possible substrings except the one at the beginning (since we are comparing beginning to the rest) */
            periodStr = s.substr(0, subStrLen); /* the substring that we are checking to see if the string in question is periodic with respect to this substring */
            startIndex = subStrLen;
            for (j = 0; j < bound; j++, startIndex += subStrLen)
                if (periodStr != s.substr(startIndex, subStrLen))
                    break;

            if (j == bound)
                found = true;
        }
        if (N++)
            cout << endl;
        if (found)
            cout << subStrLen << endl;
        else
            cout << strLen << endl;
	}
    return 0;
}
