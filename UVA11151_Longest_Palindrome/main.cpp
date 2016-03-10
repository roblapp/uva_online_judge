#include <iostream>
#include <vector>

/*
Accepted: 0.013s
Category: string processing, dynamic programming
Algorithm: dynamic programming, longest palindromic subsequence
Info: copied directly from
http://www.geeksforgeeks.org/dynamic-programming-set-12-longest-palindromic-subsequence/
*/

using namespace std;

int longestPalindromicSubsequence(string &s) {
    int N = (int) s.length();
    if (N == 0) return 0;
    vector<vector<int> > dp(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        dp[i][i] = 1;

    for (int cl = 2; cl <= N; cl++) {
        for (int i = 0; i < N - cl + 1; i++) {
            int j = i + cl - 1;
            if (s[i] == s[j] and j == i + 1) {
                dp[i][j] = 2;
            } else if (s[i] == s[j]) {
                dp[i][j] = dp[i+1][j-1] + 2;
            } else {
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
    return dp[0][N-1];
}

int main() {
	int ncases;
	string line;

	cin >> ncases; getline(cin, line); /* drain newline */
	while (ncases--) {
        getline(cin, line);
        cout << longestPalindromicSubsequence(line) << endl;
	}
    return 0;
}
