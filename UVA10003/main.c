#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* ACCEPTED 0.309 */

/*
I did NOT solve this one on my own. I was confused on it. I knew it was
solved by dynamic programming but I did not think to use recursion. I
basically had to copy the solution from the Internet.
*/

#define MAXN 51

int places[MAXN];
int dp[MAXN][MAXN];

void init()
{
    int i, j;
    for ( i = 0; i < MAXN; i++ )
        for ( j = 0; j < MAXN; j++ )
            dp[i][j] = -1;
}

int cost( int start, int end )
{
    int i;
    int c;
    int mincost;

    c = 0;
    mincost = INT_MAX;

    if ( end == start + 1 ) /* cost( a_i, a_i+1) is 0... no more cuts can be made */
        return 0;

    if ( dp[start][end] != -1 ) /* memoized data */
        return dp[start][end];

    for ( i = start + 1; i < end; i++ ) /* i is the intermediate value where start < i < end */
    {                                   /* places[e] - places[s] is the length of the stick */
        c = cost( start, i ) + cost( i, end ) + ( places[end] - places[start] );
        /* there are two subproblems for each cut... the left sub stick and the right sub stick.
        so we must make recursive calls for each sub stick */
        if ( c < mincost ) mincost = c;
    }

    return ( dp[start][end] = mincost );
}

int main()
{
    int i, len, nc; /* length and number of cuts */

    while ( scanf("%i", &len ) && len )
    {
        scanf("%i", &nc ); /* read in number of cuts */

        for ( i = 1; i <= nc; i++ )
            scanf("%i", &places[i] );

        places[0] = 0;  /* places is the length of the stick in that position */
        places[nc + 1] = len;

        init();

        printf("The minimum cutting is %i.\n", cost( 0, nc + 1 ) );
    }

    return 0;
}
