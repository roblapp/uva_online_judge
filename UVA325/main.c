#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

/* ACCEPTED 0.009s */

#define MAXLINE 10000

int getline_trim(char *s, FILE *fp) {
    char c;
    int i = 0;
    bool seen_char = false;
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        if (c == '*') return (-1);
        if (!isspace(c)) {
            seen_char = true;
        }
        if (seen_char) {
            s[i++] = c;
        }
    }

    int k = i - 1;

    while (k >= 0 && s[k] == ' ') {
        s[k] = 0;
        k--;
    }

    k++;
    s[k] = '\0';

    return k;
}

void show_is_valid(char *s, bool is_valid) {
    (is_valid) ? printf("%s is legal.\n", s) : printf("%s is illegal.\n", s);
}

void parse(char *s) {
    int i = 0;
    char c, prev = 0;
    bool seen_dec = false;
    bool seen_exp = false;
    bool must_find_digits = true;

    while ((c = s[i])) {
        if (c == '+' || c == '-') {
            if (prev != 0 && prev != 'e' && prev != 'E') {
                show_is_valid(s, false);
                return;
            }
        } else if (c == '.') {
            if (seen_exp || seen_dec || !isdigit(prev)) {
                show_is_valid(s, false);
                return;
            }
            must_find_digits = true;
            seen_dec = true;
        } else if (isdigit(c)) {
            while (isdigit(s[i])) {
                i++;
            }
            must_find_digits = false;
            i--;
            c = s[i];
        } else if (c == 'e' || c == 'E') {
            if (seen_exp || !isdigit(prev)) {
                show_is_valid(s, false);
                return;
            }
            seen_exp = true;
            must_find_digits = true;
        } else {
            show_is_valid(s, false);
            return;
        }

        prev = c;
        i++;
    }
    if (must_find_digits || (!seen_dec && !seen_exp)) {
        show_is_valid(s, false);
    } else {
        show_is_valid(s, true);
    }
}


int main() {

    char line[MAXLINE];
    FILE *fp = stdin;

    while (getline_trim(line, fp) >= 0) {
        parse(line);
    }

    fclose(fp);

    return 0;
}
