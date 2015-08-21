#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.035 */

#define MAXV 101
#define TRUE 1
#define FALSE 0
#define BLACK 0
#define WHITE 1

struct vertex
{
    int y;
    struct vertex *next;
};

struct graph
{
    struct vertex *vertices[MAXV];
};

typedef struct vertex vertex;
typedef struct graph graph;
typedef int bool;

graph g;
int ne, nv, max;
int colors[MAXV];
int optimal[MAXV];


void insert_edge( int src, int dst, int dir )
{
    vertex *temp = ( vertex * ) malloc ( sizeof ( vertex ) );
    temp->y = dst;
    temp->next = g.vertices[src];
    g.vertices[src] = temp;
    if ( dir )
        insert_edge( dst, src, FALSE );
}

void init()
{
    int i;
    for ( i = 1; i < MAXV; i++ ) colors[i] = WHITE;
    for ( i = 1; i < MAXV; i++ ) optimal[i] = -1;
    max = 0;
}

void show()
{
    int i;
    bool seen = FALSE;
    printf("%i\n", max );
    for ( i = 1; i <= nv; i++ )
        if ( optimal[i] == BLACK )
        {
            if ( seen == TRUE )
                printf(" %i", i );
            else
                printf("%i", i );
            seen = TRUE;
        }
    putchar('\n');
}

bool conflict( int v )
{
    vertex *temp = g.vertices[v];

    for ( temp = g.vertices[v]; temp != NULL; temp = temp->next )
        if ( colors[ temp->y ] == BLACK )
            return TRUE;
    return FALSE;
}

int nblacks()
{
    int i, x = 0;
    for ( i = 1; i <= nv; i++ )
        if ( colors[i] == BLACK ) x++;
    return x;
}

void color( int v )
{
    int tm;
    int i;
    if ( v > nv )
    {
        if ( ( tm = nblacks() ) > max )
        {
            max = tm;
            for ( i = 1; i <= nv; i++ ) optimal[i] = colors[i];
        }
    }
    else
    {
        if ( conflict( v ) == FALSE )
        {
            colors[v] = BLACK;
            color( v + 1 );
        }

        colors[v] = WHITE;
        color( v + 1 );
    }
}

void init_graph()
{
    int i;
    for ( i = 1; i < MAXV; i++ ) g.vertices[i] = NULL;
}

int main()
{
    int i, j, ng, x, y;

    scanf("%i", &ng );

    for ( i = 0; i < ng; i++ )
    {
        /* insert edges */
        scanf("%i %i", &nv, &ne );

        init_graph();

        for ( j = 0; j < ne; j++ )
        {
            scanf("%i %i", &x, &y );
            insert_edge( x, y, TRUE );
        }
        init();
        color( 1 );
        show();
    }

    return 0;
}
