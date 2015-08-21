#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ACCEPTED 0.052 */

#define MAXWORDS 1000
#define MAXL 200
#define ALPHA 26
#define MAXWL 20
#define TRUE 1
#define FALSE 0
#define IN 1
#define OUT 0
#define FAIL -1
#define OFFSET 97
#define readc getchar()

typedef int bool;

char dictionary[MAXWORDS][MAXL];
int dlengths[MAXWORDS];
int ndw;

char input[MAXL][MAXL];
int niw;
int nic;

char map[ALPHA]; /* the mapping from input to output */
char parent[ALPHA]; /* making sure the function is injective */

bool eofread;


void readint( int *n )
{
    char c;
    *n = 0;
    while ( ( c = readc ) != EOF && c != '\n' )
        if ( isdigit( c ) )
            *n = ( 10 * ( * n ) ) + c - '0';
}

int getline( char s[] )
{
    if ( eofread == TRUE ) return FAIL;

    char c;
    int i = 0;

    while ( ( c = readc ) != EOF && c != '\n' )
        s[i++] = c;

    s[i] = '\0';

    if ( c == EOF ) eofread = TRUE;

    return i;
}

int split( char line[] )
{
    int i = 0, j = 0, wc = -1, st = OUT;

    while ( line[i] )
    {
        if ( isalpha( line[i] ) )
        {
            if ( st == OUT )
                wc++;
            st = IN;
            input[wc][j] = line[i];
            j++;
        }
        else
        {
            if ( st == IN )
            {
                input[wc][j] = '\0';
            }

            st = OUT;
            j = 0;
        }
        i++;
    }

    if ( st == IN )
    {
        input[wc][j] = '\0';
    }

    return wc + 1;
}

void init()
{
    int i;
    for ( i = 0; i < ALPHA; i++ )
    {
        map[i] = -1 ;
        parent[i] = -1;
    }
}

void construct_candidates( int k, int c[], int *ncandidates, int len )
{
    int i;
    *ncandidates = 0;
    for ( i = 0; i < ndw; i++ )
    {
        if ( dlengths[i] == len )
        {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }
}

bool backtrack( int k )
{
    int i, j, ncandidates;
    int push;
    int len = strlen( input[k] );
    int c[MAXWORDS];
    char temp[ALPHA];
    bool failed;

    if ( k == niw )
    {
        return TRUE;
    }

    construct_candidates( k, c, &ncandidates, len );

    for ( i = 0; i < ncandidates; i++ ) /* for each candidate */
    {
        failed = FALSE;
        push = 0;

        for ( j = 0; j < len && !failed; j++ )
        {
            /* c[i] contains an index of the dictionary */
            /* we want to change input[k][j] to dictionary[ c[i] ][j] */
            if ( map[ input[k][j] - OFFSET ] == -1 && parent[ dictionary[ c[i] ][j] - OFFSET  ] == -1 ) /* not yet mapped */
            {
                map[ input[k][j] - OFFSET ] = dictionary[ c[i] ][j];
                parent[ dictionary[ c[i] ][j] - OFFSET ] = input[k][j];
                temp[push++] = input[k][j];
                temp[push++] = dictionary[ c[i] ][j];
            }
            else if ( map[ input[k][j] - OFFSET ] == dictionary[ c[i] ][j]
                     &&
                     parent[ dictionary[ c[i] ][j] - OFFSET ] == input[k][j] )
            {
                /* already been mapped, but to the "correct" character */
                continue;
            }
            else /* there is a failure */
            {
                failed = TRUE;
            }
        }

        if ( !failed && backtrack( k + 1 ) )
        {
            return TRUE;
        }
        else
        {
            for ( j = 0; j < push; j += 2 )
            {
                map[ temp[j] - OFFSET ] = -1;
                parent[ temp[j + 1] - OFFSET ] = -1;
            }
        }
    }

    return FALSE;
}

void process( char line[] )
{
    int i;
    for ( i = 0; i < nic; i++ )
    {
        if ( isalpha( line[i] ) )
            putchar( map[ line[i] - OFFSET ] );
        else
            putchar( line[i] );
    }
    putchar('\n');
}

void failed( char line[] )
{
    int i;
    for ( i = 0; i < nic; i++ )
    {
        if ( isalpha( line[i] ) )
            putchar('*');
        else
            putchar( line[i] );
    }
    putchar('\n');
}

int main()
{
    char line[MAXL];
    int i;

    eofread = FALSE;

    readint( &ndw );

    for ( i = 0; i < ndw; i++ )
    {
        dlengths[i] = getline( dictionary[i] );
    }

    while ( ( nic = getline( line ) ) != FAIL )
    {
        niw = split( line );

        init();

        if ( backtrack( 0 ) )
            process( line );
        else
            failed( line );
    }

    return 0;
}
