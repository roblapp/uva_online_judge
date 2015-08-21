#include <stdio.h>
#include <stdlib.h>

/*$2, $1, 50c, 20c, 10c and 5c */
int denomenations[] = {5, 10, 20, 50, 100, 200};

long long count_ways( int npennies )
{
    int i,j;
    long long *ways = (long long *) calloc( npennies + 1, sizeof(long long) );
    ways[0] = 1;

    for ( i = 0; i < 6; i++ )
    {
        for ( j = denomenations[i]; j <= npennies; j += 5 )
        {
            ways[j] = ways[j] + ways[j - denomenations[i] ];
        }
    }

    long long val = ways[npennies];

    free( ways );

    return val;
}

int main()
{
    int a = -1, b = -1, x;

    while ( 1 )
    {
        scanf("%i.%i", &a, &b);

        if ( a == 0 && b == 0 )
        {
            break;
        }

        x = 100*a + b;

        if ( a >= 0 && b >= 0)
        {
             printf("%3i.%.2i%17lli\n", a, b, count_ways( x ) );
        }
    }

    return 0;
}
