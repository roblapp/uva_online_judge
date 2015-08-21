#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 49

void combinations(int v[], bool contains[], int start, int n, int k, int maxk, int max_element) {

    int i;

    if (k > maxk) {
        for (i = 1; i <= maxk; i++) (i == 1) ? printf("%i", v[i]) : printf(" %i", v[i]);
        putchar('\n');
        return;
    }

    for (i = start; i <= max_element; i++) {
        if (contains[i]) {
            v[k] = i;
            combinations(v, contains, i + 1, n, k + 1, maxk, max_element);
        }
    }
}


int main() {

    int i, v[100], n, k = 6, N = 0;

    int x, max_element;

    bool contains[MAXN + 1];

    while (scanf("%i", &n) == 1 && n > 0) {
        max_element = 0;
        if (N++) putchar('\n');
        for (i = 0; i < MAXN + 1; i++) contains[i] = false;
        for (i = 0; i < n; i++) {
            scanf("%i", &x);
            contains[x] = true;
            if (x > max_element) {
                max_element = x;
            }
        }
        combinations(v, contains, 1, n, 1, k, max_element);
    }

    return 0;
}
