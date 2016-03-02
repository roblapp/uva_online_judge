#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <sstream>

/*
Accepted: 0.059s
Category: string comparison
Algorithm: string comparison
*/

using namespace std;

#define NOT_CANDIDATE_STRING -1
#define SAME_STRING 0
#define CANDIDATE_STRING 1
#define NALPHA 26
#define ASCII_DIFF 'a'

/* this assumes len(qs) == len(ds) */
int isReplacement(string &qs, string &ds) {
    int cnt = 0;
    for (int i = 0; cnt < 2 and qs[i]; i++)
        if (qs[i] != ds[i])
            cnt++;
    if (cnt == 0)
        return SAME_STRING;
    else if (cnt == 1)
        return CANDIDATE_STRING;
    return NOT_CANDIDATE_STRING;
}

/* this assumes len(qs) < len(ds) */
bool isOneCharDiff(string &qs, string &ds) {
    int j = 0, nskips = 0;
    for (int i = 0; nskips < 2 and qs[j] and ds[i]; i++)
        if (ds[i] == qs[j]) j++;
        else nskips++;
    return (nskips < 2);
}

int candidate(string &qs, string &ds) {
    int NQS = qs.length();
    int NDS = ds.length();
    int diff = abs(NDS - NQS);
    if (diff != 1 and diff != 0)
        return NOT_CANDIDATE_STRING;
    if (NQS == NDS) { /* check replacement */
        return isReplacement(qs, ds);
    } else if (NQS < NDS) {
        if (isOneCharDiff(qs, ds))
            return CANDIDATE_STRING;
    } else {
        if (isOneCharDiff(ds, qs))
            return CANDIDATE_STRING;
    }
    return NOT_CANDIDATE_STRING;
}

int main() {
	int ncases, c, n, N = 0;
	bool foundExactMatch;
	string line;

	cin >> ncases;
	while (ncases--) {
        vector<string> v;
        while (cin >> line and line[0] != '#')
            v.push_back(line);

        n = (int) v.size();
        if (N++)
            cout << endl;
        while (cin >> line and line[0] != '#') {
            foundExactMatch = false;
            stringstream ss("");
            ss << line << ":";
            for (int i = 0; i < n and !foundExactMatch; i++) {
                c = candidate(line, v[i]);
                if (c == SAME_STRING)
                    foundExactMatch = true;
                else if (c == CANDIDATE_STRING)
                    ss << " " << v[i];
            }
            if (foundExactMatch)
                cout << line << " is correct" << endl;
            else
                cout << ss.str() << endl;
        }
	}
    return 0;
}
