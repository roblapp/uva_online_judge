#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.013 */

#define MAXN 30000

long long ways[MAXN + 1];

void count()
{
    int i, j, n = 11;
    int denom[] = { 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000 };

    for ( i = 0; i <= MAXN; i++ ) ways[i] = 0;

    ways[0] = 1;

    for ( i = 0; i < n; i++ )
    {
        for ( j = denom[i]; j <= MAXN; j += 5 )
        {
            ways[j] += ways[ j - denom[i] ];
        }
    }
}

int main()
{
    int a, b, n;

    count();

    while ( scanf("%i.%i", &a, &b ) != EOF )
    {
        if ( a == 0 && b == 0 )
            break;
        n = a*100 + b;
        printf("%3i.%.2i%17lli\n", a, b, ways[n] );
    }

    return 0;
}
