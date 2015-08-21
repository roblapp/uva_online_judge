#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/* ACCEPTED 1.882s */
/*
Algorithm:

String processing
*/

using namespace std;

#define MAXL 1000000
#define MAXDRAIN 100

bool is_same_chars(char *s, int i, int j);

int main() {

    char a[MAXL + 1];
    char line[MAXDRAIN];
    int n, i, j, N = 1;
    FILE *fp = stdin;

    while (fgets(a, MAXL + 1, fp)) {
        if (a[0] == '\n') break;
        printf("Case %i:\n", N++);
        fscanf(fp, "%i", &n);
        for (int x = 0; x < n; x++) {
            fscanf(fp, "%i %i", &i, &j);
            if (is_same_chars(a, min(i, j), max(i, j)) ) printf("Yes\n");
            else printf("No\n");
        }
        fgets(line, MAXDRAIN, fp);
    }

    fclose(fp);

    return 0;
}

bool is_same_chars(char *s, int i, int j) {
    int len = strlen(s);
    if (i >= len || j >= len || i < 0 || j < 0) return false;
    char c = s[i++];
    while (i <= j) {
        if (s[i] != c) return false;
        i++;
    }
    return true;
}
