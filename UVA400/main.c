#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 60
#define MAXLINES 100

/* ACCEPTED */

void sort( char **p, int len )
{
    int i, j, k;

    for ( i = 0; i < len; i++ )
    {
        k = i;

        for ( j = i + 1; j < len; j++ )
            if ( strcmp( *( p + k ), *( p + j ) ) > 0 )
                k = j;

        if ( k != i )
        {
            char temp[MAX + 1];
            strcpy( temp, *( p + i ) );
            strcpy( *( p + i ), *( p + k ) );
            strcpy( *( p + k ), temp );
        }
    }
}

int main()
{
    char buff[MAX + 1];
    char dashes[MAX + 1];
    memset( dashes, '-', MAX );
    dashes[MAX] = '\0';
    char **p = ( char ** ) malloc( MAXLINES * sizeof( char * ) );
    int nfiles = 0, i, j;
    int max_len = 0;
    int temp_len = 0;
    int x;
    int y;
    int z;

    while ( scanf("%i", &nfiles ) != EOF )
    {
        i = max_len = 0;

        for ( j = 0; j < nfiles; j++ )
        {
            scanf("%s", buff );
            temp_len = strlen( buff );
            max_len = ( temp_len > max_len ) ? temp_len : max_len;
            *( p + i ) = ( char * ) malloc( MAX + 1 );
            strcpy( *( p + i ), buff );
            i++;
        }

        sort( p, nfiles );

        x = ( MAX - max_len ) / ( max_len + 2 ) + 1;

        int wpc = ( int ) ceil( 1.0 * nfiles / x );
        int skip = 0;

        printf("%s\n", dashes );

        for ( i = 0; i < wpc; i++ )
        {
            for ( skip = 0; i + skip < nfiles; skip += wpc )
            {
                printf("%s", *( p + i + skip ) );

                z = max_len - strlen( *( p + i + skip ) );
                y = 0;

                while ( y++ < z )
                    printf(" ");

                ( i + skip + wpc >= nfiles ) ? printf("\n") : printf("  ");
            }
        }
    }

    free( p );

    return 0;
}
