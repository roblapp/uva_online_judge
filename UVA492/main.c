#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

/* ACCEPTED 0.045s */

#define MAXWORDLEN 1000000

int getline(char *s, FILE *fp) {
    char c;
    int i = 0;
    while ((c = fgetc(fp)) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

bool isvowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

/*  corey... and, of course, stanley toles... */
void process(char *s) {
    int i = 0;
    bool state = false, add_ay = false;
    char first_letter;
    while (s[i]) {
        if (isalpha(s[i])) {
            if (!state) {
                if (isvowel(s[i])) {
                    putchar(s[i]);
                    add_ay = true;
                } else {
                    first_letter = s[i];
                }
            } else {
                putchar(s[i]);
            }
            state = true;
        } else {
            if (state) {
                if (add_ay) {
                    printf("ay");
                    add_ay = false;
                } else {
                    printf("%c%s", first_letter, "ay");
                }
            }
            putchar(s[i]);
            state = false;
        }
        i++;
    }
    if (state) {
        if (add_ay) {
            printf("ay");
            add_ay = false;
        } else {
            printf("%c%s", first_letter, "ay");
        }
    }
}

int main() {

    char line[MAXWORDLEN];
    FILE *fp = stdin;
    while (getline(line, fp) > 0) {
        process(line);
        putchar('\n');
    }
    fclose(fp);
    return 0;
}
