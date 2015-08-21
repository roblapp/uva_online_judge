#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* ACCEPTED 0.022 */

#define MAXV 100

int a[MAXV + 1][MAXV + 1];
int nvertices;


int max( int a, int b )
{
    return ( a > b ) ? a : b;
}

int min( int a, int b )
{
    return ( a < b ) ? a : b;
}

void init()
{
    int i, j;

    for ( i = 0; i <= MAXV; i++ )
        for ( j = 0; j <= MAXV; j++ )
            a[i][j] = INT_MAX;
}

void show()
{
    int i, j;

    for ( i = 1; i <= nvertices; i++ )
    {
        for ( j = 1; j <= nvertices; j++ )
        {
            printf("%i ", a[i][j] );
        }
        printf("\n");
    }
    printf("\n");
}

void floyd_warshall()
{
    int i, j, k;

    for ( k = 1; k <= nvertices; k++ )
    {
        for ( i = 1; i <= nvertices; i++ )
        {
            for ( j = 1; j <= nvertices; j++ )
            {
                if ( a[i][j] != INT_MAX || a[i][k] != INT_MAX || a[k][j] != INT_MAX )
                {
                    a[i][j] = min( a[i][j], max( a[i][k], a[k][j] ) );
                }
            }
        }
    }
}

int main()
{
    int i, c, s, q, x, y, w, count = 1, r;
    int blank = 0;

    while ( scanf("%i %i %i", &c, &s, &q ) == 3 && ( c != 0 && s != 0 && q != 0 ) )
    {
        init();
        nvertices = c;

        for ( i = 0; i < s; i++ )
        {
            scanf("%i %i %i", &x, &y, &w );
            a[x][y] = w;
            a[y][x] = w;
        }

        floyd_warshall();

        if ( blank ) printf("\n");
        blank = 1;

        printf("Case #%i\n", count++ );

        for ( i = 0; i < q; i++ )
        {
            scanf("%i %i", &x, &y );

            r = a[x][y];

            if ( r == INT_MAX )
                printf("no path\n");
            else
                printf("%i\n", r );
        }
    }

    return 0;
}
