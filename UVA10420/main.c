#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 2000
#define MAXCHARS 75

/* ACCEPTED */

struct node {

    char *word;
    int freq;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *nalloc( char *s );

node *root = NULL;

void insert( char *s )
{
    node *temp = root;
    node *prev = NULL;
    int comp;

    while ( temp != NULL )
    {
        comp = strcmp( temp->word, s );

        if ( comp == 0 ) /* repeated word */
        {
            temp->freq = temp->freq + 1;
            return;
        }

        prev = temp;

        temp = ( comp > 0 ) ? temp->left : temp->right;
    }

    if ( prev == NULL )
        root = nalloc( s );
    else
    {
        if ( comp > 0 )
            prev->left = nalloc( s );
        else
            prev->right = nalloc( s );
    }
}

void show_tree( node *temp )
{
    if ( temp != NULL )
    {
        show_tree( temp->left );
        printf("%s %i\n", temp->word, temp->freq );
        show_tree( temp->right );
    }
}

node *nalloc( char *s )
{
    node *temp = ( node * ) malloc( sizeof( node ) );
    temp->word = ( char * ) malloc( strlen( s ) + 1 );
    strcpy( temp->word, s );
    temp->freq = 1;
    temp->left = temp->right = NULL;
    return temp;
}

int main()
{
    int x;
    int i;
    char line[MAXCHARS + 1];

    scanf( "%i", &x );

    for ( i = 0; i < x; i++ )
    {
        scanf("%s", line );
        insert( line );
        fgets( line, MAXCHARS, stdin );
    }

    show_tree( root );

    return 0;
}
