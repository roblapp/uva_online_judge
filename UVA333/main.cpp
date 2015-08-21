#include <iostream>
#include <cstdlib>
#include <cstdio>
/*
ACCEPTED: 0.069s
ATTEMPTS: 3
NOTES: It was not clear from the instructions that there would be blank lines... Otherwise I
would have gotten this right on the 1st attempt.
*/

#define MAXLINE 100
#define ISBN_DIGITS 10
#define DIFF 48
#define MYEOF -1

using namespace std;

int getline_trim(char *s, int digits[], bool *is_valid, FILE *fp) {
    char c;
    int i = 0;
    int ndigits = 0, j = 0;
    bool seen_char = false;
    while ((c = fgetc(fp)) != EOF && c != '\n') {
        if (!isspace(c)) {
            seen_char = true;
        }
        if (seen_char) {
            s[i++] = c;
            if (ndigits < ISBN_DIGITS) { /* If there are still valid digits */
               if ((ndigits == 9) && (c == 'X')) {
                    digits[j++] = 10;
                } else if (isdigit(c)) {
                    digits[j++] = (c - DIFF);
                }
            }
            if (((ndigits == 9) && (c == 'X')) || isdigit(c)) {
                ndigits++;
            }
        }
    }
    int k = i - 1;
    while (k >= 0 && s[k] == ' ') {
        s[k] = 0;
        k--;
    }
    k++;
    s[k] = '\0';
    if (ndigits != 10) {
        *is_valid = false;
    } else {
        *is_valid = true;
    }
    if (c == EOF) {
        return MYEOF;
    }
    return k;
}

void output(char *s, bool is_valid) {
    is_valid ? printf("%s is correct.\n", s) : printf("%s is incorrect.\n", s);
}

int main() {
    FILE *fp = stdin;
    char line[MAXLINE];
    int i, len, s2, digits[ISBN_DIGITS], s1[ISBN_DIGITS];
    bool is_valid;
    while ((len = getline_trim(line, digits, &is_valid, fp)) != MYEOF) {
        if (is_valid) { /* Keep checking... */
            s1[0] = digits[0];
            for (i = 1; i < ISBN_DIGITS; i++) {
                s1[i] = s1[i-1] + digits[i];
            }
            s2 = 0;
            for (i = 0; i < ISBN_DIGITS; i++) {
                s2 += s1[i];
            }
            output(line, (s2 % 11 == 0));
        } else { /* We have an invalid ISBN # */
            output(line, is_valid);
        }
    }
    fclose(fp);

    return 0;
}
