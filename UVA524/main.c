#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.502 */

#define MAXN 16
#define MAXP 31

#define TRUE 1
#define FALSE 0

int ring[MAXN + 1];
int primes[MAXP + 1];

void init_primes()
{
    int i, j;

    for ( i = 0; i <= MAXP; i++ )
        primes[i] = TRUE;

    primes[0] = primes[1] = FALSE;
    for ( i = 2; i <= MAXP; i++ )
        for ( j = 2*i; j <= MAXP; j += i )
            primes[j] = FALSE;

    for ( i = 0; i <= MAXN; i++ )
        ring[i] = 1;

}

void show_ring( int n )
{
    int i;

    for ( i = 1; i < n; i++ )
        printf("%i ", ring[i] );
    printf("%i\n", ring[n] );
}

int is_valid( int c, int num, int n )
{
    int i;

    for ( i = 2; i < c; i++ )
        if ( ring[i] == num )
            return FALSE;

    if ( !primes[ num + ring[c-1] ] )
        return FALSE;

    if ( c == n ) /* check wrap around */
        if ( !primes[ num + ring[1] ] )
            return FALSE;

    return TRUE;
}

void solve( int c, int n )
{
    if ( c > n )
        show_ring( n );
    else
    {
        int i;

        for ( i = 2; i <= n; i++ )
        {
            if ( is_valid( c, i, n ) )
            {
                ring[c] = i;
                solve( c + 1, n );
            }
        }
    }
}

int main()
{
    int n;
    int x = 1;
    int f = 0;

    init_primes();

    while ( scanf("%i", &n ) == 1 )
    {
        if ( f ) printf("\n");
        printf("Case %i:\n", x );
        solve( 2, n );
        x++;
        f = TRUE;
    }

    return 0;
}
