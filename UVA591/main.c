#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.012 */

#define MAXB 50

int main()
{
    int i, c = 1, nb, avg, sum;
    int a[MAXB];

    while ( scanf("%i", &nb ) != EOF && nb != 0 )
    {
        avg = sum = 0;

        for ( i = 0; i < nb; i++ )
        {
            scanf("%i", &a[i] );
            avg += a[i];
        }

        avg /= nb;

        for ( i = 0; i < nb; i++ )
            if ( a[i] > avg )
                sum += a[i] - avg;

        printf("Set #%i\nThe minimum number of moves is %i.\n\n", c, sum );
        c++;
    }

    return 0;
}
