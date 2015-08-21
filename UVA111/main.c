#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.018 */

#define MAXE 20
#define TRUE 1
#define FALSE 0

/* returns -1 if a came before b, 1 if a came after b */
int compare( int seq[], int n, int a, int b )
{
    int i = 1;

    while ( seq[i] != a && seq[i] != b )
        i++;

    if ( seq[i] == a ) return -1;

    return TRUE;
}

int solve( int seq[], int a[], int n )
{
    int i;
    int j;
    int m;
    int r = 0;
    int sol[MAXE + 1];

    for ( i = 0; i <= MAXE; i++ )
        sol[i] = 0;

    sol[1] = 1;

    for ( i = 2; i <= n; i++ )
    {
        m = 0;

        for ( j = 1; j < i; j++ )
        {
            if ( compare( seq, n, a[i], a[j] ) > 0 ) /* if a[i] < a[j] */
                if ( sol[j] > m )
                    m = sol[j];
        }

        sol[j] = m + 1;

        if ( sol[j] > r ) r = sol[j];
    }

    return r;
}

int main()
{
    /* things to remember: this problem had a strange input that confused me.
    one of the example inputs for the proper sequence was:
    10
    3 1 4 6 8 10 9 5 7 2
    and then one of the students answers was
    2 10 1 3 8 4 9 5 7 6

    BUT, this is not the proper sequence of events. this merely denotes that
    event 1 has rank 2
    event 2 has rank 10
    event 3 has rank 1
    event 4 has rank 3
    event 5 has rank 8
    and so on...

    thus, the sequences we want to find the LCS of is
    the solution sequence
    2 10 1 3 8 4 9 5 7 6
    3 1 4 6 8 10 9 5 7 2
    */
    char c;
    int seq[MAXE + 1];
    int s[MAXE + 1];
    int n;
    int i;
    int x;

    scanf("%i", &n );

    for ( i = 0; i < n; i++ )
    {
        scanf("%i", &x);
        seq[x] = i + 1;
    }

    while ( ( c = getchar() ) != EOF )
    {
        c = getchar();
        if ( c == EOF ) break;
        else ungetc( c, stdin );
        for ( i = 0; i < n; i++ )
        {
            scanf("%i", &x );
            s[x] = i + 1;
        }
        printf("%i\n", solve( seq, s, n ) );
    }

    return 0;
}
