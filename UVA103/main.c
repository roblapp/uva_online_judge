#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.009 */

#define MAXBOXES 30
#define MAXDIM 10

#define TRUE 1
#define FALSE 0

int m[MAXBOXES + 1][MAXDIM];
int ordering[MAXBOXES + 1];
int nboxes, ndim;

void init()
{
    int i, j;

    for ( i = 0; i <= MAXBOXES; i++ )
    {
        for ( j = 0; j < MAXDIM; j++ )
            m[i][j] = 0;
        ordering[i] = i;
    }
}

int compare( const void *a, const void *b )
{
    return * ( int * ) a - * ( int * ) b;
}

int compare_boxes( int a[], int b[] )
{
    int i = 0;

    while ( i < ndim && a[i] == b[i] )
    {
        if ( i + 1 == ndim )
            return 0;
        i++;
    }

    return a[i] - b[i];
}

int box_fits( int a[], int b[] )
{
    int i = 0;

    while ( i < ndim && a[i] < b[i] )
    {
        if ( i + 1 == ndim ) /* all of box a fits into box b */
            return TRUE;
        i++;
    }
    return FALSE;
}

void swap( int a[], int b[] )
{
    int i, temp[ndim];
    /* temp = a; */
    for ( i = 0; i < ndim; i++ )
        temp[i] = a[i];
    /* now copy b's contents into a */
    for ( i = 0; i < ndim; i++ )
        a[i] = b[i];
    /* now copy a's contents into b */
    for ( i = 0; i < ndim; i++ )
        b[i] = temp[i];
}

void sort()
{
    int i, j, key;

    /* O( N*M*LOG(M) ) */
    for ( i = 1; i <= nboxes; i++ )
        qsort( m[i], ndim, sizeof( int ), compare );

    /* N^2 */
    for ( i = 1; i < nboxes; i++ )
    {
        key = i;

        for ( j = i + 1; j <= nboxes; j++ )
            if ( compare_boxes( m[key], m[j] ) > 0 )
                key = j;

        if ( key != i )
        {
            swap( m[key], m[i] );
            int temp = ordering[i];
            ordering[i] = ordering[key];
            ordering[key] = temp;
        }
    }
}

void construct_path( int pos, int parent[] )
{
    if ( parent[pos] != -1 )
    {
        construct_path( parent[pos], parent );
        printf(" %i", ordering[pos] );
    }
    else
        printf("%i", ordering[pos] );
}

void solve()
{
    int i, j, mn, mp, parent[nboxes + 1], lss[nboxes + 1];

    int tm, tp;

    for ( i = 0; i <= nboxes; i++ ) parent[i] = -1;
    for ( i = 0; i <= nboxes; i++ ) lss[i] = 0;

    mn = mp = 0;
    lss[1] = 1;

    for ( i = 2; i <= nboxes; i++ )
    {
        tm = 0;
        tp = -1;

        for ( j = 1; j < i; j++ )
        {
            if ( box_fits( m[j], m[i] ) && lss[j] > tm ) /* m[j] < m[i] */
            {
                tm = lss[j];
                tp = j;
            }
        }
        lss[i] = 1 + tm;
        parent[i] = tp;

        if ( lss[i] > mn )
        {
            mn = lss[i]; /* take note where largest lss is and what it is */
            mp = i;
        }
    }

    printf("%i\n", mn );
    construct_path( mp, parent );
    printf("\n");
}

int main()
{
    int i, j;

    while ( ( scanf("%i %i", &nboxes, &ndim ) ) == 2 )
    {
        init();

        for ( i = 1; i <= nboxes; i++ )
            for ( j = 0; j < ndim; j++ )
                scanf("%i", &m[i][j] );

        sort();
        solve();
    }

    return 0;
}
