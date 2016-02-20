#include <iostream>

/*
Accepted: 0.000s
Category: string processing, recursive parsing
Algorithm: recursive parsing
*/

using namespace std;

/* returns true if the string starting at index i is a valid slump, false otherwise */
bool isValidSlump(string &s, int &i, int N) {
    if (i >= N)
        return false;
    if (s[i] == 'D' or s[i] == 'E')
        i++;
    else
        return false;
    if (s[i] == 'F')
        while (s[i] == 'F')
            i++;
    else
        return false;
    if (s[i] == 'G') {
        i++; /* set index to next char */
        return true; /* requires additional checking in the function's caller */
    }
    return isValidSlump(s, i, N);
}

/* returns true if the string starting at index i is a valid slimp, false otherwise */
bool isValidSlimp(string &s, int &i, int N) {
    if (i >= N)
        return false;
    if (s[i] == 'A')
        i++;
    else
        return false;
    if (s[i] == 'H') {
        i++; /* set index to next char */
        return true; /* requires additional checking in the function's caller */
    } else {
        if (s[i] == 'B') {
            i++;
            if (!isValidSlimp(s, i, N))
                return false;
        } else {
            if (!isValidSlump(s, i, N))
                return false;
        }
        /* in both cases we need to make sure the last char is a 'C' */
        if (s[i] == 'C') {
            i++; /* set index to next char */
            return true; /* requires additional checking in the function's caller */
        }
    }
    return false;
}

bool isValidString(string &s) {
    int i = 0, N = s.length();

    if (s[i] == 'A') {
        if (!isValidSlimp(s, i, N) or i >= N)
            return false;
        else { /* OK so far... */
            if (s[i] == 'D' or s[i] == 'E') {
                if (!isValidSlump(s, i, N))
                    return false;
                return (i == N);
            } else
                return false;
        }
    }
    return false;
}

int main() {
	int ncases;
	string line;

	cin >> ncases;
	cout << "SLURPYS OUTPUT" << endl;
	while (ncases--) {
        cin >> line;
        (isValidString(line)) ? cout << "YES" << endl : cout << "NO" << endl;
	}
	cout << "END OF OUTPUT" << endl;
    return 0;
}
