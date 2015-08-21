#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

/* ACCEPTED 0.072 */

#define MAXN 10000

struct point
{
    double x, y;
};

typedef struct point point;

point a[MAXN];
int n;

int compare( const void *a, const void *b )
{
    point pa = * ( point * ) a;
    point pb = * ( point * ) b;

    return pa.x < pb.x;
}

double square( double n )
{
    return n*n;
}

/* returns distance squared */
double dist( point pa, point pb )
{
    return square( pa.x - pb.x ) + square( pa.y - pb.y );
}

int main()
{
    int i;

    while ( scanf("%i", &n ) == 1 && n != 0 )
    {
        for ( i = 0; i < n; i++ )
        {
            scanf("%lf %lf", &a[i].x, &a[i].y );
        }
        qsort( &a, n, sizeof( point ), compare );

        if ( n == 1 )
        {
            puts("INFINITY");
            continue;
        }
        else
        {
            double min = dist( a[0], a[1] );
            int i, j;
            for ( i = 0; i < n - 1; i++ )
                for ( j = i + 1; j < n && square( a[j].x - a[i].x ) < min; j++ )
                    if ( dist( a[j], a[i] ) < min )
                        min = dist( a[j], a[i] );
            min = sqrt( min );
            if ( min > 10000.0 )
                puts("INFINITY");
            else
                printf("%.4lf\n", min );
        }
    }

    return 0;
}
