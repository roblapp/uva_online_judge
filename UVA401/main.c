#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

int mirror( char c )
{
    if ( c == 'A' )
    {
        return c;
    }
    else if ( c == 'E' )
    {
        return '3';
    }
    else if ( c == 'H' )
    {
        return c;
    }
    else if ( c == 'I' )
    {
        return c;
    }
    else if ( c == 'J' )
    {
        return 'L';
    }
    else if ( c == 'L' )
    {
        return 'J';
    }
    else if ( c == 'M' )
    {
        return 'M';
    }
    else if ( c == 'O')
    {
        return 'O';
    }
    else if ( c == 'S' )
    {
        return '2';
    }
    else if ( c >= 'T' && c <= 'Y' )
    {
        return c;
    }
    else if ( c == 'Z' )
    {
        return '5';
    }
    else if ( c == '1' )
    {
        return c;
    }
    else if ( c == '2')
    {
        return 'S';
    }
    else if ( c == '3' )
    {
        return 'E';
    }
    else if ( c == '5' )
    {
        return 'Z';
    }
    else if ( c == '8' )
    {
        return c;
    }

    return 0;
}

int is_mirrored( char *s )
{
    int i = 0, j = strlen( s ) - 1;

    while ( i <= j && mirror( *(s + i) ) == *(s + j ) )
    {
        i++; j--;
    }

    return ( i <= j ) ? FALSE : TRUE;
}

int is_palindrome( char *s )
{
    int i = 0, j = strlen( s ) - 1;

    while ( i <= j && *( s + i ) == *( s + j ) )
    {
        i++; j--;
    }

    return ( i <= j ) ? FALSE : TRUE;
}

int main()
{
    char *s = ( char * ) malloc( 21 );
    int x, y;

    while ( scanf( "%s", s ) != EOF )
    {
        x = is_palindrome( s );
        y = is_mirrored( s );

        if ( !x && !y )
        {
            printf("%s -- is not a palindrome.\n\n", s );
        }
        else if ( x && !y )
        {
            printf("%s -- is a regular palindrome.\n\n", s );
        }
        else if ( !x && y )
        {
            printf("%s -- is a mirrored string.\n\n", s );
        }
        else
        {
            printf("%s -- is a mirrored palindrome.\n\n", s );
        }
    }

    free( s );

    return 0;
}
