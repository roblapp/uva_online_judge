#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* ACCEPTED 0.092 */

#define MAXROWS 10
#define MAXCOLS 100

struct cell
{
    int cost;
    int parent;
};

typedef struct cell cell;

cell m[MAXROWS + 1][MAXCOLS + 1];

void init()
{
    int i, j;

    for ( i = 0; i <= MAXROWS; i++ )
    {
        for ( j = 0; j <= MAXCOLS; j++ )
        {
            m[i][j].cost = INT_MAX;
            m[i][j].parent = -1;
        }
    }
}

/*

   x
 /
x- y
 \
   z

m by n matrix

*/

int min( int a, int b, int c )
{
    int r;
    if ( a < b )
        r = ( a < c ) ? a : c;
    else
        r = ( b < c ) ? b : c;
    return r;
}

int min_two( int a, int b )
{
    return ( a < b ) ? a : b;
}

void solve( int a[MAXROWS + 1][MAXCOLS + 1], int mr, int n )
{
    int i, k;
    int x, y, z;
    int p, px, py, pz;

    for ( i = 1; i <= mr; i++ )
        m[i][n].cost = a[i][n];

    for ( k = n - 1; k >= 1; k-- ) /* column iterator */
    {
        for ( i = mr; i >= 1; i-- ) /* row iterator */
        {
            x = m[i-1][k+1].cost;
            y = m[i][k+1].cost;
            z = m[i+1][k+1].cost;
            px = i - 1;
            py = i;
            pz = i + 1;

            if ( i == mr ) /* check if c is in row 0, column k + 1 */
            {
                z = m[1][k+1].cost;
                pz = 1;
            }
            if ( i == 1 )
            {
                x = m[mr][k+1].cost;
                px = mr;
            }

            /* x y z */
            if ( x < y )
            {
                if ( x < z ) /* x is smallest */
                    p = px;
                else if ( x > z ) /* z is smallest */
                    p = pz;
                else /* x = z */
                    p = min_two( px, pz );
            }
            else if ( x > y )
            {
                if ( y < z ) /* y is smallest */
                    p = py;
                else if ( y > z ) /* z is smallest */
                    p = pz;
                else /* y = z */
                    p = min_two( py, pz );
            }
            else /* x = y */
            {
                if ( x < z )
                    p = min_two( px, py );
                else if ( x > z )
                    p = pz;
                else /* x = y = z */
                    p = min( px, py, pz );
            }
            m[i][k].cost = a[i][k] + min( x, y, z );
            m[i][k].parent = p;
        }
    }
}

void construct_path( int i, int j, int mr, int n )
{
    if ( j < n )
    {
        printf("%i ", i );

        construct_path( m[i][j].parent, j + 1, mr, n );
    }
    else if ( j == n )
       printf("%i\n", i );
}

void show_path( int mr, int n )
{
    int i;
    int min = m[1][1].cost;
    int pos = 1;
    for ( i = 2; i <= mr; i++ )
    {
        if ( m[i][1].cost < min )
        {
            min = m[i][1].cost;
            pos = i;
        }
    }
    construct_path( pos, 1, mr, n );
    printf("%i\n", m[pos][1].cost );
}

int main()
{
    int a[MAXROWS + 1][MAXCOLS + 1];
    int i, j, mr, n;

   while ( scanf("%i %i\n", &mr, &n ) == 2 )
   {
        init();

        for ( i = 1; i <= mr; i++ )
            for ( j = 1; j <= n; j++ )
                scanf("%i", &a[i][j] );

        solve( a, mr, n );

        show_path( mr, n );
    }

    return 0;
}
