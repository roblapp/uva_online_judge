#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.012 */

#define TRUE 1
#define FALSE 0
#define MAXL 100
#define MAXE 21

enum state
{
    IN, OUT
};

struct entry
{
    char key[MAXL];
    struct entry *next;
};

typedef struct entry entry;
typedef int bool;
typedef enum state state;

entry *table[MAXL];
char data[MAXL][MAXL];

void init()
{
    int i;

    for ( i = 0; i < MAXL; i++ )
        table[i] = NULL;
}

unsigned hash( void *key )
{
    unsigned char *p = key;
    unsigned h = 0;

    while ( *p )
    {
        h ^= ( h << 5 ) + ( h >> 2 ) + *p;
        p++;
    }

    return h % MAXL;
}

void insert( char *key )
{
    unsigned index = hash( key );

    entry *temp = ( entry * ) malloc ( sizeof ( entry ) );
    strcpy( temp->key, key );
    temp->next = table[index];
    table[index] = temp;
}

bool search( char *key )
{
    unsigned index = hash( key );

    entry *temp = table[index];

    while ( temp != NULL )
    {
        if ( strcmp( key, temp->key ) == 0 )
            return TRUE;
        temp = temp->next;
    }

    return FALSE;
}

int split( char line[] )
{
    int i = 0, j = 0, wc = -1;
    state st = OUT;

    while ( line[i] )
    {
        if ( isalpha( line[i] ) )
        {
            if ( st == OUT )
                wc++;
            st = IN;
            data[wc][j] = tolower( line[i] );
            j++;
        }
        else
        {
            if ( st == IN )
                data[wc][j] = '\0';
            st = OUT;
            j = 0;
        }
        i++;
    }

    return wc + 1;
}

int main()
{
    int i, j, nw, ne, x, r, max, n = 1, nfound[MAXE];
    char line[MAXL], c, exc[MAXE][MAXL];

    while ( scanf("%i %i", &nw, &ne ) == 2 )
    {
        init();

        for ( i = 0; i < nw; i++ )
        {
            scanf("%s", line );
            insert( line );
        }

        while ( ( c = getchar() ) != '\n' ) /* scan down to next line */
            ;

        max = 0;

        for ( i = 0; i < ne; i++ )
        {
            fgets( exc[i], MAXL, stdin );

            x = split( exc[i] );

            r = 0;

            for ( j = 0; j < x; j++ )
                if ( search( data[j] ) )
                    r++;

            nfound[i] = r;

            if ( r > max )
                max = r;
        }

        printf("Excuse Set #%i\n", n);
        for ( i = 0; i < ne; i++ )
            if ( nfound[i] == max )
                printf("%s", exc[i] ); /* OMIT THE \n between prints because fgets retains the \n character!!! */
        printf("\n");
        n++;
    }

    return 0;
}
