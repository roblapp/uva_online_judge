#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

/* ACCEPTED 0.013s */
/*
Algorithm: Ad Hoc
This problem was very straight forward I am not
sure why they would ever have this in a contest???
*/

#define MAXN 26
#define UPPER 65
#define LOWER 97
#define in cin

using namespace std;

typedef struct {
    char c;
    int freq;
} entry;

int compare(const void *pa, const void *pb) {
    entry a = *(entry *) pa;
    entry b = *(entry *) pb;

    if (a.freq > b.freq) return -1;
    else if (a.freq < b.freq) return 1;
    else {
        if (a.c < b.c) return -1;
        else return 1;
    }
}

int main() {

    entry a[MAXN];
    for (int i = 0; i < MAXN; i++) {
        a[i].c = ((char ) (i + UPPER));
        a[i].freq = 0;
    }
    char c;
    int n;
    in >> n;
    while ((c = getchar()) != EOF) {
        if (isalpha(c)) {
            if (islower(c)) a[c-LOWER].freq = a[c-LOWER].freq + 1;
            else a[c-UPPER].freq = a[c-UPPER].freq + 1;
        }
    }

    qsort(a, MAXN, sizeof(entry), compare);
    for (int i = 0; i < MAXN; i++) {
        if (a[i].freq > 0) {
            cout << a[i].c << " " << a[i].freq << endl;
        }
    }

    return 0;
}
