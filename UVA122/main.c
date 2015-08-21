#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.009 */

#define MAXLINE 1000
#define MAXN (1 << 16)
#define TRUE 1
#define FALSE 0

typedef int bool;

int tree[MAXN + 1];
char path[MAXN + 1];
int fe;

void init() {
    fe = 0;
    memset( tree, -1, sizeof( tree ) );
}

bool process_path( int digit ) {
    int i, len = strlen( path ), cp = 1;
    for ( i = 0; i < len; i++ ) {
        if ( path[i] == 'L' ) cp = cp << 1;
        else if ( path[i] == 'R' ) cp = (cp << 1) + 1;
    }
    if ( tree[cp] != - 1 ) return FALSE;
    tree[cp] = digit;
    if ( cp > fe ) fe = cp;
    return TRUE;
}

bool parse( char *line ) {
    int i = 0, j = 0, digit;
    char c;
    while ( ( c = line[i] ) != '\n' ) {
        if ( c == '(' ) {
            if ( line[i+1] == ')' ) return FALSE;
            j = digit = 0;
        } else if ( c == ')' ) {
            path[j] = 0;
            if ( !process_path( digit ) ) return FALSE;
        } else if ( isdigit( c ) ) {
            digit = 10*digit + (c - '0') % 10;
        } else if ( c == 'L' || c == 'R' ) {
            path[j++] = c;
        }
        i++;
    }
    return TRUE;
}

bool climb( int n ) {
    while ( n >= 1 && tree[n] != -1 ) n >>= 1;
    return (n == 0);
}

int main() {
    int i;
    char line[MAXLINE];
    FILE *fp = stdin;
    init();
    LOOP: while ( fgets( line, MAXLINE, fp ) != NULL ) {
        if ( !parse( line ) ) {
            for ( i = fe; i >= 1; i-- ) {
                 if ( tree[i] != -1 && !climb( i ) ) {
                    printf("not complete\n");
                    init();
                    goto LOOP;
                 }
            }
            for ( i = 1; i <= fe; i++ ) {
                if ( tree[i] != -1 ) {
                    if ( i == fe ) printf("%i\n", tree[i] );
                    else printf("%i ", tree[i] );
                }
            }
            init();
        }
    }

    fclose(fp);
    return 0;
}
