#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ACCEPTED 0.039 */

#define MAXL 1000

int len;
char a[MAXL];

int compare( const void *a, const void *b )
{
    char ca = *( char * ) a;
    char cb = *( char * ) b;

    if ( toupper( ca ) == toupper( cb ) )
        return ca - cb;
    return toupper( ca ) - toupper( cb );
}

int comp( char ca, char cb )
{
    if ( toupper( ca ) == toupper( cb ) )
        return ca - cb;
    return toupper( ca ) - toupper( cb );
}

void show()
{
    int i;
    for ( i = 0; i < len; i++ )
        putchar( a[i] );
    putchar('\n');
}

void swap( int i, int j )
{
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int permute( int n )
{
    int j;
    int k;
    int r;
    int s;

    j = n - 1;
    k = n;

    /* j is the largest a_j such that a_j <= a_j+1 */
    while ( j >= 0 && comp( a[j], a[j+1] ) >= 0 )
        j--;

    if ( j == -1 )
        return -1;
    /* a_k is the smallest integer greater than a_j to the right of a_j */
    while ( k >= 0 && comp( a[j], a[k] ) >= 0 )
        k--;

    swap( j, k );

    r = n;
    s = j + 1;

    while ( r > s )
    {
        swap( r, s );
        r--;
        s++;
    }
    return 1;
}

int main()
{
    int i, nc;

    scanf("%i", &nc );

    for ( i = 0; i < nc; i++ )
    {
        scanf("%s", a );

        len = strlen( a );

        qsort( &a, len, sizeof( char ), compare );

        show();

        while ( permute( len - 1 ) != -1 )
            show();
    }

    return 0;
}
