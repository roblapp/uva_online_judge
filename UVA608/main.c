#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED
    UVA: time: 0.029
    update to time: 0.028
    POJ: code length: 2843B, memory: 352K, time: 0ms
    updated to code length: 2797B
*/

#define TRUE 1
#define FALSE 0
#define MAXL 12

typedef int boolean;

void clear_comp( boolean candidates[], char scale[] )
{
    int i, j;
    boolean res;

    for ( i = 0; i < MAXL; i++ )
    {
        res = FALSE;

        for ( j = 0; scale[j] != '\0'; j++ )
        {
            if ( ( i + 'A' ) == scale[j] )
            {
                res = TRUE;
                break;
            }
        }
        if ( !res ) candidates[i] = FALSE; /* no longer a candidate */
    }
}

void clear_items( boolean candidates[], char scale[] )
{
    int i;

    for ( i = 0; scale[i] != '\0'; i++ )
        candidates[ scale[i] - 'A' ] = FALSE;
}

void solve( boolean light[], boolean heavy[], char left[], char right[], int outcome )
{
    int i, j;
    char scale[MAXL + MAXL];
    j = 0;
    for ( i = 0; left[i] != '\0';  i++ )
        scale[j++] = left[i];
    for ( i = 0; right[i] != '\0';  i++ )
        scale[j++] = right[i];
    scale[j] = '\0';

    if ( outcome == -1 ) /* scale is down */
    {
        clear_comp( light, scale );
        clear_comp( heavy, scale );
        clear_items( heavy, left );
        clear_items( light, right );
    }
    else if ( outcome == 0 ) /* scale is even */
    {
        clear_items( light, scale );
        clear_items( heavy, scale );
    }
    else /* scale is up */
    {
        clear_comp( light, scale );
        clear_comp( heavy, scale );
        clear_items( heavy, right );
        clear_items( light, left );
    }
}

int main()
{
    int i, n, j, k;
    char left[MAXL], right[MAXL], outcome[MAXL];
    boolean light[MAXL], heavy[MAXL];

    scanf("%i", &n );

    for ( i = 0; i < n; i++ )
    {
        for ( j = 0; j < MAXL; j++ ) light[j] = heavy[j] = TRUE;

        for ( j = 0; j < 3; j++ )
        {
            scanf( "%s %s %s", left, right, outcome );
            if ( outcome[0] == 'd' )
                solve( light, heavy, left, right, -1 );
            else if ( outcome[0] == 'e' )
                solve( light, heavy, left, right, 0 );
            else
                solve( light, heavy, left, right, 1 );
        }

        for ( k = 0; k < MAXL + MAXL; k++ )
        {
            if ( k < MAXL && light[k] )
            {
                printf("%c is the counterfeit coin and it is light.\n", ( k + 'A' ) );
                break;
            }
            else if ( heavy[ k % MAXL ] )
            {
                printf("%c is the counterfeit coin and it is heavy.\n", ( ( k % MAXL ) + 'A' ) );
                break;
            }
        }
    }

    return 0;
}
