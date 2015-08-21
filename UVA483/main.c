#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/* ACCEPTED 0.015 */

#define MAXLEN 1000

void reverse(char *s) {
    int i, len = strlen(s);
    for (i = 0; i < len >> 1; i++) {
        char temp = s[i];
        s[i] = s[len - 1 - i];
        s[len - 1 - i] = temp;
    }
}

int split_process(char *s) {
    int i = 0, k = 0, nwords = 0;
    bool state = false;
    char data[MAXLEN];
    while (s[i]) {
        if (!isspace(s[i])) {
            data[k++] = s[i];
            state = true;
        } else {
            if (state) {
                data[k] = 0;
                k = 0;
                reverse(data);
                printf("%s", data);
                nwords++;
            }
            putchar(s[i]);
            state = false;
        }
        i++;
    }
    if (state) {
        data[k] = 0;
        reverse(data);
        printf("%s", data);
        nwords++;
    }
    putchar('\n');
    return nwords;
}

int getline(char *s, FILE *fp) {
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int main() {

    char line[MAXLEN];

    FILE *fp = stdin;

    while (getline(line, fp) > 0) {
        split_process(line);
    }

    fclose(fp);

    return 0;
}
