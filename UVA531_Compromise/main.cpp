#include <iostream>
#include <vector>
#include <stack>

/*
Accepted: 0.009s
Category: string processing, dynamic programming
Algorithm: longest common subsequence
Info: the problem description was not very clear in that
initially I did not know there was more than 1 test case.
The i/o of this problem sucks!
*/

using namespace std;

void longestCommonSubsequence(vector<string> &va, vector<string> &vb) {
    int n = (int) va.size();
    int m = (int) vb.size();
    int dp[n+1][m+1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (va[i-1] == vb[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    stack<string> s;
    int i = n, j = m;
    while (i > 0 and j > 0) {
        if (va[i-1] == vb[j-1]) {
            s.push(va[i-1]);
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    bool first = true;
    while (!s.empty()) {
        if (first)
            cout << s.top();
        else
            cout << " " << s.top();
        first = false;
        s.pop();
    }
    cout << endl;
}

int main() {
	string line;

	while (1) {
        vector<string> va, vb;
        if (cin >> line) {
            if (line == "#")
                ; /* do nothing */
            else {
                va.push_back(line);
                while (cin >> line and line != "#")
                    va.push_back(line);
            }
        } else {
            break;
        }
        if (cin >> line) {
            if (line == "#")
                ; /* do nothing */
            else {
                vb.push_back(line);
                while (cin >> line and line != "#")
                    vb.push_back(line);
                longestCommonSubsequence(va, vb);
            }
        } else {
            break;
        }
	}
    return 0;
}
