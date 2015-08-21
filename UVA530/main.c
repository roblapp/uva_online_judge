#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.012 */

#define MAXN 100

unsigned int max( unsigned int a, unsigned int b )
{
    return ( a > b ) ? a : b;
}

unsigned int min( unsigned int a, unsigned int b )
{
    return ( a < b ) ? a : b;
}

void solve( unsigned int n, unsigned int k )
{
    unsigned int i, j = 0, ik;
    unsigned int x = max( k, n - k ) + 1, y = min( k, n - k );
    unsigned int top[MAXN], bottom[MAXN];

    unsigned long long int num = 1, den = 1;

    for ( i = x; i <= n; i++ )
        top[j++] = i;

    for ( i = 1; i <= y; i++ )
        bottom[i] = i;

    for ( i = 0; i < j; i++ )
    {
        for ( ik = 1; ik <= y; ik++ )
        {
            if ( top[i] % bottom[ik] == 0 && bottom[ik] != 1 )
            {
                top[i] /= bottom[ik];
                bottom[ik] = 1;
            }
        }
    }

    for ( i = 0; i < j; i++ )
        num *= top[i];

    for ( i = 1; i <= y; i++ )
        den *= bottom[i];

    printf("%llu\n", ( num / den ) );
}

int main()
{
    unsigned int n, k;

    while (  ( scanf("%i %i", &n, &k ) == 2 ) &&  ( n != 0 || k != 0 ) )
        solve( n, k );

    return 0;
}
