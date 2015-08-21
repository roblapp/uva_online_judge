#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

/* ACCEPTED */

int *a;

int bubble_sort( const int len )
{
    int i, j, count = 0;

    for ( i = 0; i < len; i++ )
    {
        for ( j = i + 1; j < len; j++ )
        {
            if ( a[j] < a[i] )
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                count++;
            }
        }
    }

    return count;
}

int main()
{
    int ncases = 0;
    int ncars = 0;
    int i, j, k = 0;

    a = ( int * ) calloc( MAX, sizeof( int ) );

    scanf("%i", &ncases );

    for ( i = 0; i < ncases; i++ )
    {
        scanf("%i", &ncars );

        for ( j = 0; j < ncars; j++ )
        {
            scanf("%i", &a[k++] );
        }

        printf("Optimal train swapping takes %i swaps.\n", bubble_sort( ncars ) );
        memset( a, 0, ncars );
        k = 0;
    }

    free( a );

    return 0;
}
