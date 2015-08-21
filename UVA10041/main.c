#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ACCEPTED 0.032 */

#define MAXN 30000

int compare( const void *a, const void *b )
{
    return *( int * ) a - * ( int * ) b;
}

int main()
{
    int a[MAXN];
    int ncases;
    int n;
    int i;
    int j;
    int sum;
    int med;

    scanf("%i", &ncases );

    for ( i = 0; i < ncases; i++ )
    {
        scanf("%i", &n );

        for( j = 0; j < n; j++ )
            scanf("%i", &a[j] );

        qsort( a, n, sizeof( int ), compare );
        med = sum = 0;
        if ( n % 2 == 1 ) med = a[ ( n - 1 ) / 2];
        else med = ( a[ ( n / 2 ) ] + a[ ( n / 2 ) - 1 ] ) / 2;

        for  ( j = 0; j < n; j++ )
            sum += abs( med - a[j] );

        printf("%i\n", sum );
    }

    return 0;
}
