#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ACCEPTED 0.039 */

#define MAXLEN 100

char a[MAXLEN];
int len;

int compare( const void *a, const void *b ) {
    char ca = *(char *) a;
    char cb = *(char *) b;
    if ( ca < cb ) return -1;
    else if ( ca > cb ) return 1;
    return 0;
}

void sort( char *s, int pos, int n ) {
    qsort( (s + pos), n - pos, sizeof( char ), compare );
}

void swap( int i, int j ) {
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int permute() {
    int j = len - 2;
    while ( j >= 0 && a[j] >= a[j+1] )
        j--;
    if ( j == -1 ) return 0;
    swap( j, j + 1 );
    sort( a, j + 1, len );
    return 1;
}

void create( int n, int h ) {
    int i;
    for ( i = 0; i < n - h; i++ ) {
        a[i] = '0';
    }
    for ( i = n - h; i < n; i++ ) {
        a[i] = '1';
    }
    a[i] = 0;
    len = i;
}

int main() {
    int i, ncases, n, h, N = 0;
    scanf("%i", &ncases);
    for ( i = 0; i < ncases; i++ ) {
        scanf("%i %i", &n, &h );
        create( n, h );
        if ( N++ ) putchar('\n');
        printf("%s\n", a );
        while ( permute() ) {
            printf("%s\n", a );
        }
    }
    return 0;
}
