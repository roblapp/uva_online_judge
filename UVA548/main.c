#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>

/* ACCEPTED */
/* However, the time was TERRIBLE @ 2.392 seconds which is my worst time to date */

#define MAX 10000

#define TRUE 1
#define FALSE 0

int rec( int *parent, int child, int sum )
{
    return ( child == - 1 ) ? sum : rec( parent, parent[child], sum + child );
}

int prev( int *selectable, int *a, int i )
{
    i--;

    while ( i >= 0 && selectable[i] == FALSE ) i--;

    return i;
}

int next( int *selectable, int *a, int i, int n )
{
    i++;

    while ( i < n && selectable[i] == FALSE ) i++;

    return i;
}

void construct_tree( int *a, int *b, int n, int max_val )
{
    int *parent = ( int * ) malloc( ( max_val + 1 ) * sizeof( int ) );
    int *selectable = ( int * ) malloc ( ( max_val + 1 ) * sizeof( int ) );
    int *is_leaf = ( int * ) malloc ( ( max_val + 1 ) * sizeof( int ) );

    int i, j, k, i_pr, i_nx;

    for ( i = 0; i < max_val + 1; i++ )
    {
        parent[i] = -1;
        selectable[i] = is_leaf[i] = TRUE;
    }

    for ( i = 1; i < n; i++ )
    {
        j = 0;

        while ( a[j] != b[i] )
            j++;

        /* j is the index in a */
        i_pr = prev( selectable, a, j );
        i_nx = next( selectable, a, j, max_val );

        for ( k = 0; k < i; k++ )
        {
            /* b[k] is a child of b[i] */
            if ( i_pr >= 0 && a[i_pr] == b[k] )
            {
                selectable[ i_pr ] = is_leaf[ b[i] ] = FALSE;
                parent[ a[ i_pr ] ] = b[i];
            }
            else if ( i_nx < n && a[i_nx] == b[k] )
            {
                selectable[ i_nx ] = is_leaf[ b[i] ] = FALSE;
                parent[ a[ i_nx ] ] = b[i];
            }
        }
    }

    int x;
    int min = INT_MAX;
    int min_leaf;

    for ( i = 0; i < n; i++ )
    {
        if ( is_leaf[ a[i] ] == TRUE )
        {
            x = rec( parent, a[i], 0);
            if ( x < min )
            {
                min = x;
                min_leaf = a[i];
            }
        }
    }

    printf("%i\n", min_leaf );
}

int main()
{
    char c;
    int a[MAX + 1];
    int b[MAX + 1];
    int ptr;
    int max;

    while ( TRUE )
    {
        c = getchar();
        ptr = 0;
        if ( c == EOF )
            break;
        else
            ungetc( c, stdin );
        max = 0;
        do
        {
            scanf("%i", &a[ptr] );
            if ( a[ptr] > max )
            {
                max = a[ptr];
            }
            ptr++;
            c = getchar();
        }
        while ( c != '\n' );
        ptr = 0;
        do
        {
            scanf("%i", &b[ptr++] );
            c = getchar();
        }
        while ( c != '\n' );

        construct_tree( a, b, ptr, max );
    }

    return 0;
}
