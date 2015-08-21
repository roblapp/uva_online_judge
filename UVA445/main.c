#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.022 */

int main()
{
    char c;
    int i, x = 0;

    while ( ( c = getchar() ) != EOF )
    {
        if ( c == '\n' || c == '!' )
            putchar('\n');
        else if ( isspace( c ) )
            ;
        else if ( isdigit( c ) )
            x += c - '0';
        else
        {
            if ( c == 'b' ) c = ' ';
            for ( i = 0; i < x; i++ )
                putchar( c );
            x = 0;
        }
    }

    return 0;
}
