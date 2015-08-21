#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED 0.065 */

#define MAXN 1000
#define TRUE 1
#define FALSE 0

typedef int bool;

bool ps[MAXN + 1];
int dp[MAXN + 1];
int *primes;
int plen;

int max( int a, int b ) { return ( a > b ) ? a : b; }

void seive() {
    int i, j, np;
    memset( ps, TRUE, sizeof( ps ) );
    memset( dp, 0, sizeof( dp ) );
    ps[0] = FALSE;
    for ( i = 2; i <= MAXN; i++ ) {
        for ( j = 2*i; j <= MAXN; j += i ) {
            ps[j] = FALSE;
        }
    }
    np = dp[0] = 0;
    for ( i = 1; i <= MAXN; i++ ) {
        if ( ps[i] ) np++;
        dp[i] = np;
    }
    j = 0;
    plen = dp[MAXN];
    primes = (int *) calloc( dp[MAXN], sizeof( int ) );
    for ( i = 0; i <= MAXN; i++ ) {
        if ( ps[i] ) primes[j++] = i;
    }
}

void print_primes( int mid, int a, int b, int nprimes ) {
    int i, sti = max( 0, mid - b );
    printf("%i %i:", a, b );
    for ( i = 0; i < nprimes && sti < plen && primes[sti] <= a; i++, sti++ ) {
        printf(" %i", primes[sti] );
    }
    putchar('\n');
}

int main() {
    int a, b, c;
    seive();
    while ( scanf("%i %i", &a, &b ) == 2 ) {
        int x = dp[a] / 2;
        if ( dp[a] % 2 == 0 ) {
            c = 2*b;
        } else {
            c = 2*b - 1;
            x++;
        }
        print_primes( x, a, b, c );
        putchar('\n');
    }
    free( primes );

    return 0;
}
