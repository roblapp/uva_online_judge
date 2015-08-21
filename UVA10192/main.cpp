#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>

/* ACCEPTED 0.019s */
/*
Algorithm:

Dynamic Programming - LCS

*/

#define MAXL 105

using namespace std;

int lcs(char *a, char *b, int n, int m) {

    int dp[MAXL + 1][MAXL + 1];

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 0; i <= m; i++)
        dp[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int my_getline(char *s, FILE *fp) {
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF && c != '\n')
        s[i++] = c;
    s[i] = 0;
    return i;
}

int main() {

    char a[MAXL + 2], b[MAXL + 2];
    int n, m, k = 1;

    FILE *fp = stdin;

    while (1) {
        my_getline(a + 1, fp);
        if (a[1] == '#') break;
        my_getline(b + 1, fp);
        if ((n = strlen(a + 1)) == 0 or (m = strlen(b + 1)) == 0) {
            cout << "Case #" << k++ << ": you can visit at most 0 cities." << endl;
        } else {
            cout << "Case #" << k++ << ": you can visit at most " << lcs(a, b, n, m) << " cities." << endl;
        }
    }
    fclose(fp);

    return 0;
}
