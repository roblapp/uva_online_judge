#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.188 */

#define MAXN 1000000
#define TRUE 1
#define FALSE 0

int primes[MAXN + 1];

void generate_primes()
{
    int i, j;

    for ( i = 0; i <= MAXN; i++ )
        primes[i] = TRUE;

    primes[0] = primes[1] = FALSE;

    for ( i = 2; i <= MAXN; i++ )
        for ( j = 2*i; j <= MAXN; j += i )
            primes[j] = FALSE;
}

void solve( int n )
{
    int i = 0;
    int j = n;

    while ( !primes[i] || !primes[j] || i + j != n )
    {
        if ( i + j < n )
            i++;
        else
            j--;
    }
    printf("%i = %i + %i\n", n, i, j );
}

int main()
{
    int n;

    generate_primes();

    while ( ( scanf("%i", &n ) == 1 ) && n != 0 )
        solve( n );

    return 0;
}
