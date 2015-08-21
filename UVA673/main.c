#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150

int main()
{
    int x = 0;
    int i;
    int last_item;
    int failed = 0;
    unsigned char stack[MAX];
    unsigned char c;
    unsigned char temp;

    while ( ( c = getchar() ) != '\n' )
    {
        x = 10*x + ( c - '0' );
    }

    for ( i = 0; i < x; i++ )
    {
        last_item = -1;
        failed = 0;

        while ( ( c = getchar() ) != '\n' )
        {
            if ( c == '(' || c == '[' )
            {
                stack[++last_item] = c;
            }
            else if ( c == ')' )
            {
                if ( last_item == -1 )
                {
                    failed = 1;
                    while ( ( c = getchar() ) != '\n' )
                        ;
                    break;
                }
                else
                {
                    temp = stack[last_item--];
                    if ( temp != '(' )
                    {
                        failed = 1;
                        while ( ( c = getchar() ) != '\n' )
                            ;
                        break;
                    }
                }
            }
            else if ( c == ']' )
            {
                temp = stack[last_item--];
                if ( temp != '[' )
                {
                    failed = 1;
                    while ( ( c = getchar() ) != '\n' )
                        ;
                    break;
                }
            }
        }

        if ( failed )
            printf("No\n");
        else
        {
            if ( last_item != -1 )
                printf("No\n");
            else
                printf("Yes\n");
        }
    }

    return 0;
}
