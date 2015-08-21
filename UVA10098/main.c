#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED */

#define MAX 10

void swap( char *a, int i, int j )
{
    char temp = *( a + i );
    *( a + i ) = *( a + j );
    *( a + j ) = temp;
}

int permute( char *a )
{
    int j, k, n, r, s;

    n = strlen( a );

    j = n - 2;

    while ( j >= 0 && a[j] >= a[j+1] )
        j--;

    if ( j == - 1) return 0;

    k = n - 1;

    while ( k >= 0 && a[j] >= a[k] )
        k--;

    swap( a, j, k );

    r = n - 1;
    s = j + 1;

    while ( r > s )
    {
        swap( a, r, s );
        r--;
        s++;
    }

    return 1;
}

int compare( const void *x, const void *y )
{
    return * ( char * ) x - * ( char * ) y;
}

int main()
{
    int i, x;
    char *a = ( char * ) malloc ( MAX + 1 );

    scanf("%i", &x );

    for ( i = 0; i < x; i++ )
    {
        scanf("%s", a );

        qsort( a, strlen( a ), sizeof( char ), compare );

        printf("%s\n", a );

        while ( permute( a ) )
        {
            printf("%s\n", a );
        }

        printf("\n");
    }

    free( a );

    return 0;
}
