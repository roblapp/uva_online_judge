#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.012 */

#define DSIZE 52
#define MAXS 100
#define readc getchar()
#define TRUE 1
#define FALSE 0
#define FAIL -1

int shuffles[MAXS + 1][DSIZE + 1];
int deck[DSIZE + 1];
int eofread = FALSE;

void readint( int *x )
{
    scanf("%i", x );
}

int readcase( int *x )
{
    if ( eofread ) return FAIL;

    char c;
    *x = 0;
    while ( ( c = readc ) != EOF && c != '\n' )
        if ( isdigit( c ) )
            *x = 10 * ( * x ) + c - '0';
    if ( c == EOF )
        eofread = TRUE;
    if ( c == '\n' && *x == 0 )
        return FALSE;
    return TRUE;
}

void init()
{
    int i;
    for ( i = 1; i <= DSIZE; i++ )
        deck[i] = i;
}

void show()
{
    char *suits[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    char *ranks[] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };
    int i;
    for ( i = 1; i <= DSIZE; i++ )
        printf("%s of %s\n", ranks[ ( ( deck[i] - 1 ) % 13 ) ] , suits[ ( ( deck[i] - 1 ) / 13 ) ] );
}

int main()
{
    int i, j, k, nc, ns, x;
    int temp[DSIZE + 1];

    readint( &nc );

    for ( i = 0; i < nc; i++ )
    {
        readint( &ns );

        for ( j = 1; j <= ns; j++ )
            for ( k = 1; k <= DSIZE; k++ )
                readint( &shuffles[j][k] );

        readc;
        init();

        while ( ( x = readcase( &j ) ) != FAIL && j != 0 )
        {
            for ( k = 1; k <= DSIZE; k++ )
                temp[k] = deck[ shuffles[j][k] ];
            for ( k = 1; k <= DSIZE; k++ )
                deck[k] = temp[k];
        }
        show();

        if ( i < nc - 1 ) putchar('\n');
    }
    return 0;
}
