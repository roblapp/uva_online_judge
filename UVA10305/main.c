#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.012 */

#define MAXT 100
#define TRUE 1
#define FALSE 0

struct vertex {

    int y;
    struct vertex *next;
};

struct graph {

    struct vertex *vertices[MAXT + 1];
    int nvertices;
    int nedges;
};

typedef struct vertex vertex;
typedef struct graph graph;
typedef int bool;

graph g;
bool discovered[MAXT + 1];
int stack[MAXT + 1];
int pi;

void init()
{
    int i;
    for ( i = 0; i <= MAXT; i++ )
    {
        g.vertices[i] = NULL;
        discovered[i] = FALSE;
        stack[i] = 0;
    }
    pi = -1;
}

void push( int v )
{
    stack[++pi] = v;
}

int pop()
{
    return ( pi >= 0 ) ? stack[pi--] : 0;
}

void show_stack()
{
    int i = pi;

    while ( i >= 0 )
    {
        if ( i == 0 )
            printf("%i\n", pop() );
        else
            printf("%i ", pop() );
        i--;
    }
}

vertex *valloc( int x )
{
    vertex *temp = ( vertex * ) malloc ( sizeof ( vertex ) );
    temp->y = x;
    temp->next = NULL;
    return temp;
}

void insert_edge( int src, int dest )
{
    vertex *temp = valloc( dest );
    temp->next = g.vertices[src];
    g.vertices[src] = temp;
}

void dfs( int v )
{
    int n; /* neighbor */
    vertex *temp;

    discovered[v] = TRUE;
    temp = g.vertices[v];

    while ( temp != NULL )
    {
        n = temp->y;

        if ( !discovered[n] )
            dfs( n );

        temp = temp->next;
    }

    push( v );
}

void top_sort()
{
    int i;

    for ( i = 1; i <= g.nvertices; i++ )
        if ( !discovered[i] )
            dfs( i );

    show_stack();
}

int main()
{
    int i, src, dst;

    while ( ( scanf("%i %i", &g.nvertices, &g.nedges ) == 2 ) && ( g.nvertices != 0 || g.nedges != 0 ) )
    {
        init();

        for ( i = 0; i < g.nedges; i++ )
        {
            scanf("%i %i", &src, &dst );
            insert_edge( src, dst );
        }

        top_sort();
    }

    return 0;
}
