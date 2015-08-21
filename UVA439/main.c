#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

/* ACCEPTED */

#define MAXV 64
#define SIZE 8
#define TRUE 1
#define FALSE 0

struct node {

    int data;
    struct node *next;
};

struct vertex {

    int y;
    struct vertex *next;
};

struct graph {

    struct vertex *vertices[MAXV + 1];
};

struct queue {

    struct node *head;
    struct node *tail;
    int size;
};

typedef struct queue queue;
typedef struct node node;
typedef struct vertex vertex;
typedef struct graph graph;


int moves[MAXV +1];
int discovered[MAXV + 1];

node *nalloc( int data )
{
    node *temp = ( node * ) malloc ( sizeof( node ) );
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int is_empty( queue *q )
{
    return ( q->size == 0 );
}

void enqueue( queue *q, int data )
{
    if ( q->head == NULL )
    {
        q->head = q->tail = nalloc( data );
    }
    else
    {
        node *temp = nalloc( data );
        q->tail->next = temp;
        q->tail = temp;
    }
    q->size = q->size + 1;
}

int dequeue( queue *q )
{
    int result = -1;

    if ( q->head != NULL )
    {
        result = q->head->data;

        if ( q->head == q->tail )
            q->head = q->tail = NULL;
        else
            q->head = q->head->next;

        q->size = q->size - 1;
    }

    return result;
}


/**< graph functions */
void insert_edge( graph *g, int v, int neighbor )
{
    vertex *temp = ( vertex * ) malloc( sizeof( vertex ) );
    temp->y = neighbor;

    temp->next = g->vertices[v];

    g->vertices[v] = temp;
}


int min( int a, int b )
{
    return ( a < b ) ? a : b;
}

/* returns 1d index from a 2d input ( input is 0 based and output is 1 based ) */
int index( int i, int j )
{
    return ( SIZE * i + j + 1 );
}

int letter_index( char a, char b )
{
    return index( a - 97, b - 49 );
}

void add_neighbors( graph *g, int x, int y )
{
    int i[] = { -1, -1, 1, 1, 2, 2, -2, -2 };
    int j[] = { -2, 2, -2, 2, -1, 1, -1, 1 };
    int a, b, k, temp, v;

    v = index( x, y ); /* vertex we are adding neighbors of */

    for ( k = 0; k < SIZE; k++ )
    {
        a = x + i[k];
        b = y + j[k];

        if ( a >= 0 && a < SIZE && b >= 0 && b < SIZE )
        {
            temp = index( a, b );

            if ( temp >= 1 && temp <= MAXV )
                insert_edge( g, v, temp );
        }
    }
}

void init_q( queue *q )
{
    q->head = q->tail = NULL;
    q->size = 0;
}

void init_graph( graph *g )
{
    int i, j;

    for ( i = 0; i <= MAXV; i++ )
    {
        g->vertices[i] = NULL;
        discovered[i] = FALSE;
        moves[i] = INT_MAX;
    }

    for ( i = 0; i < SIZE; i++ )
    {
        for ( j = 0; j < SIZE; j++ )
        {
            add_neighbors( g, i, j );
        }
    }
}

void bfs( graph *g, queue *q, int src )
{
    int v = src;
    int neighbor;
    vertex *temp;

    enqueue( q, v );
    discovered[v] = TRUE;
    moves[v] = 0;

    while ( !is_empty( q ) )
    {
        v = dequeue( q );
        temp = g->vertices[v];

        while ( temp != NULL )
        {
            neighbor = temp->y;
            moves[neighbor] = min( moves[neighbor], moves[v] + 1 );

            if ( !discovered[neighbor] ) /* if neighbor is not discovered */
            {
                enqueue( q, neighbor );
                discovered[neighbor] = TRUE;
            }

            temp = temp->next;
        }
    }
}

int main()
{
    graph g;
    queue q;
    char x[10];
    char c;
    int ptr = 0;
    int src;
    int dest;

    while ( TRUE )
    {
        c = getchar();
        if ( c == EOF ) break;
        if ( c == '\n' )
        {
            src = letter_index( x[0], x[1] );
            dest = letter_index( x[2], x[3] );
            init_graph( &g );
            init_q( &q );
            bfs( &g, &q, dest );
            printf("To get from %c%c to %c%c takes %i knight moves.\n", x[0], x[1], x[2], x[3], moves[src] );
            ptr = 0;
        }
        if ( !isspace( c ) )
            x[ptr++] = c;
    }


    return 0;
}
