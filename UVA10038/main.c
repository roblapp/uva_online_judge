#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ACCEPTED 0.013 */

#define MAXN 3000
#define TRUE 1
#define FALSE 0

typedef int boolean;

int main()
{
    boolean a[MAXN + 1];
    int i, n, x, y, d, res;
    char c;

    while ( scanf("%i", &n ) != EOF )
    {
        scanf("%i", &x );
        res = TRUE;

        if ( n == 1 )
            goto FINISH;

        for ( i = 0; i <= n; i++ )
            a[i] = FALSE;

        for ( i = 0; i < n - 1; i++ )
        {
            scanf("%i", &y );
            d = abs( x - y );
            if ( d >= n || d == 0 || a[d] == TRUE )
            {
                while ( ( c = getchar() ) != '\n' )
                    ;
                res = FALSE;
                goto FINISH;
            }else
                a[d] = TRUE;

            x = y;
        }

        FINISH:
            if ( res )
                printf("Jolly\n");
            else
                printf("Not jolly\n");
    }

    return 0;
}
