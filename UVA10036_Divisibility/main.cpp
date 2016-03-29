#include <iostream>
#include <vector>
#include <cmath>

/*
Accepted: 0.069s
Category: dynamic programming
Info: I pretty much copied this from the Internet. I understand about 90% of how
it works.
*/

using namespace std;

#define MAX_REMAINDER 100

int main() {
	int ncases, n, div, x;

	cin >> ncases;
	while (ncases--) {
        cin >> n >> div;
        int currentIndex = 1, prevIndex = 0;
        vector<vector<bool> > dp(2, vector<bool>(MAX_REMAINDER + 1, false)); /* space optimization: only need the current row and the prev row */
        dp[0][0] = dp[1][0] = true;
        for (int i = 0; i < n; i++) {
            cin >> x;
            x = abs(x);
            swap(currentIndex, prevIndex);
            dp[currentIndex].assign(MAX_REMAINDER + 1, false);
            for (int rem = 0; rem < MAX_REMAINDER; rem++) {
                if (dp[prevIndex][rem]) {
                    dp[currentIndex][(rem + (x % div) + div) % div] = true; /* I think we add div to keep things it positive */
                    dp[currentIndex][(rem + (-x % div) + div) % div] = true;
                }
            }
        }
        cout << (dp[currentIndex][0] ? "Divisible" : "Not divisible") << endl;
	}
    return 0;
}
