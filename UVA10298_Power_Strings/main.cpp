#include <iostream>
#include <set>

/*
Accepted: 0.236s
Category: string processing, ad-hoc
Algorithm: same as problem #10298 Power Strings
*/

using namespace std;

int getDivisors(int n, set<int> &divisors) {
    divisors.clear();
    int res = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            divisors.insert(i);
            res++;
            if (i != 1) {
                divisors.insert(n/i);
                res++;
            }
        }
    }
    return res;
}

int main() {
	int strLen, subStrLen, bound, startIndex, j;
	bool found;
	string s, periodStr;
	set<int> divisors;

	while (getline(cin, s) and s != ".") {
        strLen = (int) s.length();
        getDivisors(strLen, divisors);
        found = false;
        for (set<int>::iterator it = divisors.begin(); !found and it != divisors.end(); it++) {
            subStrLen = *it;
            bound = strLen / subStrLen - 1; /* try each of the possible substrings except the one at the beginning (since we are comparing beginning to the rest) */
            periodStr = s.substr(0, subStrLen); /* the substring that we are checking to see if the string in question is periodic with respect to this substring */
            startIndex = subStrLen;
            for (j = 0; j < bound; j++, startIndex += subStrLen)
                if (periodStr != s.substr(startIndex, subStrLen))
                    break;
            if (j == bound)
                found = true;
        }
        if (found)
            cout << (strLen / subStrLen) << endl;
        else
            cout << 1 << endl;
	}
    return 0;
}
