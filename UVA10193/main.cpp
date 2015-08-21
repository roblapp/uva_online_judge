#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cstring>
#include <cmath>

/* ACCEPTED 0.016s */
/*
Algorithm:

Euclidean GCD
*/

#define MAXLEN 30
#define DIFF 48

using namespace std;

unsigned int gcd(unsigned int a, unsigned int b) {
    return (b == 0) ? a : gcd(b, a%b);
}

int main() {

    int ncases;
    unsigned a, b;
    char line[MAXLEN + 1];
    FILE *fp = stdin;

    fscanf(fp, "%i", &ncases);

    for (int i = 0; i < ncases; i++) {
        fscanf(fp, "%s", line);
        a = b = 0;
        int len = strlen(line);
        for (int j = 0; j < len; j++) {
            a += (line[j] - DIFF) * pow(2, (len - j - 1));
        }
        fscanf(fp, "%s", line);
        len = strlen(line);
        for (int j = 0; j < len; j++) {
            b += (line[j] - DIFF) * pow(2, (len - j - 1));
        }
        bool found = false;

        if (a == b or gcd(a, b) > 1) {
            found = true;
        }
        if (found) printf("Pair #%i: All you need is love!\n", (i + 1));
        else printf("Pair #%i: Love is not all you need!\n", (i + 1));
    }

    fclose(fp);

    return 0;
}
