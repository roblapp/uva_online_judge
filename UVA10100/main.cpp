#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ACCEPTED 0.013s */
/*
Algorithm used:

I used a version of the longest common subsequence (LCS) algorithm
that uses dynamic programming. The general LCS recurrence is as follows:
Let M[i,j] represent the maximum length subsequence between 0 and the i_th and
j_th character in String0[0, ... , n] and String1[0, ... , m]. (Although in this problem we are matching entire words, not
just characters, but the algorithm is exactly the same except you compare words
at the i, j indices versus characters like the traditional LCS algorithm).

M[i,j] = 0 if i = 0 or j = 0
M[i,j] = 1 + M[i-1,j-1] if String0[i] = String1[j]
M[i,j] = max( M[i-1,j], M[i,j-1] ) otherwise
*/

#define MAXLINE 1000
#define MAXLEN 20

#define in cin
#define readc getchar()

using namespace std;

bool eof_read;

int get_line(char *s) {
    if (eof_read) return (-1);
    char c;
    int i = 0;
    while ((c = readc) != EOF && c != '\n') {
        s[i++] = c;
    }
    s[i] = 0;
    if (c == EOF) eof_read = true;
    return i;
}

int split( char *dst[], char line[] ) {
    int i = 0, j = 0, wc = -1, st = 0;
    while (line[i]) {
        if (isalnum(line[i])) {
            if (!st) wc++;
            st = 1;
            dst[wc][j] = line[i];
            j++;
        } else {
            if (st) dst[wc][j] = '\0';
            st = 0;
            j = 0;
        }
        i++;
    }
    if (st) dst[wc][j] = '\0';
    return wc + 1;
}

int longest_common_word_sequence(char *a[], char *b[], int n, int m) {

    int dp[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (strcmp(a[i-1], b[j-1]) == 0) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main() {

    char line[MAXLINE + 1];
    char *a[MAXLINE];
    char *b[MAXLINE];
    int N = 1;
    for (int i = 0; i < MAXLINE; i++) {
        a[i] = (char *) malloc(MAXLEN + 1);
        b[i] = (char *) malloc(MAXLEN + 1);
    }
    eof_read = false;

    while (get_line(line) >= 0) {
        int n = split(a, line);
        get_line(line);
        int m = split(b, line);

        if (n == 0 || m == 0) {
            printf("%2i. Blank!\n", N);
        } else {
            int x = longest_common_word_sequence(a, b, n, m);
            printf("%2i. Length of longest match: %i\n", N, x);
        }
        N++;
    }

    return 0;
}
