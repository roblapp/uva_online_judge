#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.012 */

#define MAXN 102

char a[MAXN][MAXN];
int n, m;

void init()
{
    int i, j;
    for ( i = 0; i < MAXN; i++ )
        for ( j = 0; j < MAXN; j++ )
            a[i][j] = 0;
}

void show( int f)
{
    int i, j;
    printf("Field #%i:\n", f );
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            if ( a[i][j] == '*' )
                putchar( a[i][j] );
            else
                putchar( a[i][j] + '0' );
        }
        putchar('\n');
    }
}

int main()
{
    int i, j, f = 1, seen = 0;
    char c;

    while ( scanf("%i %i", &n, &m ) == 2 && ( n != 0 || m != 0 ) )
    {
        init();

        for ( i = 1; i <= n; i++ )
        {
            getchar();

            for ( j = 1; j <= m; j++ )
            {
                c = getchar();
                if ( c == '*' )
                    a[i][j] = '*';
            }
        }

        for ( i = 1; i <= n; i++ )
        {
            for ( j = 1; j <= m; j++ )
            {
                if ( a[i][j] == '*' )
                {
                    if ( a[i-1][j-1] != '*' )
                        a[i-1][j-1]++;
                    if ( a[i-1][j] != '*' )
                        a[i-1][j]++;
                    if ( a[i-1][j+1] != '*' )
                        a[i-1][j+1]++;
                    if ( a[i][j-1] != '*' )
                        a[i][j-1]++;
                    if ( a[i][j+1] != '*' )
                        a[i][j+1]++;
                    if ( a[i+1][j-1] != '*' )
                        a[i+1][j-1]++;
                    if ( a[i+1][j] != '*' )
                        a[i+1][j]++;
                    if ( a[i+1][j+1] != '*' )
                        a[i+1][j+1]++;
                }
            }
        }
        if ( seen )
            putchar('\n');
        seen = 1;
        show( f );
        f++;
    }

    return 0;
}
