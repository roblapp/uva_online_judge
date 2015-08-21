#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED 0.012 */

#define MAXLEN 100000

int is_subsequence( char *t, char *p )
{
    int i;
    int n = strlen( t );
    int m = strlen( p );
    int y = 0;

    for ( i = 0; i < n && y < m; i++ )
    {
        if ( t[i] == p[y] )
            y++;
    }
    return ( y == m );
}

int main()
{
    char t[MAXLEN];
    char p[MAXLEN];

    while ( scanf("%s %s", p, t ) == 2 )
    {
        if ( is_subsequence( t, p ) )
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
