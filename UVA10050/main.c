#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.009 */

#define MAXS 3651
#define FRIDAY 6
#define SATURDAY 7
#define WEEK 7
#define TRUE 1
#define FALSE 0

typedef int bool;

bool a[MAXS];

void init()
{
    int i;
    for ( i = 0; i < MAXS; i++ ) a[i] = FALSE;
}

int main()
{
    /* num cases, num days, num parties, hartal, weekend one, weekend two */
    int i, j, k, count, nc, nd, np, h, wo, wt;

    scanf("%i", &nc );

    for ( i = 0; i < nc; i++ )
    {
        init();
        count = 0;
        wo = FRIDAY;
        wt = SATURDAY;
        scanf("%i", &nd );
        scanf("%i", &np );

        for ( j = 0; j < np; j++ )
        {
            scanf("%i", &h );

            for ( k = h; k <= nd; k += h)
                a[k] = TRUE;
        }

        for ( j = 1; j <= nd; j++ )
            if ( j == wo )
                wo += WEEK;
            else if ( j == wt )
                wt += WEEK;
            else if ( a[j] == TRUE )
                count++;
        printf("%i\n", count );
    }

    return 0;
}
