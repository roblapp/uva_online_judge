#include <stdio.h>
#include <ctype.h>

/* ACCEPTED 0.015 */

enum state
{
    IN, OUT
};

typedef enum state state;

int main()
{
    char c;
    int x = 0, p = 0;
    state s = OUT;

    while ( ( c = getchar() ) != EOF )
    {
        if ( c == '|' )
        {
            if ( s == IN )
            {
                printf("%c", x );
                x = 0;
                s = OUT;
            }
            else
            {
                s = IN;
                x = 0;
                p = 7;
            }
        }
        else if ( c == ' ' )
            p--;
        else if ( c == 'o' ) /* 1 */
        {
            x = x + ( 1 << p );
            p--;
        }
    }

    return 0;
}
