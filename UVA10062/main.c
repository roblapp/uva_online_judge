#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ACCEPTED 0.009 */

#define MAXLINE 1010
#define NCHARS 97
#define DIFF 32

struct entry {
    int cdata, f;
};

typedef struct entry entry;

int compare(const void* a, const void *b) {
    entry ea = *(entry *) a;
    entry eb = *(entry *) b;
    if ( ea.f == eb.f ) return eb.cdata - ea.cdata;
    return (ea.f - eb.f);
}

int main() {
    char c, line[MAXLINE + 1];
    entry freq[NCHARS];
    int i, N = 0;
    FILE *fp = stdin;

    while ( fgets(line, MAXLINE + 1, fp) != NULL ) {
        for ( i = 0; i < NCHARS; i++ ) {
            freq[i].f = 0;
            freq[i].cdata = i;
        }
        for ( i = 0; line[i] != '\n'; i++) {
            c = line[i];
            if ( c >= 32 && c <= 128 ) freq[c-DIFF].f = freq[c-DIFF].f + 1;
        }
        if (N++) putchar('\n');
        qsort(freq, NCHARS, sizeof(entry), compare);
        for ( i = 0; i < NCHARS; i++ ) {
            if ( freq[i].f > 0 ) {
                printf("%i %i\n", freq[i].cdata + DIFF, freq[i].f );
            }
        }
    }

    fclose(fp);

    return 0;
}
