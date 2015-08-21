#include <stdio.h>
#include <stdlib.h>

#define MAXV 200
#define TRUE 1
#define FALSE 0

/* ACCEPTED */

struct vertex {

    int y;
    struct vertex *next;
};

struct graph {

    struct vertex *vertices[MAXV + 1];
    int nedges;
    int nvertices;
};

typedef struct vertex vertex;
typedef struct graph graph;


void insert_edge( graph *g, int src, int dest, int dir )
{
    vertex *temp = ( vertex * ) malloc ( sizeof( vertex ) );

    temp->y = dest;

    temp->next = g->vertices[src];

    g->vertices[src] = temp;

    if ( dir == TRUE )
        insert_edge( g, dest, src, FALSE );
    else
        g->nedges++;
}

int conflict( graph *g, int current_vertex, int col, int *colors )
{
    vertex *v = g->vertices[current_vertex];

    while ( v != NULL )
    {
        if ( *( colors + ( v->y ) ) == col ) return TRUE;

        v = v->next;
    }

    return FALSE;
}

int color( graph *g, int vertex, int *colors )
{
    if ( vertex >= ( g->nvertices ) )
        return TRUE;
    else
    {
        int i;

        for ( i = 1; i <= 2; i++ ) /* try coloring with n colors */
        {
            if ( !conflict( g, vertex, i, colors ) )
            {
                *( colors + vertex ) = i;

                if ( color( g, vertex + 1, colors ) ) return TRUE;
            }
        }

        *( colors + vertex ) = 0;

        return FALSE;
    }
}

int main()
{
    graph g;
    int m;
    int i;
    int x;
    int y;
    int *colors = ( int * ) malloc( MAXV * sizeof( int ) );

    while ( scanf("%i", &g.nvertices ) != EOF && g.nvertices != 0 )
    {
        g.nedges = 0;

        for ( i = 0; i < g.nvertices; i++ )
        {
            *( colors + i ) = 0;
            g.vertices[i] = NULL;
        }

        scanf("%i", &m );

        for ( i = 0; i < m; i++ )
        {
            scanf("%i %i", &x, &y );
            insert_edge( &g, x, y, TRUE );
        }

        if ( color( &g, 0, colors ) )
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }

    return 0;
}
