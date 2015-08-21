#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED 1.402 */

#define MAXV 1000
#define TRUE 1
#define FALSE 0

int connected[MAXV + 1][MAXV + 1];
int parent[MAXV + 1];
int degree[MAXV + 1];

int find( int x)
{
    return ( parent[x] == x ) ? x : ( parent[x] = find( parent[x] ) );
}

/* key to the problem is in the Euler Cycle */
void euler_cycle( int begin )
{
    int to;

    for ( to = 1; to <= MAXV; to++ )
    {
        if ( connected[begin][to] )
        {
            connected[begin][to]--;
            connected[to][begin]--;

            euler_cycle( to );

            printf("%i %i\n", to, begin );
        }
    }
}

int main()
{
    int i, j, nc, ne, left, right, possible, pleft, pright, begin, tparent, c;

    scanf("%i", &nc );

    for ( i = 0; i < nc; i++ )
    {
        memset( connected, 0, sizeof( connected ) );
        memset( degree, 0, sizeof( degree ) );

        for ( j = 0; j < MAXV + 1; j++ )
            parent[j] = j;

        scanf("%i", &ne );

        for ( j = 0; j < ne; j++ )
        {
            scanf("%i %i", &left, &right );

            connected[left][right]++;
            connected[right][left]++;

            degree[left]++;
            degree[right]++;

            pleft = find( left );
            pright = find( right );

            if ( pleft != pright )
                parent[pleft] = pright;
        }

        begin = 1;

        while ( !degree[begin] )
            begin++;

        /* make sure we can get back to here from every other vertex */
        tparent = find( begin );
        possible = TRUE;
        /* make sure we can get to the first parent */
        for ( c = begin + 1; possible && c <= MAXV; c++ )
            if ( degree[c] && find( c ) != tparent )
                possible = FALSE;
        /* if there is an odd degree vertex, no euler cycle */
        for ( j = 1; possible && j <= MAXV; j++ )
            if ( degree[j] & 1 )
                possible = FALSE;

        printf("Case #%i\n", ( i + 1 ) );

        if ( !possible )
            printf("some beads may be lost\n");
        else
            euler_cycle( begin );
        if ( i < nc - 1 )
            putchar('\n');
    }

    return 0;
}
