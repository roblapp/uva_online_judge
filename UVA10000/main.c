#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
#define MAXV 200

struct vertex {
    int y;
    struct vertex *next;
};

struct graph {
    struct vertex *vertices[MAXV + 1];
    int nvertices;
};

struct node {
    int x;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
    int size;
};

/**< type definitions */
typedef struct node node;
typedef struct queue queue;
typedef struct graph graph;
typedef struct vertex vertex;
typedef int bool;

void init_graph( graph *g ) {
    int i;
    g->nvertices = 0;
    for ( i = 0; i <= MAXV; i++ ) g->vertices[i] = NULL;
}

void init_q( queue *q ) {
    q->head = q->tail = NULL;
    q->size = 0;
}

/* puts y in x's adjacency list */
void insert_edge( graph *g, int x, int y, int dir ) {
    vertex *v = ( vertex * ) malloc ( sizeof( vertex ) );
    v->y = y;
    v->next = g->vertices[x];
    g->vertices[x] = v;
    if ( dir ) insert_edge( g, y, x, FALSE );
}

node *nalloc( int data ) {
    node *temp = ( node * ) malloc ( sizeof ( node ) );
    temp->x = data;
    temp->next = NULL;
    return temp;
}

bool is_empty(queue *q) {
    return (q->size == 0);
}

void enqueue( queue *q, int data ) {
    node *temp = nalloc( data );
    if ( q->head == NULL )
        q->head = temp;
    else
        q->tail->next = temp;
    q->tail = temp;
    q->size = q->size + 1;
}

int dequeue( queue *q ) {
    int res = 0;
    if ( q->head != NULL ) {
        node *temp = q->head;
        res = temp->x;
        q->head = q->head->next;
        if ( q->head == NULL )
            q->tail = NULL;
		q->size = q->size - 1;
    }
    return res;
}

void bfs(graph *g, int src, int cn) {
    int v, n;
    vertex *temp;
    queue q;
    init_q(&q);
    bool visited[MAXV + 1];
    int dist[MAXV + 1];
    memset(visited, FALSE, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    v = src;
    visited[v] = TRUE;
    enqueue(&q, v);
    while (!is_empty(&q)) {
        v = dequeue(&q);
        visited[v] = TRUE;
        temp = g->vertices[v];
        while ( temp != NULL ) {
            n = temp->y;
            if ( !visited[n] || (visited[n] && dist[n] < dist[v] + 1) ) {
                dist[n] = 1 + dist[v];
                enqueue(&q, n);
            }
            temp = temp->next;
        }
    }
    int max = 0, maxv = src;
    for ( v = 1; v <= MAXV; v++ ) {
        if ( dist[v] > max ) {
            max = dist[v];
            maxv = v;
        }
    }
    printf("Case %i: The longest path from %i has length %i, finishing at %i.\n\n", cn, src, max, maxv);
}


int main() {
    int a, b, np, start, cn = 1;
    graph g;
    FILE *fp = stdin;
    while ( fscanf(fp,"%i", &np ) == 1 && np != 0 ) {
        fscanf(fp,"%i", &start);
        init_graph(&g);
        while ( fscanf(fp,"%i %i", &a, &b ) == 2 && (a != 0 || b != 0 ) ) {
            insert_edge(&g, a, b, FALSE);
        }
        bfs(&g, start, cn++);
    }
    fclose(fp);
    return 0;
}
