#include <iostream>
#include <cstdio>
#include <vector>
#include <iomanip>

/*
Accepted: 0.066s
Category: string processing, dynamic programming
Algorithm: Edit Distance (implementation based on a C implementation in the Algorithm Design Manual by Steven Skiena)
Info: The implementation is OK, but the printing process is ugly. Need to think of a better design for
printing the solution.
*/

using namespace std;

#define MATCH 0
#define INSERT 1
#define DELETE 2

struct Cell {
    int parent;
    int cost;
};

int match(char ca, char cb) {
    return (ca == cb) ? 0 : 1;
}

int indel(char c) {
    return 1;
}

void printEditDistanceSoln(vector<vector<Cell> > &dp, string &s, string &t, int i, int j, int &adjustedLen) {
    if (dp[i][j].parent == -1) return;
    if (dp[i][j].parent == MATCH) {
        printEditDistanceSoln(dp, s, t, i-1, j-1, adjustedLen);
        if (s[i] != t[j])
            cout << "C" << t[j];
        else
            return;
    } else if (dp[i][j].parent == INSERT) {
        printEditDistanceSoln(dp, s, t, i, j-1, adjustedLen);
        adjustedLen++;
        cout << "I" << t[j];
    } else { /* must be delete */
        printEditDistanceSoln(dp, s, t, i-1, j, adjustedLen);
        adjustedLen--;
        cout << "D" << s[i];
        i++;
    }
    cout << setw(2) << setfill('0') << i + adjustedLen;
}

/* computes the minimum number of edits to transform string s into t */
void getEditDistanceString(string &str, string &pat) {
    string s = " " + str;
    string t = " " + pat;
    int n = (int) s.length();
    int m = (int) t.length();
    vector<vector<Cell> > dp(n + 1, vector<Cell>(m + 1));
    int opt[3];
    for (int i = 0; i < m; i++) {
        dp[0][i].cost = i;
        dp[0][i].parent = (i > 0) ? INSERT : -1;
    }
    for (int i = 0; i < n; i++) {
        dp[i][0].cost = i;
        dp[i][0].parent = (i > 0) ? DELETE : -1;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            opt[MATCH] = dp[i-1][j-1].cost + match(s[i], t[j]);
            opt[INSERT] = dp[i][j-1].cost + indel(t[j]);
            opt[DELETE] = dp[i-1][j].cost + indel(s[i]);

            dp[i][j].cost = opt[MATCH];
            dp[i][j].parent = MATCH;
            for (int k = INSERT; k <= DELETE; k++) {
                if (opt[k] < dp[i][j].cost) {
                    dp[i][j].cost = opt[k];
                    dp[i][j].parent = k;
                }
            }
        }
    }
    int adjsutedLen = 0;
    printEditDistanceSoln(dp, s, t, n-1, m-1, adjsutedLen);
    cout << "E" << endl;
}

int main() {
	string sa, sb;

	while (1) {
        cin >> sa;
        if (sa == "#") break;
        cin >> sb;
        getEditDistanceString(sa, sb);
	}
    return 0;
}
