#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED 0.016 */

#define MAXL 1001

int lcs( char *s, char *t )
{
    int i;
    int j;
    int n = strlen( s );
    int m = strlen( t );
    int dp[n + 1][m + 1];

    for ( i = 0; i <= n; i++ )
        for ( j = 0; j <= m; j++ )
            dp[i][j] = 0;

    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            if ( s[i-1] == t[j-1] )
                dp[i][j] = dp[i-1][j-1] + 1;
            else if( dp[i-1][j] >= dp[i][j-1] )
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-1];
        }
    }

    return dp[n][m];
}

int main()
{
    char s[MAXL];
    char t[MAXL];

    /* use gets so that we can input empty lines */

    while ( gets( s ) && gets( t ) )
        printf("%i\n", lcs( s, t ) );

    return 0;
}
