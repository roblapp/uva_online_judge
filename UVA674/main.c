#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.029 - 0.036 */

#define MAXN 7500

long ways[MAXN];

void count_ways()
{
    int i, j;
    int denom[] = { 1, 5, 10, 25, 50 };
    ways[0] = 1;
    for ( i = 0; i < 5; i++ )
        for ( j = denom[i]; j < MAXN; j++ )
            ways[j] += ways[ j - denom[i] ];
}

int main()
{
    int n;

    count_ways();

    while ( scanf("%i", &n ) != EOF )
        printf("%li\n", ways[n] );


    return 0;
}
