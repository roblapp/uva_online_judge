#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{
    char a[MAX][MAX + 1];
    char c;
    int row = 0, col = 0, i, max_len = 0;

    for ( row = 0; row < MAX; row++ )
    {
        for ( col = 0; col < MAX + 1; col++ )
        {
            a[row][col] = '\0';
        }
    }

    row = col = 0;

    while ( ( c = getchar() ) != EOF )
    {
        if ( c == '\n')
        {
            a[row++][col] = '\0'; /*redundant*/
            col = 0;
        }
        else
        {
            a[row][col++] = c;

            if ( col > max_len )
                max_len = col;
        }
    }

    for ( col = 0; col < max_len; col++ )
    {
        for ( i = row - 1; i >= 0; i-- )
        {
            if ( a[i][col] != '\0' )
            {
                printf("%c", a[i][col] );
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }

    return 0;
}
