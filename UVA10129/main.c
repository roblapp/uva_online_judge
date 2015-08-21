#include <stdio.h>
#include <stdlib.h>

#define MAXL 1001
#define MAXV 100001

struct vertex {

    char s[MAXL];
    struct vertex *next;
};

struct graph {

    struct vertex *vertices[MAXV];
    int in_degree[MAXV];
    int out_degree[MAXV];
    int nv;
    int ne;
};

typedef struct vertex vertex;
typedef struct graph graph;

graph g;

FILE *fp;

void call()
{
}

int main()
{
    int i, j, nc;
    //char temp[MAXL];

    fp = fopen("test.txt", "r" );

    fscanf(fp, "%i", &nc );

    for ( i = 0; i < nc; i++ )
    {
        fscanf(fp, "%i", &g.nv );

        for ( j = 0; j < g.nv; j++ )
        {
        }
    }

    fclose( fp );

    return 0;
}
