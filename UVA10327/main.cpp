#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/* ACCEPTED 0.079s */
/*
Algorithm:

Bubble sort, sorting
*/

#define MAXN 1000

using namespace std;

int main() {

    int n;
    int a[MAXN];
    int cnt;
    bool swapped;

    while (scanf("%i", &n) == 1) {
        for (int i = 0; i < n; i++) {
            scanf("%i", &a[i]);
        }
        swapped = true;
        cnt = 0;
        for (int i = n - 1; i > 0 and swapped; i--) {
            swapped = false;
            for (int j = 0; j < i; j++) {
                if (a[j] > a[j+1]) {
                    swap(a[j], a[j+1]);
                    cnt++;
                    swapped = true;
                }
            }
        }

        printf("Minimum exchange operations : %i\n", cnt);
    }

    return 0;
}
