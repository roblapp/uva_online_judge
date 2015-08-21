#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED */

#define MAX 800

int sqr( int x )
{
    int sum = 0;

    while ( x > 0 )
    {
        sum +=  ( x % 10 ) * ( x % 10 );
        x /= 10;
    }

    return sum;
}

void copy( int *a, int *current, int res )
{
    int i = 0;

    for ( i = 0; i < MAX; i++ )
        if ( *( current + i ) == 1 )
            *( a + i ) = res;
}

int is_happy( int *a, int x )
{
    int res = 0;
    int *current = ( int *  ) calloc( MAX, sizeof( int ) );

    x = sqr( x );

    while ( *( current + x ) == 0 && *( a + x ) == 0 )
    {
        *( current + x ) = 1;
        x = sqr( x );
    }

    if ( *( current + x ) == 1 || *( a + x ) == -1 ) /* number is NOT happy */
    {
        copy( a, current, -1 );
    }
    else /* number IS happy */
    {
        copy( a, current, 1 );
        res = 1;
    }

    free( current );

    return res;
}

int main()
{
    int i, ncases, x;

    int *a = ( int * ) calloc( MAX, sizeof( int ) );

    *( a + 1 ) = 1; /* 1 is a happy number */

    scanf("%i", &ncases );

    for ( i = 0; i < ncases; i++ )
    {
        scanf("%i", &x );

        if ( is_happy( a, x ) )
            printf("Case #%i: %i is a Happy number.\n", ( i + 1 ), x );
        else
            printf("Case #%i: %i is an Unhappy number.\n", ( i + 1 ), x );
    }

    free( a );

    return 0;
}
