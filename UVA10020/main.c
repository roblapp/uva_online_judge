#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* ACCEPTED 0.096 */

#define MAXPAIRS 100000
#define TRUE 1
#define FALSE 0

typedef int bool;
typedef struct interval interval;

struct interval {

    int start, end;
    bool used;
};

interval s[MAXPAIRS];

int npairs;
int m;


int compare( const void *a, const void *b )
{
    interval ia = *( interval * ) a;
    interval ib = *( interval * ) b;
    return ia.start - ib.start;
}

void show( int ind[], int ni )
{
    int i;
    for ( i = 0; i < ni; i++ )
    {
        printf("%i %i\n", s[ ind[i] ].start, s[ ind[i] ].end );
    }
}

int furthest( int cur, int last_index )
{
    int i, maxi = -1;
    int max = INT_MIN;

    for ( i = last_index + 1; i < npairs && s[i].start <= cur; i++ )
    {
        if ( s[i].end > max && s[i].used == FALSE )
        {
            max = s[i].end;
            maxi = i;
        }
    }

    if ( maxi != -1 )
        s[maxi].used = TRUE;

    return maxi;
}

int main()
{
    int i, nc, last_index, ni;
    int x, y, cur;
    int ind[MAXPAIRS];
    bool found = FALSE;

    scanf("%i", &nc );

    for ( i = 0; i < nc; i++ )
    {
        ni = npairs = cur = 0;
        last_index = -1;

        scanf("%i", &m );

        while ( scanf("%i %i", &x, &y ) == 2 && ( x != 0 || y != 0 ) )
        {
            s[npairs].start = x;
            s[npairs].end = y;
            s[npairs].used = FALSE;
            npairs++;
        }

        qsort( &s, npairs, sizeof( interval ), compare );

        while ( cur < m )
        {
            last_index = furthest( cur, last_index );

            if ( last_index == -1 )
            {
                found = FALSE;
                break;
            }
            ind[ni++] = last_index;
            cur = s[last_index].end;
            found = TRUE;
        }

        if ( found == FALSE )
        {
            printf("0\n");
        }
        else
        {
            printf("%i\n", ni );
            show( ind, ni );
        }

        if ( i < nc - 1 )
            putchar('\n');
    }

    return 0;
}
