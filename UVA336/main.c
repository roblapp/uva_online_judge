#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

/* ACCEPTED 0.119s */
/* Need to go through and free up dynamic memory. However,
in a contest you don't want to waste time with calls to free() */

#define MAXV 100
#define TRUE 1
#define FALSE 0
#define TABLESIZE 100
#define MAXLEN 20

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
    int parent;
    struct node *next;
};

struct queue {
    struct node *head;
    struct node *tail;
    int size;
};

struct entry {
    char key[MAXLEN + 1];
    int value;
    struct entry *next;
};

/**< type definitions */
typedef struct node node;
typedef struct queue queue;
typedef struct graph graph;
typedef struct vertex vertex;
typedef struct entry entry;

entry *table[TABLESIZE];
int casen = 1;

void init_table() {
    int i;
    for ( i = 0; i < TABLESIZE; i++ ) table[i] = NULL;
}

entry *entry_allocate( char *key, int value ) {
    entry *temp = ( entry * ) malloc ( sizeof ( entry ) );
    strcpy( temp->key, key );
    temp->value = value;
    temp->next = NULL;
    return temp;
}

unsigned hash( char *key ) {
    char *p = key;
    unsigned h = 0;
    while ( *p ) {
        h ^= ( h << 5 ) + ( h >> 2 ) + *p;
        p++;
    }
    return h % TABLESIZE;
}

int search( char * key ) {
    unsigned index = hash( key );

    entry *temp = table[index];

    while ( temp != NULL ) {
        if ( strcmp( temp->key, key ) == 0 ) {
            return TRUE;
        }
        temp = temp->next;
    }

    return FALSE;
}

int get_value( char *key ) {
    unsigned index = hash( key );

    entry *temp = table[index];

    while ( temp != NULL ) {
        if ( strcmp( temp->key, key ) == 0 ) {
            return temp->value;
        }
        temp = temp->next;
    }

    return 0;
}

void insert( char *key, int value ) {
    unsigned index = hash( key );

    entry *temp = table[index];

    while ( temp != NULL ) {
        if ( strcmp( temp->key, key ) == 0 ) {
            return;
        }
        temp = temp->next;
    }

    entry *n = entry_allocate( key, value );
    n->next = table[index];
    table[index] = n;
}

char *int_to_string(int vertex) {
    int tv = vertex, len = 0;
    if (vertex == 0) {
        char *r = (char *) malloc(2);
        r[0] = '0';
        r[1] = 0;
        return r;
    }
    while (tv > 0) {
        tv /= 10;
        len++;
    }
    int i = len;
    char *str = (char *) malloc(len + 1);
    char *tstr = str;
    *(tstr + i) = 0;
    i--;
    while (vertex > 0) {
        *(tstr + i--) = (vertex % 10) + 48;
        vertex /= 10;
    }
    return str;
}


node *nalloc( int data0, int data1 ) {
    node *temp = ( node * ) malloc ( sizeof ( node ) );
    temp->x = data0;
    temp->parent = data1;
    temp->next = NULL;
    return temp;
}

void init_q( queue *q ) {
    q->head = q->tail = NULL;
    q->size = 0;
}

void init_graph( graph *g ) {
    int i;
    g->nvertices = 0;
    for ( i = 0; i <= MAXV; i++ ) g->vertices[i] = NULL;
}

void clear_graph(graph *g) {
    int i;
    vertex *v, *temp;

    for ( i = 1; i <= MAXV; i++ ) {
        v = g->vertices[i];
         while (v != NULL) {
            temp = v;
            v = v->next;
            free(temp);
        }
    }
}

/* puts y in x's adjacency list */
void insert_edge( graph *g, int x, int y, int dir ) {
    vertex *v = ( vertex * ) malloc ( sizeof( vertex ) );
    v->y = y;
    v->next = g->vertices[x];
    g->vertices[x] = v;
    if ( dir )
        insert_edge( g, y, x, FALSE );
}

void show_graph( graph *g ) {
    int i;
    vertex *v;

    for ( i = 1; i <= MAXV; i++ ) {
        v = g->vertices[i];

        if ( v != NULL ) {
            printf("%i:", i );

            while ( v != NULL ) {
                printf(" %i", v->y );
                v = v->next;
            }
            printf("\n");
        }
    }
}

void enqueue( queue *q, int data0, int data1 ) {
    node *temp = nalloc(data0, data1);

    if ( q->head == NULL )
        q->head = temp;
    else
        q->tail->next = temp;

    q->tail = temp;
    q->size = q->size + 1;
}

void dequeue(queue *q, int *data0, int *data1) {
    *data0 = 0;
    *data1 = 0;

    if ( q->head != NULL ) {
        node *temp = q->head;
        *data0 = temp->x;
        *data1 = temp->parent;
        q->head = q->head->next;

        if ( q->head == NULL )
            q->tail = NULL;

		q->size = q->size - 1;
    }
}

int is_empty(queue *q) {
    return (q->size == 0);
}

void show_q( queue *q ) {
    node *temp = q->head;

    printf("[%i] : { ", q->size );

    while ( temp != NULL ) {
        printf("[%i %i] ", temp->x, temp->parent);
        temp = temp->next;
    }

    printf("}\n");
}

void bfs(graph *g, int src, int original, int time, int count) {
    int i, v, y, depth = 0;
    int visited[MAXV + 1];
    vertex *temp;
    for (i = 1; i <= MAXV; i++) {
        visited[i] = FALSE;
    }

    queue q;
    init_q(&q);

    visited[src] = TRUE;
    enqueue(&q, src, depth);
    count--;
    while (!is_empty(&q)) {
        dequeue(&q, &v, &depth);
        temp = g->vertices[v];
        while (temp != NULL) {
            y = temp->y;
            if (!visited[y] && depth + 1 <= time) {
                visited[y] = TRUE;
                enqueue(&q, y, depth + 1);
                count--;
            }
            temp = temp->next;
        }
        if (depth + 1 > time) break;
    }

    printf("Case %i: %i nodes not reachable from node %i with TTL = %i.\n", casen++, count, original, time);
}

int main() {

    graph g;
    int i, nedges, x, y;

    while (scanf("%i", &nedges) == 1 && nedges > 0) {

         init_graph(&g);

         init_table();

         int nodes[MAXV + 1];

         for (i = 1; i <= MAXV; i++) {
            nodes[i] = 0;
         }
        int k = 1;

        int nx, ny;

        for (i = 0; i < nedges; i++) {
            scanf("%i %i", &x, &y);

            char *str = int_to_string(x);
            if (!search(str) ) {
                insert(str, k);
                nx = k++;
            } else {
                nx = get_value(str);
            }
            str = int_to_string(y);
            if (!search(str) ) {
                insert(str, k);
                ny = k++;
            } else {
                ny = get_value(str);
            }
            nodes[nx] = nodes[ny] = TRUE;
            insert_edge(&g, nx, ny, TRUE);
        }
        int count = 0;
        for (i = 1; i <= MAXV; i++) {
            if (nodes[i]) count++;
        }

        while (scanf("%i %i", &x, &y) == 2 && (x > 0 || y > 0)) {

            char *str = int_to_string(x);
            if (!search(str)) {
                printf("Case %i: %i nodes not reachable from node %i with TTL = %i.\n", casen++, count, x, y);
            } else if (y == 0) {
                printf("Case %i: %i nodes not reachable from node %i with TTL = %i.\n", casen++, count - 1, x, y);
            } else {
                bfs(&g, get_value(str), x, y, count);
            }
        }

        clear_graph(&g);
    }

    return 0;
}

