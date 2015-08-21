#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ACCEPTED 0.109s */

/* super easy problem... probably the easiest I have ever
encountered for a contest problem. How could this run time
be sped up? Maintain a dictionary that stores pairs after
they have been computed, then each time a pair is queried
we first check the dictionary */

#define MAXN 50

int a[MAXN];


int gcd(int a, int b) {
    return (b == 0) ? a : (gcd(b, a % b));
}

int main() {
    int i, j, n, sum;

    while (scanf("%i", &n) == 1 && n > 0) {
        for (i = 0; i < n; i++) {
            scanf("%i", &a[i]);
        }
        sum = 0;
        for (i = 0; i < n - 1; i++) {
            for (j = i + 1; j < n; j++) {
                if (gcd(a[i], a[j]) == 1) {
                    sum++;
                }
            }
        }
        double res = sqrt((6.0 * ((n - 1) * n / 2.0))  / (sum * 1.0));
        (sum == 0) ? printf("No estimate for this data set.\n") : printf("%.6lf\n", res);
    }

    return 0;
}
