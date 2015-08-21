#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.012 */

#define MAXLEN 100
#define MAXLINES 10000
#define TRUE 1
#define FALSE 0

typedef struct entry entry;
typedef int bool;
typedef enum state state;

enum state {

    IN, OUT
};

struct entry
{
    char key[MAXLEN + 1];
    bool dup;
    struct entry *next;
};

entry *table[MAXLINES];
char data[MAXLINES][MAXLEN];

void init()
{
    int i;
    for ( i = 0; i < MAXLINES; i++ ) table[i] = NULL;
}

unsigned hash( char *key )
{
    char *p = key;
    unsigned h = 0;

    while ( *p )
    {
        h ^= ( h << 5 ) + ( h >> 2 ) + *p;
        p++;
    }

    return h % MAXLINES;
}

int compare_char( const void *a, const void *b )
{
    return * ( char * ) a - * ( char * ) b;
}

bool search( char *key )
{
    char tk[MAXLEN + 1];
    int i;
    unsigned index;
    entry *temp;

    for ( i = 0; key[i] != '\0'; i++ )
        tk[i] = tolower( key[i] );
    tk[i] = '\0';

    if ( i > 1 )
        qsort( tk, i - 1, sizeof( char ), compare_char );

    index = hash( tk );

    temp = table[index];

    while ( temp != NULL )
    {
        if ( strcmp( temp->key, tk ) == 0 )
        {
            if ( temp->dup )
                return TRUE;
            else
                return FALSE;
        }
        temp = temp->next;
    }
    return FALSE;
}

void insert( char *key )
{
    char tk[MAXLEN + 1];
    int i;
    unsigned index;
    entry *temp;

    for ( i = 0; key[i] != '\0'; i++ )
        tk[i] = tolower( key[i] );
    tk[i] = '\0';

    if ( i > 1 )
        qsort( tk, i - 1, sizeof( char ), compare_char );

    index = hash( tk );

    temp = table[index];

    while ( temp != NULL )
    {
        if ( strcmp( temp->key, tk ) == 0 )
        {
            temp->dup = TRUE;
            return;
        }
        temp = temp->next;
    }

    entry *n = ( entry * ) malloc ( sizeof ( entry ) );
    strcpy( n->key, tk );
    n->dup = FALSE;
    n->next = table[index];
    table[index] = n;
}

int get_lines()
{
    int i = 0, j = 0, wc = -1;
    state st = OUT;
    char c;

    while ( ( c = getchar() ) != '#' )
    {
        if ( isalpha( c ) )
        {
            if ( st == OUT )
                wc++;
            st = IN;
            data[wc][j] = c;
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

int compare( const void *a, const void *b )
{
    return strcmp( ( char * ) a, ( char * ) b );
}

int main()
{
    int i, n;

    n = get_lines(); /* O( NCHARS ) */

    qsort( data, n, MAXLEN, compare ); /* O( NWORDS*LOG( NWORDS ) ) */

    for ( i = 0; i < n; i++ ) /* O( NWORDS ) */
    {
        insert( data[i] ); /* O( WORDLENGTH*LOG( WORDLENGTH ) ) */
    }

    for ( i = 0; i < n; i++ ) /* O( NWORDS ) */
    {
        if ( !search( data[i] ) )
        {
            printf("%s\n", data[i] );
        }
    }

    return 0;
}
