#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.012 */

#define MAXV 100

char a[MAXV][MAXV];

void dfs( int i, int j, int m, int n )
{
    if ( i < 0 || i >= m || j < 0 || j >= n || a[i][j] != '@' )
    {
        return;
    }

    a[i][j] = '.';
    dfs( i - 1, j - 1, m, n );
    dfs( i - 1, j, m, n );
    dfs( i - 1, j + 1, m, n );
    dfs( i, j - 1, m, n );
    dfs( i, j + 1, m, n );
    dfs( i + 1, j - 1, m, n );
    dfs( i + 1, j, m, n );
    dfs( i + 1, j + 1, m, n );
}

int main()
{
    int i, j, m, n, x;

    for ( i = 0; i < MAXV; i++ )
        for ( j = 0; j < MAXV; j++ )
            a[i][j] = '.';

    while ( scanf("%i %i", &m, &n ) == 2 && ( m != 0 && n != 0 ) )
    {
		getchar();
        for ( i = 0; i < m; i++ )
        {
            for ( j = 0; j < n; j++ )
            {
                a[i][j] = getchar();
            }
            getchar();
        }
        x = 0;
        for ( i = 0; i < m; i++ )
        {
            for ( j = 0; j < n; j++ )
            {
                if ( a[i][j] == '@' )
                {
                    dfs( i, j, m, n );
                    x++;
                }
            }
        }
        printf("%i\n", x );
    }
    return 0;
}
