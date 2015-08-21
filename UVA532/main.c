#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include <string.h>

/* ACCEPTED 0.022 */
/*
Lesson learned here:
DFS worked for several problems but not for all of them. The reason is that
the order that the we traversed the graph was sometimes the shortest path, but
not ALWAYS the shortest path. When we use a breadth first traversal we will always
discover the vertices through the shortest path. For shortest path problems use
Dijkstra's algorithm or BFS when it will work.
*/

#define MAXR 30
#define MAXC 30
#define MAXL 30
#define TRUE 1
#define FALSE 0

struct node {

    int i, j, k, cost;
    struct node *next;
};

struct queue {

    struct node *head;
    struct node *tail;
    int size;
};

typedef struct node node;
typedef struct queue queue;

char a[MAXR][MAXC][MAXL];
int sr, sc, sl, er, ec, el, min_cost, nl, nr, nc;
int discovered[MAXR][MAXC][MAXL];

node *nalloc( int i, int j, int k, int cost )
{
    node *temp = ( node * ) malloc ( sizeof ( node ) );
    temp->i = i;
    temp->j = j;
    temp->k = k;
    temp->cost = cost;
    temp->next = NULL;
    return temp;
}

void enqueue( queue *q, int i, int j, int k, int cost )
{
    node *temp = nalloc( i, j, k, cost );

    if ( q->head == NULL )
        q->head = temp;
    else
        q->tail->next = temp;

    q->tail = temp;
    q->size = q->size + 1;
}

void dequeue( queue *q, int *pi, int *pj, int *pk, int *pcost )
{
    if ( q->head != NULL )
    {
        node *temp = q->head;
        *pi = temp->i;
        *pj = temp->j;
        *pk = temp->k;
        *pcost = temp->cost;
        q->head = q->head->next;

        if ( q->head == NULL )
            q->tail = NULL;

		q->size = q->size - 1;
    }
}

void init_q( queue *q )
{
    q->head = q->tail = NULL;
    q->size = 0;
}

int is_empty( queue *q )
{
    return ( q->size == 0 );
}

int map( int i, int j, int k )
{
    return ( i * MAXC + j ) + ( k * MAXR*MAXC );
}

void neighbors( queue *q, int i, int j, int k, int cost )
{
    if ( i > 0 && !discovered[i-1][j][k] && a[i-1][j][k] != '#' )
    {
        enqueue( q, i-1, j, k, cost );
        discovered[i-1][j][k] = TRUE;
    }

    if ( j > 0 && !discovered[i][j-1][k] && a[i][j-1][k] != '#' )
    {
        enqueue( q, i, j-1, k, cost );
        discovered[i][j-1][k] = TRUE;
    }
    if ( i < nr - 1 && !discovered[i+1][j][k] && a[i+1][j][k] != '#' )
    {
        enqueue( q, i+1, j, k, cost );
        discovered[i+1][j][k] = TRUE;
    }
    if ( j < nc - 1 && !discovered[i][j+1][k] && a[i][j+1][k] != '#' )
    {
        enqueue( q, i, j+1, k, cost );
        discovered[i][j+1][k] = TRUE;
    }
    if ( k < nl - 1 && !discovered[i][j][k+1] && a[i][j][k+1] != '#' )
    {
        enqueue( q, i, j, k+1, cost );
        discovered[i][j][k+1] = TRUE;
    }
    if ( k > 0 && !discovered[i][j][k-1] && a[i][j][k-1] != '#' )
    {
        enqueue( q, i, j, k-1, cost );
        discovered[i][j][k-1] = TRUE;
    }
}

void bfs()
{
    int i, j, k, cost;
    queue q;

    init_q( &q );

    i = sr;
    j = sc;
    k = sl;
    cost = 0;

    enqueue( &q, i, j, k, cost );
    discovered[i][j][k] = TRUE;

    while ( !is_empty( &q ) )
    {
        dequeue( &q, &i, &j, &k, &cost );

        if ( i == er && j == ec && k == el )
        {
            min_cost = cost;
            return;
        }

        neighbors( &q, i, j, k, cost + 1 );
    }
}

void getline()
{
    int i, j, k;
    char c;

    for ( k = 0; k < nl; k++ )
    {
        for ( i = 0; i < nr; i++ )
        {
            j = 0;
            while ( j < nc )
            {
                c = getchar();

                if ( c == '#' || c == '.' || c == 'S' || c == 'E' )
                {
                    a[i][j][k] = c;

                    if ( c == 'S' )
                    {
                        sr = i;
                        sc = j;
                        sl = k;
                    }
                    else if ( c == 'E' )
                    {
                        er = i;
                        ec = j;
                        el = k;
                    }

                    j++;
                }
            }
        }
    }
}

int main()
{
    while ( scanf("%i %i %i", &nl, &nr, &nc ) == 3 && ( nl != 0 || nr != 0 || nc != 0 ) )
    {
        memset( discovered, 0, sizeof( discovered ) );
        getline();
        min_cost = INT_MAX;
        bfs();
        if ( min_cost == INT_MAX )
            printf("Trapped!\n");
        else
            printf("Escaped in %i minute(s).\n", min_cost );
    }

    return 0;
}
