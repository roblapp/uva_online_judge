#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ACCEPTED 0.022 */

#define N 101
#define M 25001

bool v[M];

int iabs(int n) {
    return (n < 0) ? -n : n;
}

int partition(int s[], int n) {
    int i, j;
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += s[i + 1];
    }
    int W = sum >> 1;
    memset(v, 0, sizeof(v));
    v[0] = true;

    for (i = 1; i <= n; i++) {
        for (j = W; j >= 1; j--) {
            if (!v[j]) {
                v[j] = (s[i] <= j) ? v[j - s[i]] : false;
            }
        }
    }

    for (j = W; j >= 1 && !v[j]; j--);

    return (iabs(sum - j*2));
}

int main() {
    int i, j, n, ncases;
    int s[N];
    scanf("%i", &ncases);
    for (i = 0; i < ncases; i++) {
        scanf("%i", &n);
        for (j = 0; j < n; j++) {
            scanf("%i", &s[j + 1]);
        }
        printf("%i\n", partition(s, n));
    }

    return 0;
}
