#include <iostream>
#include <vector>

/*
Accepted: 0.006s
Description: 2d max sub array, dynamic programming
*/

using namespace std;

#define read cin

int findMaxRun(int dp[], int ncols) {
    int cnt;
    int temp;
    int result = 0;
    for (int i = 0; i < ncols; i++) {
        temp = 0;
        cnt = 0;
        for (int j = i; j < ncols; j++) {
            if (dp[j] == 0) {
                cnt = 0;
                temp = 0;
            } else {
                if (temp == 0)
                    temp = dp[j];
                cnt++;
                temp = min(temp, dp[j]);
                result = max(result, temp*cnt);
            }
        }
    }
    return result;
}

int main() {
	int nrows, ncols, x;

	while (read >> nrows >> ncols && (nrows != 0 || ncols != 0)) {
        int dp[nrows][ncols];
        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++) {
                read >> x;
                if (i == 0)
                    dp[0][j] = (x == 0) ? 1 : 0;
                else
                    dp[i][j] = (x == 0) ? dp[i-1][j] + 1 : 0;
            }
        }
        int res = 0;
        for (int i = 0; i < nrows; i++)
            res = max(res, findMaxRun(dp[i], ncols));
        cout << res << endl;
	}
    return 0;
}
