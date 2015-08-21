#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.055 */

/*
This is the first program I have used a union find data structure
for. It is a very simple concept. Basically, it is just an array
that builds trees for components not necessarily connected. I will soon
apply it towards Kruskal's Algorithm
*/

#define MAXV 30000
#define MAXE 500000
#define TRUE 1
#define FALSE 0

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

typedef struct set_union set_union;
typedef struct point point;
typedef int bool;

set_union s;
point edges[MAXE];

int max( int a, int b )
{
    return ( a > b ) ? a : b;
}

int min( int a, int b )
{
    return ( a < b ) ? a : b;
}

int point_compare( const void *a, const void *b )
{
    point pa = *( point * ) a;
    point pb = *( point * ) b;

    if ( pa.x < pb.x )
        return -1;
    else if ( pa.x > pb.x )
        return 1;
    else
        return pa.y - pb.y;
}

void init()
{
    int i;

    for ( i = 0; i <= MAXV; i++ )
    {
        s.parent[i] = i;
        s.size[i] = 1;
    }
    s.nv = s.ne = 0;
}

int find( int x )
{
    return ( s.parent[x] == x ) ? x : find( s.parent[x] );
}

void union_sets( int a, int b )
{
    int x = find( a );
    int y = find( b );

    if ( x == y ) return;

    if ( s.size[x] >= s.size[y] )
    {
        s.size[x] = s.size[x] + s.size[y];
        s.parent[y] = x;
    }
    else
    {
        s.size[y] = s.size[x] + s.size[y];
        s.parent[x] = y;
    }
}

bool same_component( int x, int y )
{
    return ( find( x ) == find( y ) );
}

void solve()
{
    int i, max;

    for ( i = 0; i < s.ne; i++ )
        if ( !same_component( edges[i].x, edges[i].y ) )
            union_sets( edges[i].x, edges[i].y );

    max = 1;

    for ( i = 0; i < s.nv; i++ )
        if ( s.size[i] > max )
            max = s.size[i];

    printf("%i\n", max );
}

int main()
{
    int i, j, x, y, ncases;

    scanf("%i", &ncases );

    for ( i = 0; i < ncases; i++ )
    {
        init();

        scanf("%i %i", &s.nv, &s.ne );

        for ( j = 0; j < s.ne; j++ )
        {
            scanf("%i %i", &x, &y );
            edges[j].x = min( x, y );
            edges[j].y = max( x, y );
        }

        qsort( &edges, s.ne, sizeof( point ), point_compare );

        solve();
    }

    return 0;
}
