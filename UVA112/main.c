#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED */

#define MAX 5000

/* must input the string with the ith position referencing the first '(' */
int is_leaf( char *s, const int len, int i )
{
    int count = 1; /* when count becomes 0, we are at the end of the node */
    int occ = 0;
    int x = 0; /* marked true if previous character was a digit */

    while ( ++i < len && count != 0 )
    {
        if ( s[i] == '(' )
                count++;
        else if ( s[i] == ')' )
            count--;
        if ( isdigit( s[i] ) )
        {
            if ( x == 0 ) occ++;
            x = 1;
        }
        else
            x = 0;
        if ( count > 2 || occ > 1 )
            return 0;
    }

    return ( occ == 1 && count == 0 );
}

/* assumes data is passed to function with i referring to first ( */
int node_data( char *s, const int len, int i )
{
    int sign = 1;
    int x = 0;
    i++;

    while ( i < len && ( isspace( s[i] ) ) )
        i++;

    if ( s[i] == '-' )
    {
        sign = -1;
        i++;
    }

    while ( i < len && isdigit( s[i] ) )
    {
        x = 10 * x + ( s[i] - '0' );
        i++;
    }

    return sign * x;
}

int is_null( char *s, const int len, int i )
{
    i++;

    while ( i < len && s[i] != ')' )
    {
        if ( !isspace( s[i] ) )
            return 0;
        i++;
    }

    return 1;
}

/* always get passed into the function with i referring to the first ( */
int parse( char *s, const int len, int i, int sum )
{
    int x;
    int pc; /* parenthesis counter */
    int left, right;

    if ( is_null( s, len, i ) )
        return 0;

    x = node_data( s, len, i );

    /* check if leaf first */
    if ( is_leaf( s, len, i ) ) /* if the node is a leaf node */
    {
        if ( sum - x == 0 )
            return 1;
        else
            return 0;
    }

    i++; /* skip over first parenthesis */

    while ( i < len && s[i] != '(' )
        i++;

    /* now we can recursively call left child */
    left = i;

    pc = 1;

    i++;

    while ( i < len && pc != 0 )
    {
        if ( s[i] == '(' )
            pc++;
        else if ( s[i] == ')' )
            pc--;
        i++;
    }

    while ( i < len && ( isspace( s[i] ) ) )
        i++;

    right = i;

    return parse( s, len, left, sum - x ) || parse( s, len, right, sum - x );
}

void traverse( char *s, const int len, int sum )
{
    if ( parse( s, len, 0, sum ) )
        printf("yes\n");
    else
        printf("no\n");
}

int main()
{
    char line[MAX];
    char c;
    int sum;
    int pc;
    int len;
    int line_ptr;

    while ( scanf("%i", &sum ) != EOF )
    {
        while ( ( c = getchar() ) != '(' )
            ;

        line_ptr = 0;
        line[line_ptr] = c;
        len = 1;
        pc = 1;

        while ( pc != 0 )
        {
            c = getchar();

            if ( c == '(' )
                    pc++;
            else if ( c == ')' )
                pc--;

            if ( !isspace( c ) )
            {
                line[++line_ptr] = c;
                len++;
            }
        }
        line[++line_ptr] = '\0';

        char *tree = ( char * ) malloc( len + 1 );

        strcpy( tree, line );

        traverse( tree, len, sum );

        free( tree );
    }

    return 0;
}
