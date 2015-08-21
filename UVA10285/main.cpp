#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

/* ACCEPTED 0.036s */
/*
Algorithm:

Dynamic Programming (I think...)

*/

#define MAXN 100

using namespace std;

int main() {

    int a[MAXN + 2][MAXN + 2];
    int m[MAXN + 2][MAXN + 2];
    char line[MAXN];
    int n, soln = 0, r, c;

    FILE *fp = stdin;

    fscanf(fp, "%i", &n);

    while (n--) {
        soln = 0;
        fscanf(fp, "%s %i %i", line, &r, &c);
        for (int i = 0; i <= MAXN + 1; i++) {
            for (int j = 0; j <= MAXN + 1; j++) {
                a[i][j] = 0;
                m[i][j] = 1;
            }
        }
        for (int i = 1; i <= r; i++) {
            for (int j = 1; j <= c; j++) {
                fscanf(fp, "%i", &a[i][j]);
            }
        }

        for (int k = 100; k >= 0; k--) {
            for (int i = 1; i <= MAXN; i++) {
                for (int j = 1; j <= MAXN; j++) {
                    if (a[i][j] == k) {
                        if (a[i][j] < a[i-1][j]) {
                            m[i][j] = max(m[i][j], m[i-1][j] + 1);
                        }
                        if (a[i][j] < a[i+1][j]) {
                            m[i][j] = max(m[i][j], m[i+1][j] + 1);
                        }
                        if (a[i][j] < a[i][j-1]) {
                            m[i][j] = max(m[i][j], m[i][j-1] + 1);
                        }
                        if (a[i][j] < a[i][j+1]) {
                            m[i][j] = max(m[i][j], m[i][j+1] + 1);
                        }
                        soln = max(soln, m[i][j]);
                    }
                }
            }
        }

        printf("%s: %i\n", line, soln);
    }

    fclose(fp);

    return 0;
}
