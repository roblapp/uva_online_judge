#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.013 */

#define MAXKEYWORD 11
#define MAXL 200
#define SIZE 2000
#define TRUE 1
#define FALSE 0
#define IN 1
#define OUT 0

struct i_entry {

    char iw[MAXKEYWORD];
    struct i_entry *next;
};

struct t_entry {

    char keyword[MAXL];
    char title[MAXL];
    int original_position;
};

typedef struct i_entry i_entry;
typedef struct t_entry t_entry;

i_entry *table[SIZE];
t_entry data[SIZE];
int push_pos;

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

int entry_compare( const void *a, const void *b )
{
    t_entry ta = *( t_entry * )a;
    t_entry tb = *( t_entry * )b;

    int cmp = strcmp( ta.keyword, tb.keyword );

    if ( cmp < 0 )
        return -1;
    else if ( cmp > 0 )
        return 1;
    else
    {
        if ( ta.original_position < tb.original_position )
            return -1;
        else if ( ta.original_position > tb.original_position )
            return 1;
        else
            return 0;
    }
}

void insert( char line[] )
{
    unsigned index = hash( line );
    i_entry *n = ( i_entry * ) malloc ( sizeof ( i_entry ) );
    strcpy( n->iw, line );
    n->next = table[index];
    table[index] = n;
}

int ignore_word( char word[] )
{
    unsigned index = hash( word );
    i_entry *temp = table[index];

    while ( temp != NULL )
    {
        if ( strcmp( temp->iw, word ) == 0 )
            return TRUE;
        temp = temp->next;
    }
    return FALSE;
}

void show()
{
    int i;

    for ( i = 0; i < push_pos; i++ )
        printf("%s\n", data[i].title );
}

int split_data( char line[], int ln )
{
    int i = 0, j = 0, k, x = 0, state = OUT, sp, ep;
    char word[MAXL];

    while ( line[i] )
    {
        if ( isalpha( line[i] ) )
        {
            if ( state == OUT )
                sp = i;
            word[j++] = line[i];
            state = IN;
        }
        else
        {
            j = 0;
            state = OUT;
        }

        if ( line[i+1] == '\0' || !isalpha( line[i+1] ) )
        {
            if ( state == IN )
            {
                word[j] = '\0';
                ep = i;
                x++;

                if ( !ignore_word( word ) )
                {
                    t_entry n;
                    for ( k = 0; word[k] != '\0'; k++ )
                        word[k] = toupper( word[k] );
                    strcpy( n.keyword, word );
                    for ( k = sp; k <= ep; k++ )
                        line[k] = toupper( line[k] );
                    strcpy( n.title, line );
                    for ( k = sp; k <= ep; k++ )
                        line[k] = tolower( line[k] );
                    n.original_position = ln;
                    data[push_pos++] = n;
                }

                j = 0;
            }
        }
        i++;
    }

    return x;
}

int getline( char s[] )
{
    char c;
    int i = 0;

    while ( ( c = getchar() ) != EOF && c != '\n' )
        s[i++] = tolower( c );

    s[i] = '\0';

    return i;
}

int main()
{
    char line[MAXL];
    int lnum = 0;

    push_pos = 0;

    while ( scanf("%s", line ) == 1 && strcmp( line, "::") != 0 )
        insert( line );

    getchar();

    while ( getline( line ) > 0 )
    {
        split_data( line, lnum );
        lnum++;
    }

    qsort( &data, push_pos, sizeof( t_entry ), entry_compare );

    show();

    return 0;
}
