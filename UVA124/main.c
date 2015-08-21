#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ACCEPTED 0.009 */

#define MAXN 26
#define MAXLINE 300
#define MAXCANDIDATES 100
#define DIFF 97
#define TRUE 1
#define FALSE 0

typedef int bool;

char a[MAXN], temp[MAXN];
int lena, nlarger[MAXN], d[MAXN][MAXN];
bool used[MAXN];

int compare( const void *a, const void *b ) {
    char ca = *(char *)a;
    char cb = *(char *)b;
    if ( ca < cb ) return -1;
    else if ( ca > cb ) return 1;
    return 0;
}

void init() {
    int i, j;
    for ( i = 0; i < MAXN; i++ ) {
        for ( j = 0; j < MAXN; j++ ) d[i][j] = 0;
        nlarger[i] = used[i] = FALSE;
    }
}

void update_helper( int x, int y ) {
    int r;
    for ( r = 0; r < MAXN; r++ ) {
        if ( r != y && d[r][x] == -1 ) {
            d[r][y] = -1;
            d[y][r] = 1;
        }
    }
    for ( r = 0; r < MAXN; r++ ) {
        if ( r != x && d[r][y] == 1 ) {
            d[r][x] = 1;
            d[x][r] = -1;
        }
    }
}

void update( char r, char s ) {
    int x = (r - DIFF), y = (s - DIFF);
    d[x][y] = -1;
    d[y][x] = 1;
    update_helper( x, y );
}

void compute_nlarger() {
    int i, j, x, col, cnt;
    for ( i = 0; i < lena; i++ ) {
        x = a[i] - DIFF;
        cnt = 0;
        for ( j = 0; j < lena; j++ ) {
            col = a[j] - DIFF;
            if ( x != col && (d[x][col] == -1 || d[x][col] == 0 ) )
                cnt++;
        }
        nlarger[x] = cnt;
    }
}

void get_data( char line[] ) {
    int i, c = 0;
    char x, y;
    for ( i = 0; line[i] != 0; i++ ) {
        if ( isalpha(line[i]) ) {
            if ( c == 0 ) {
                x = line[i];
                c++;
            } else {
                y = line[i];
                update( x, y );
                c = 0;
            }
        }
    }
}

int extract( char line[] ) {
    int i, c = 0, len = strlen( line );
    for ( i = 0; i < len; i++ )
        if ( isalpha(line[i]) && islower(line[i]) ) a[c++] = line[i];
    a[c] = 0;
    return c;
}

bool less_than( char a, char b ) {
    return ( a != b && (d[a-DIFF][b-DIFF] == -1 || d[a-DIFF][b-DIFF] == 0));
}

bool less_than_all( char c, int ub ) {
    int i;
    for ( i = 0; i < ub; i++ ) if ( !less_than( temp[i], c ) ) return FALSE;
    return TRUE;
}

void process_solution() {
    int i; for ( i = 0; i < lena; i++ ) if ( !less_than_all( temp[i], i ) ) return;
    printf("%s\n", temp );
}

void construct_candidates( int k, char prev, int c[], int *ncandidates ) {
    int i;
    *ncandidates = 0;
    for ( i = 0; i < lena; i++ ) {
        if ( !used[a[i]-DIFF] && nlarger[a[i]-DIFF] >= lena - k - 1 ) {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }
}

void backtrack( int k, char prev ) {
    if ( k == lena ) {
        temp[k] = 0;
        process_solution();
    }
    int i, ncandidates, c[MAXCANDIDATES];
    construct_candidates( k, prev, c, &ncandidates );
    for ( i = 0; i < ncandidates; i++ ) {
        temp[k] = a[c[i]];
        used[a[c[i]]-DIFF] = TRUE;
        backtrack( k + 1, a[c[i]] );
        used[a[c[i]]-DIFF] = FALSE;
    }
}

int main() {
    int N = 0;
    char line[MAXLINE];
    while ( fgets( line, MAXLINE, stdin ) != NULL ) {
        lena = extract( line );
        qsort( a, strlen( a ), sizeof( char ), compare );
        init();
        fgets( line, MAXLINE, stdin );
        get_data( line );
        compute_nlarger();
        if ( N++ ) putchar('\n');
        backtrack( 0, 0 );
    }
    return 0;
}
