#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.012 */

#define MAXR 5000
#define NCOLS 25

int a[MAXR + 1];
int nrows;

int main()
{
    int i, j, x, min, spc;
    char c;

    while ( scanf("%i", &nrows ) == 1 && nrows != 0 )
    {
        vspc = 0;
        min = NCOLS;

        for ( i = 0; i < nrows; i++ )
        {
            x = 0;

            while ( ( c = getchar() ) != 'X' )
                ;
            ungetc( c, stdin );

            for ( j = 0; j < NCOLS; j++ )
            {
                c = getchar();

                if ( c == ' ' ) x++;
            }

            a[i] = x;
            if ( x < min ) min = x;
        }

        for ( j = 0; j < nrows; j++ )
            vspc = vspc + a[j] - min;

        if ( nrows == 1 )
            printf("0\n");
        else
            printf("%i\n", vspc );
    }

    return 0;
}
