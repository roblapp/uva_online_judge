#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.013 */

#define MAXN 100

long pas[MAXN + 1][MAXN + 1];

void solve()
{
    int i, j;

    for ( i = 0; i <= MAXN; i++ )
        pas[i][0] = 1;
    for ( i = 0; i <= MAXN; i++ )
        pas[i][i] = 1;

    for ( i = 2; i <= MAXN; i++ )
        for ( j = 1; j < i; j++ )
            pas[i][j] = pas[i-1][j-1] + pas[i-1][j];
}

int main()
{
    int n, k;

    solve();

    while ( ( scanf("%i %i", &n, &k ) == 2 ) && ( n != 0 || k != 0 ) )
        printf("%i things taken %i at a time is %li exactly.\n", n, k, pas[n][k] );

    return 0;
}
