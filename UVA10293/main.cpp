#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

/* ACCEPTED 0.025s */
/*
Algorithm:

ad-hoc, string processing

*/

#define IN 1
#define OUT 0
#define MAXLEN 30
#define MAXLINE 100

using namespace std;

int f[MAXLEN + 1];

bool parse(FILE *fp) {
    char c;
    int state = OUT;
    int len = 0;
    bool is_prev_hyphen = false;
    /* separators: ' ', ?, !, ',', '.' */
    while (1) {
        c = fgetc(fp);
        if (c == EOF) return false;
        if (c == '#') break;
        if (c == '-') {
            if (state == IN) {
                is_prev_hyphen = true;
            } else {
                is_prev_hyphen = false;
            }
        } else if (c == '\n') {
            if (is_prev_hyphen) state = IN;
            else if (state == IN) {
                f[len]++;
                len = 0;
                state = OUT;
            }
            else state = OUT;
            is_prev_hyphen = false;
        } else if (c == '\'') {

        } else if (c != ' ' and c != '?' and c != '!' and c != ',' and c != '.' and c != '\n') { /* c must be a countable letter */
            len++;
            state = IN;
            is_prev_hyphen = false;
        } else {
            if (state == IN) {
                f[len]++;
                len = 0;
            }
            state = OUT;
            is_prev_hyphen = false;
        }
    }

    if (state == IN) {
        f[len]++;
    }

    return true;
}


int main() {

    memset(f, 0, sizeof(f));
    char line[MAXLINE + 1];
    FILE *fp = stdin;
    while (parse(fp)) {
        fgets(line, MAXLINE + 1, fp); /* drain rest of the line */
        for (int i = 1; i <= MAXLEN; i++) {
            if (f[i] > 0) printf("%i %i\n", i, f[i]);
        }
        putchar('\n');
        memset(f, 0, sizeof(f));
    }
    fclose(fp);
    return 0;
}
