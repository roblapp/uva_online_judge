#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.015*/

#define MAXN 30000

long long int ways[MAXN + 1];

void solve()
{
    int i, j;
    int den[] = { 1, 5, 10, 25, 50 };

    for ( i = 0; i <= MAXN; i++ )
        ways[i] = 0;
    ways[0] = 1;

    for ( i = 0; i < 5; i++ )
        for ( j = den[i]; j <= MAXN; j++ )
            ways[j] += ways[j - den[i]];
}

int main()
{
    int n;
    long long int r;

    solve();

    while ( scanf("%i", &n ) == 1 )
    {
        r = ways[n];
        if ( r == 1 )
            printf("There is only 1 way to produce %i cents change.\n", n );
        else
            printf("There are %lli ways to produce %i cents change.\n", r, n );
    }

    return 0;
}
