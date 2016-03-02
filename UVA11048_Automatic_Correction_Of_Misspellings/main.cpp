#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <sstream>

/*
Accepted: 0.057s
Category: string processing, string comparison
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
    if (qs.compare(ds) == 0)
        return SAME_STRING;
    /* Check for 1 wrong letter */
    int cnt = 0;
    for (int i = 0; qs[i]; i++)
        if (qs[i] != ds[i])
            cnt++;
    if (cnt == 1)
        return CANDIDATE_STRING;
    else if (cnt == 2) {
        int len = qs.length();
        cnt = 0;
        for (int i = 0; i < len - 1; i++)
            if (qs[i] != ds[i] and qs[i] == ds[i+1] and ds[i] == qs[i+1] and qs[i+1] != ds[i+1])
                cnt++;
        if (cnt == 1)
            return CANDIDATE_STRING;
    }
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
	int nd, nq, si, n, c;
	bool foundExact, foundWrong;
	string line;
	vector<string> v;

	cin >> nd;
	while (nd--) {
        cin >> line;
        v.push_back(line);
	}
	n = (int) v.size();
	cin >> nq;
	while (nq--) {
        cin >> line;
        foundExact = foundWrong = false;
        si = -1;
        for (int i = 0; i < n and !foundExact; i++) {
            c = candidate(line, v[i]);
            if (c == SAME_STRING)
                foundExact = true;
            else if (c == CANDIDATE_STRING and !foundWrong) {
                si = i;
                foundWrong = true;
            }
        }
        if (foundExact)
            cout << line << " is correct" << endl;
        else if (foundWrong)
            cout << line << " is a misspelling of " << v[si] << endl;
        else
            cout << line << " is unknown" << endl;
	}
    return 0;
}
