#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED .135 */

#define MAXN 100
#define MAXS 1000

void swap( char *v[], int i, int j )
{
    char *temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int string_compare( char *s, char *t )
{
    int i, r = 0, ls = strlen( s ), lt = strlen( t ), k = 0;
    char ab[ls + lt + 1], ba[ls + lt + 1];

    for ( i = 0; i < ls; i++ )
    {
        ab[r] = s[i];
        ba[lt + r] = s[i];
        r++;
    }
    ba[lt + r] = '\0';

    for ( i = 0; i < lt; i++ )
    {
        ab[r] = t[i];
        ba[k++] = t[i];
        r++;
    }

    ab[r] = '\0';

    return strcmp( ab, ba );
}

void sort( char *s[], int n )
{
    int i, j, key;

    for ( i = 0; i < n - 1; i++ )
    {
        key = i;

        for ( j = i + 1; j < n; j++ )
            if ( string_compare( s[key], s[j] ) < 0 )
                key = j;

        if ( i != j ) swap( s, i, key );
    }
}

int main()
{
    int ndata;
    int i;
    char *data[MAXN]; /* storage for MAXN pointers */

    for ( i = 0; i < MAXN; i++ )
        data[i] = ( char * ) malloc ( MAXS ); /* allocate room for numbers with MAXS digits */

    while ( scanf("%i", &ndata ) != EOF && ndata != 0 )
    {
        for ( i = 0; i < ndata; i++ )
            scanf("%s", data[i] );

        sort( data, ndata );

        for ( i = 0; i < ndata; i++ )
            printf("%s", data[i] );
        printf("\n");
    }

    for ( i = 0; i < MAXN; i++ )
        free( data[i] );

    return 0;
}
