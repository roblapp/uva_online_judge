#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define MAXLEN 1000
#define MAXLINE 72
#define nextc fgetc(fp)
#define NEWLINE 0
#define SPACE 1

struct data {
    char str[MAXLEN];
    int lws, cc, ec;
};

typedef struct data data;
typedef enum state state;

FILE *fp;
FILE *fpout;

bool eof_read, candidate;
int pec, pwc, c;


void show(data *d) {
    printf("%s\nLWS: %i\tCC: %i\nec: %i\n\n",
           d->str, d->lws, d->cc, d->ec);
}

void init(data *d) {
    if (d->ec == SPACE) {
        d->lws = 1;
    } else {
        d->lws = 0;
    }
    d->cc = 0;
    d->str[0] = 0;
    d->ec = -1;
}

bool get_next(data *d) {
    init(d);
    char c;
    bool seen_char = false, end_of_word = false;
    int i = 0;
    while (!end_of_word) {
        c = nextc;
        if (c == EOF) return false;
        if (c == ' ') {
            if (!seen_char) {
                d->lws = d->lws + 1;
            } else {
                d->ec = SPACE;
                end_of_word = true;
            }
        } else if (c == '\n') {
            d->ec = NEWLINE;
            end_of_word = true;
        } else {
            seen_char = true;
            d->str[i++] = c;
            d->str[i] = 0;
            d->cc++;
        }
    }
    return true;
}

void print_nchars(int n, char c) {
    int i;
    for (i = 0; i < n; i++) {
        putc(c, fpout);
    }
}

void print(char *format_string, char *print_string) {
    fprintf(fpout, format_string, print_string);
    fprintf(stdout, format_string, print_string);
}

void process(data *d) {
    if (pec == SPACE) {

    } else if (pec == NEWLINE) {

    } else {
        if (d->cc > 0) {
            if (d->lws + d->cc > MAXLINE) {
                print_nchars(1, '\n');
                print("%s", d->str);
                c = d->cc;
            } else {
                print_nchars(d->lws, ' ');
                print("%s", d->str);
                c = d->lws + d->cc;
            }

            if (d->ec == NEWLINE) {
                candidate = true;
            }

        } else {
            print_nchars(1, '\n');
            c = 0;
        }
    }
}

int main() {

    fp = fopen("test.txt", "r");
    fpout = fopen("testout.txt", "w");

    data *d = (data *) malloc(sizeof(data));
    candidate = true;
    pwc = c = 0;
    pec = -1;

    while (get_next(d)) {
        //show(d);
        process(d);
        pec = d->ec;
    }

    free(d);

    fclose(fpout);

    fclose(fp);

    return 0;
}
