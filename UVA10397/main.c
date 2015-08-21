#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ACCEPTED 0.229 */
/*
I am not satisfied with this runtime. Someone suggested
to apply constraints on the points so you don't have to
consider all N^2 distances between points...
*/

#define MAXV 750
#define MAXEDGES 280875

struct set_union
{
    int parent[MAXV + 1];
    int size[MAXV + 1];
    int nv;
    int ne;
};

struct point
{
    int x, y;
};

struct edge_pair
{
    int va, vb;
    double dist;
};

typedef struct set_union set_union;
typedef struct point point;
typedef struct edge_pair edge_pair;

set_union s;
point p[MAXV + 1];
edge_pair e[MAXEDGES];

void init()
{
    int i;

    s.nv = s.ne = 0;

    for ( i = 0; i <= MAXV; i++ )
    {
        s.parent[i] = i;
        s.size[i] = 1;
    }
}

double dist( point pa, point pb )
{
    return sqrt( ( ( double ) ( pa.x - pb.x ) * ( pa.x - pb.x ) ) +
                 ( ( double ) ( pa.y - pb.y ) * ( pa.y - pb.y ) ) );
}

int weight_compare( const void *a, const void *b )
{
    edge_pair ea = *( edge_pair * ) a;
    edge_pair eb = *( edge_pair * ) b;

    if ( ea.dist > eb.dist )
        return 1;
    else if ( ea.dist < eb.dist )
        return -1;
    else
        return 0;
}

int find( int x )
{
    return ( x == s.parent[x] ) ? x : find( s.parent[x] );
}

void union_sets( int x, int y )
{
    int a, b;

    a = find( x );
    b = find( y );

    if ( a == b ) return;

    if ( s.size[a] >= s.size[b] )
    {
        s.size[a] = s.size[a] + s.size[b];
        s.parent[b] = a;
    }
    else
    {
        s.size[b] = s.size[a] + s.size[b];
        s.parent[a] = b;
    }
}

int same_component( int x, int y )
{
    return ( find( x ) == find( y ) );
}

void kruskals()
{
    int i;
    double dist = 0;

    for ( i = 0; i < s.ne; i++ )
    {
        if ( !same_component( e[i].va, e[i].vb ) )
        {
            union_sets( e[i].va, e[i].vb );
            dist += e[i].dist;
        }
    }
    printf("%.2lf\n", dist );
}

int main()
{
    int i, j, k, np, nx, va, vb;

    while ( scanf("%i", &np ) != EOF )
    {
        init();

        s.nv = np;

        for ( i = 1; i <= np; i++ )
        {
            scanf("%i %i", &p[i].x, &p[i].y );
        }

        k = 0;

        for ( i = 1; i < np; i++ )
        {
            for ( j = i + 1; j <= np; j++ )
            {
                e[k].va = i;
                e[k].vb = j;
                e[k].dist = dist( p[i], p[j] );
                k++;
                s.ne++;
            }
        }

        scanf("%i", &nx );

        for ( i = 0; i < nx; i++ )
        {
            scanf("%i %i", &va, &vb );
            union_sets( va, vb );
        }

        qsort( &e, s.ne, sizeof( edge_pair ), weight_compare );

        kruskals();
    }

    return 0;
}
