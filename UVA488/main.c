#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.339 */

void wave(int n, int amp, int x )
{
    if ( n == 0 ) return;

    int i;

    for ( i = 0; i < n; i++ )
       printf("%i", n );
    printf("\n");
    if ( x >= amp )
        wave( n - 1, amp, x + 1 );
    else
        wave( n + 1, amp, x + 1 );
}

int main()
{
    int i, j, ncases, amp, freq;

    scanf("%i", &ncases );

    for ( i = 0; i < ncases; i++ )
    {
        scanf("%i %i", &amp, &freq );

        for ( j = 0; j < freq; j++ )
        {
            wave( 1, amp, 1 );

            if ( !( j == freq - 1 && i == ncases - 1 ) )
                printf("\n");
        }
    }

    return 0;
}
