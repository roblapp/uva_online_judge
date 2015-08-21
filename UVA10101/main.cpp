#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/* ACCEPTED 0.052s */
/*
Algorithm:
ad-hoc

*/

#define in cin
#define DIFF 48
#define MAXLEN 20
#define MAXSTRLEN 100

using namespace std;

const int p[] = {10000000, 100000, 1000, 100, 1};
const char *pstr[] = {"kuti", "lakh", "hajar", "shata", ""};

char *b[MAXLEN];
int bi = 0;

void copy_findex(const char *prefix, int index) {
    for (int j = 0; prefix[j] != 0; j++) {
        b[bi][index++] = prefix[j];
    }
    b[bi++][index] = 0;
}

void buffer(long long int x, const char *prefix, bool add_space) {
    int i = 0;
    if (x > 9) {
        b[bi][i++] = ((x / 10) + DIFF);
        b[bi][i++] = ((x % 10) + DIFF);
        if (add_space) b[bi][i++] = ' ';
        copy_findex(prefix, i);
    } else {
        b[bi][i++] = x + DIFF;
        if (add_space) b[bi][i++] = ' ';
        copy_findex(prefix, i);
    }
}

long long int resolve(long long int x) {

    int i = 0;
    while (i < 4 and x > 0) {
        if (x / p[i] > 0) {
            buffer(x/p[i], pstr[i], true);
            x = x % p[i];
        }
        i++;
    }

    return x;
}

int main() {

    long long int x;
    int n = 1;

    for (int i = 0; i < MAXLEN; i++) b[i] = (char *) malloc(MAXSTRLEN);

    while (in >> x) {
        if (x != 0) {
            int i = bi = 0;
            while (i < 5 and x > 0) {
                if (x / p[i] > 0) {
                    int k = resolve(x/p[i]);
                    if (k > 0) {
                        if (i < 4) buffer(k, pstr[i], true);
                        else buffer(k, pstr[i], false);
                    } else {
                        copy_findex(pstr[i], 0);
                    }
                    x = x % p[i];
                    i = 0;
                } else {
                    i++;
                }
            }

            printf("%4i. ", n++);
            for (int i = 0; i < bi; i++) {
                if (i > 0) putchar(' ');
                printf("%s", b[i]);
            }
            putchar('\n');
        } else {
            printf("%4i. 0\n", n++);
        }
    }

    for (int i = 0; i < MAXLEN; i++) free(b[i]);

    return 0;
}
