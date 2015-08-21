#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ACCEPTED 0.029 */

int main()
{
    int sa, lim, nterms, x = 0;
    long long int a;

    while ( scanf("%i %i", &sa, &lim ) == 2 && ( sa != -1 || lim != -1 ) )
    {
        nterms = 1;
        a = sa;
        x++;

        while ( a != 1 && a <= lim )
        {
            if ( a % 2 == 0 )
                a >>= 1;
            else
                a = 3*a + 1;
            nterms++;
        }
        if ( a > lim ) nterms--;

        printf("Case %i: A = %i, limit = %i, number of terms = %i\n", x, sa, lim, nterms );
    }

    return 0;
}
