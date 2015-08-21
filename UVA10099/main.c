#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* ACCEPTED 0.019 */

/*
In all honesty I did see what the problem was requiring, however, I did
not know how to implement it. So I looked it up on quest to solve and
it uses a minimax Floyd-Warshall algorithm described below.
*/

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
            a[i][j] = -1;
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
                if ( a[i][j] != -1 || a[i][k] != -1 || a[k][j] != -1 )
                {
                    a[i][j] = max( a[i][j], min( a[i][k], a[k][j] ) );
                }
            }
        }
    }
}

int main()
{
    int ne;
    int i;
    int x, y, w;
    int count = 1;

    while ( ( scanf("%i %i", &nvertices, &ne ) == 2 ) && ( nvertices != 0 && ne != 0 ) )
    {
        init();

        for ( i = 0; i < ne; i++ )
        {
            scanf("%i %i %i", &x, &y, &w );
            a[x][y] = w;
            a[y][x] = w;
        }

        scanf("%i %i %i", &x, &y, &w );

        floyd_warshall();

        double r = ceil( ( 1.0 * w ) / ( a[x][y] - 1 ) );

        printf("Scenario #%i\nMinimum Number of Trips = %i\n\n", count, ( int ) r );

        count++;
    }

    return 0;
}
