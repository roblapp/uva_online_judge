#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.023s
Category: string processing
Algorithm: KMP string matching
Info: pretty much directly copied from https://github.com/juanplopes/icpc/blob/master/uva/11475.cpp
*/

using namespace std;

void computePrefixSuffixTable(vector<int> &t, string &p) {
    t.assign(p.length() + 10, 0); /* + 10 just because... (only + 1 is needed) */
    int i = 1, j = 0;

    while (i < p.size()) {
        if (p[j] == p[i]) {
            i++; j++;
            t[i] = j;
        } else if (j == 0) {
            i++;
            t[i] = 0;
        } else {
            j = t[j];
        }
    }
}

/* the function will give us the length of the longest suffix of str that matches a prefix of pattern */
int modifiedKMPStringSearch(string &str, string &pattern) {
    vector<int> fv;
    computePrefixSuffixTable(fv, pattern);

    int i = 0, j = 0;
    int N = str.length();
    int M = pattern.length();

    while (i < N) {
        while (j < M) {
            if (pattern[j] == str[i]) {
                i++; j++;
            } else {
                break;
            }
        }
        if (j == 0) i++;
        if (i == N) return j; /* the worst case is that this returns j = 1 because the final char in str will match the first char in pattern */
        j = fv[j];
    }
    return 0;
}

int main() {
	string line, revStr;
	while (cin >> line) {
        revStr = string(line.rbegin(), line.rend());
        string temp = line.substr(0, line.length() - modifiedKMPStringSearch(line, revStr));
        cout << line + string(temp.rbegin(), temp.rend()) << endl;
	}
    return 0;
}
