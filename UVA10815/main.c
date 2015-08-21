#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAXLINE 200

/*Andy's Dictionary*/

struct node {

    char *key;
    struct node *left;
    struct node *right;
};

typedef struct node node;

node *root;

void read_line();

node * insert( node *temp, char *key )
{
    int comp;

    if ( temp == NULL )
    {
        /*new word*/
        temp = (node *) malloc( sizeof( node ) );
        temp->key = (char *) malloc( strlen( key ) + 1 );
        strcpy( temp->key, key );
        temp->left = temp->right = NULL;
    }
    else if ( ( comp = strcmp( temp->key, key ) ) == 0 )
    {
        /*duplicate*/
        return temp;
    }
    else if ( comp > 0 )
    {
        temp->left = insert( temp->left, key );
    }
    else
    {
        temp->right = insert( temp->right, key );
    }

    return temp;
}

void show_tree( node *temp )
{
    if ( temp != NULL )
    {
        show_tree( temp->left );
        printf("%s\n", temp->key );
        show_tree( temp->right );
    }
}

int main()
{
    read_line();

    show_tree( root );

    return 0;
}

void read_line()
{
    char a[MAXLINE + 1];
    int c, count = 0;

    while ( ( c = tolower( getchar() ) ) != EOF )
    {
        if ( !isalpha( c ) )
        {
            a[count] = '\0';
            if ( *a != '\0')
                root = insert( root, a );
            count = 0;
        }
        else
        {
            a[ count++ ] = c;
        }
    }
}
