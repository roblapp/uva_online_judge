#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

/* ACCEPTED 0.012 */

#define MAXN 100
#define TRUE 1
#define FALSE 0

struct point
{
    double x, y;
};

typedef struct point point;
typedef int bool;

point a[MAXN + 1];
int n;

double dist( point pa, point pb)
{
    return sqrt( ( pa.x - pb.x ) * ( pa.x - pb.x ) + ( pa.y - pb.y ) * ( pa.y - pb.y ) );
}

void prims()
{
    int i;
    int j;
    int v;
    bool intree[n + 1];
    double distance[n + 1];
    double temp;
    double td = 0.0;

    for ( i = 0; i <= n; i++ ) intree[i] = FALSE;
    for ( i = 0; i <= n; i++ ) distance[i] = INT_MAX;

    v = 1;
    distance[v] = 0;

    for ( i = 0; i < n - 1; i++ )
    {
        intree[v] = TRUE;

        for ( j = 1; j <= n; j++ )
            if ( j != v && !intree[j] && dist( a[v], a[j] ) < distance[j] )
                distance[j] = dist( a[v], a[j] );

        v = 1;
        temp = INT_MAX;

        for ( j = 1; j <= n; j++ )
        {
            if ( !intree[j] && distance[j] < temp )
            {
                temp = distance[j];
                v = j;
            }
        }
        td += temp;
    }
    printf("%.2lf\n", td );
}

int main()
{
    int i, j;
    int ncases;

    scanf("%i", &ncases );

    for ( j = 0; j < ncases; j++ )
    {
        scanf("%i", &n );

        for ( i = 1; i <= n; i++ )
            scanf("%lf %lf", &a[i].x, &a[i].y );

        prims();

        if ( j < ncases - 1 ) printf("\n");
    }

    return 0;
}
