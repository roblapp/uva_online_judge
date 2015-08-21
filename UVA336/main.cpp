#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#define MAXV 100
#define TRUE 1
#define FALSE 0
#define BLACK 1
#define WHITE 0

using namespace std;

struct vertex {
    int y;
    struct vertex *next;
};

struct graph {
    struct vertex *vertices[MAXV + 1];
    int nvertices;
};

typedef struct graph graph;
typedef struct vertex vertex;

void init_graph( graph *g ) {
    int i;

    g->nvertices = 0;

    for ( i = 0; i <= MAXV; i++ ) g->vertices[i] = NULL;
}

/* puts y in x's adjacency list */
void insert_edge( graph *g, int x, int y, int dir ) {
    vertex *v = ( vertex * ) malloc ( sizeof( vertex ) );

    v->y = y;
    v->next = g->vertices[x];
    g->vertices[x] = v;

    if ( dir ) insert_edge( g, y, x, FALSE );
}

void delete_graph(graph *g) {
    int i;
    vertex *temp0, *temp1;
    for (i = 0; i <= MAXV; i++) {
        temp0 = g->vertices[i];
        while (temp0 != NULL) {
            temp1 = temp0;
            temp0 = temp0->next;
            free(temp1);
        }
    }
}



int main() {



    return 0;
}
