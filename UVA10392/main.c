#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ACCEPTED */

int main()
{
    int i;

    long long int x;

    while ( scanf("%lld", &x ) != EOF && x > 0 )
    {
        while ( x % 2 == 0 )
        {
            printf("    2\n");
            x /= 2;
        }

        for ( i = 3; i <= sqrt( x ); i += 2 )
        {
            while ( x % i == 0 )
            {
                printf("    %i\n", i );
                x /= i;
            }
        }

        if ( x > 1 )
            printf("    %lld\n", x );

        printf("\n");
    }

    return 0;
}
