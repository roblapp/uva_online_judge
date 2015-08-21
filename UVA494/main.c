#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define TRUE 1
#define FALSE 0

int main()
{
    char c;
    int count = 0;
    int word = FALSE;

    while ( ( c = getchar() ) != EOF )
    {
        if ( isalpha( c ) )
        {
            word = TRUE;
        }
        else
        {
            if ( word == TRUE )
            {
                count++;
            }

            if ( c == '\n' )
            {
                printf("%i\n", count);
                count = 0;
            }

            word = FALSE;
        }
    }

    return 0;
}
