#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/* ACCEPTED 0.012s */

#define MAXV 26
#define MAXLEN 100
#define DIFF 'a'

using namespace std;

struct vertex {
    int y, weight;
    struct vertex *next;
};

struct graph {
    vertex *vertices[MAXV];
    int degree[MAXV];
    int sumedges;
};

int dijkstras( graph *g, int src, int dst );

void init( graph *g ) {
    for ( int i = 0; i < MAXV; i++ ) {
        g->vertices[i] = NULL;
        g->degree[i] = 0;
    }
    g->sumedges = 0;
}

void show( graph *g ) {
    for ( int i = 0; i < MAXV; i++ ) {
        vertex *v = g->vertices[i];
        printf("%c: ", i + DIFF );
        while ( v != NULL ) {
            printf("%c ", v->y + DIFF );
            v = v->next;
        }
        printf("\n");
    }
}

void insert_edge( graph *g, int x, int y, int weight, bool dir ) {
    vertex *v = (vertex *) malloc( sizeof( vertex ) );
    v->y = y;
    v->weight = weight;
    v->next = g->vertices[x];
    g->vertices[x] = v;
    g->degree[x]++;
    if ( dir ) {
        insert_edge( g, y, x, weight, false );
    }
}

void insert_edge( graph *g, char word[] ) {
    int len = strlen( word );
    char cx = word[0];
    char cy = word[len-1];
    insert_edge( g, cx - DIFF, cy - DIFF, len, true );
    g->sumedges = g->sumedges + len;
}

int solve( graph *g ) {
    int neven = 0, nodd = 0, j = 0;
    int oddv[2];
    for ( int i = 0; i < MAXV; i++ ) {
        if ( g->degree[i] % 2 == 0 ) {
            neven++;
        } else {
            nodd++;
            oddv[j++] = i;
        }
    }
    if ( nodd == 0 ) {
        return g->sumedges;
    } else {
        return dijkstras( g, oddv[0], oddv[1] ) + g->sumedges;
    }
}

int dijkstras( graph *g, int src, int dst ) {
    int distance[MAXV];
    bool visited[MAXV];
    int v, w, dist, weight;
    vertex *p;

    for ( int i = 0; i < MAXV; i++ ) {
        distance[i] = INT_MAX;
        visited[i] = false;
    }
    distance[src] = 0;
    v = src;

    while ( !visited[v] ) {
        visited[v] = true;
        p = g->vertices[v];
        while ( p != NULL ) {
            w = p->y;
            weight = p->weight;
            if ( distance[w] > distance[v] + weight ) {
                distance[w] = distance[v] + weight;
            }
            p = p->next;
        }
        v = 0;
        dist = INT_MAX;
        for ( int i = 0; i < MAXV; i++ ) {
            if ( !visited[i] && dist > distance[i] ) {
                dist = distance[i];
                v = i;
            }
        }
    }
    return distance[dst];
}


int main() {
    char s[MAXLEN];
    graph g;
    init( &g );
    while ( scanf( "%s", s ) == 1 ) {
        if ( strcmp("deadend", s ) == 0 ) {
            printf("%i\n", solve( &g ) );
            init( &g );
        } else {
            insert_edge( &g, s );
        }
    }

    return 0;
}

