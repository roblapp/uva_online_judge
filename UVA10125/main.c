#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 1.132 */

#define MAXN 1000
#define SIZE 8000
#define TRUE 1
#define FALSE 0

struct entry {

    int a;
    int b;
    int sum;
    struct entry *next;
};

typedef struct entry entry;

entry *table[SIZE];
int nelem;

entry *ealloc( int a, int b )
{
    entry *temp = ( entry * ) malloc ( sizeof ( entry ) );
    temp->a = a;
    temp->b = b;
    temp->sum = a + b;
    return temp;
}

int compare( const void *pa, const void *pb )
{
    return *( int * ) pa - *( int * ) pb;
}

unsigned hash( int sum )
{
    unsigned hashval = ( sum % 10 ) + '0';

    while ( sum > 0 )
    {
        hashval = ( ( sum % 10 ) + '0' ) + 31 * hashval;
        sum /= 10;
    }

    return hashval % SIZE;
}

int contains( int c, int d )
{
    int res = d - c;
    int index = hash( res );

    entry *temp = table[index];

    while ( temp != NULL )
    {
        if ( temp->sum == res)
            if ( temp->a != c && temp->b != c && temp->a != d && temp->b != d  )
                return TRUE;

        temp = temp->next;
    }

    return FALSE;
}

void insert( int a, int b )
{
    int index = hash( a + b );

    entry *temp = table[index];

    while ( temp != NULL )
    {
        if ( temp->a == a && temp->b == b )
            return;
        temp = temp->next;
    }

    entry *n = ealloc( a, b );
    n->next = table[index];
    table[index] = n;
}

int memoize( int a[], int n )
{
    int i, j;
    int x = 0;

    for ( i = 0; i < SIZE; i++ ) table[i] = NULL;

    for ( i = 0; i < n - 1; i++ )
    {
        for ( j = i + 1; j < n; j++ )
        {
            if ( a[i] != a[j] )
            {
                insert( a[i], a[j] );
                x++;
            }
        }
    }

    return x;
}

void solve( int a[], int n )
{
    int i;
    int j;
    int c;
    int d;

    for ( i = n - 1; i > 0; i-- )
    {
        d = a[i];

        for ( j = i - 1; j >= 0; j-- )
        {
            c = a[j];

            if ( c != d && contains( c, d ) )
            {
                printf("%i\n", d );
                return;
            }
        }
    }
    printf("no solution\n");
}

int main()
{
    int nnums;
    int i;

    while ( scanf("%i", &nnums ) != EOF && nnums != 0 )
    {
        int *set = ( int * ) malloc( nnums * sizeof( int ) );

        for ( i = 0; i < nnums; i++ )
        {
            scanf("%i", ( set + i ) );
        }

        qsort( set, nnums, sizeof( int ), compare );

        memoize( set, nnums );

        solve( set, nnums );

        free( set );
    }

    return 0;
}
