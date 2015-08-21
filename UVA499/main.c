#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.012 */

#define MAXLINE 1000

int lower[26];
int upper[26];
int max;

void init() {
    int i;
    for (i = 0; i < 26; i++) {
        lower[i] = upper[i] = 0;
    }
    max = -1;
}

int getline() {
    char c;
    int i = 0;
    while (( c = getchar()) != EOF && c != '\n') {
        i++;
        if (isalpha(c) && islower(c)) {
            lower[c - 97]++;
            if (lower[c - 97] > max) max = lower[c - 97];
        } else if (isalpha(c) && isupper(c)) {
            upper[c - 65]++;
            if (upper[c - 65] > max) max = upper[c - 65];
        }
    }
    return i;
}

int main() {
    int i;
    init();
    while (getline() > 0) {
        for (i = 0; i < 26; i++)
            if (upper[i] == max)
                putchar(i + 65);
        for (i = 0; i < 26; i++)
            if (lower[i] == max)
                putchar(i + 97);
        printf(" %i\n", max);
        init();
    }
    return 0;
}
