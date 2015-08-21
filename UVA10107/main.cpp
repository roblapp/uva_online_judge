#include <iostream>
#include <string.h>

/* ACCEPTED 0.055s */
/*
Algorithm:
maintain a sorted array by using the insertion algorithm
from insertion sort. I am a little surprised this ran as
quickly as it did since it is an O(N^2) algorithm :/.

Possible alternatives:
Some kind of balanced binary search tree?
*/

#define MAXN 10000

using namespace std;

int main() {

    int i = 0, j, n;

    long long int a[MAXN];
    memset(a, -1, sizeof(a));

    while (cin >> n) {
        if (i == 0) {
            a[i++] = n;
        } else {
            j = i - 1;
            while (j >= 0 && a[j] > n) {
                a[j+1] = a[j];
                j--;
            }
            a[j+1] = n;
            i++;
        }
        int mid = i >> 1;
        long long int median;
        if (i % 2 == 0) {
            int mid2 = mid - 1;
            median = (a[mid] + a[mid2]) >> 1;
        } else {
            median = a[mid];
        }
        cout << median << endl;
    }

    return 0;
}
