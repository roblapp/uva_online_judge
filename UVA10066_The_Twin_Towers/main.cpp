#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Category: dynamic programming - longest common subsequence
Algorithm: dynamic programming - longest common subsequence
*/

using namespace std;

int longestCommonSequence(vector<int> &va, vector<int> &vb, int n, int m) {
    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (va[i-1] == vb[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int main() {
	int n, m, x, N = 1;

	while (cin >> n >> m and (n != 0 or m != 0)) {
        vector<int> va, vb;
        for (int i = 0; i < n; i++) {
            cin >> x;
            va.push_back(x);
        }
        for (int i = 0; i < m; i++) {
            cin >> x;
            vb.push_back(x);
        }
        cout << "Twin Towers #" << N++ << endl;
        cout << "Number of Tiles : " << longestCommonSequence(va, vb, n, m) << endl;
        cout << endl;
	}
    return 0;
}
