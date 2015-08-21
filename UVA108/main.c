
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


/*
ACCEPTED
brute force max sum: 0.049
Kadanes algorithm: 0.015
*/

#define MAXN 100

int max( int a, int b )
{
    return ( a > b ) ? a : b;
}

/* brute force way -> O(n^2) */
int max_sub( int a[], int n )
{
    int row, col;
    int max = INT_MIN;
    int temp;

    for ( row = 0; row < n; row++ )
    {
        temp = 0;

        for ( col = row; col < n; col++ )
        {
            temp += a[col];

            if ( temp > max )
                max = temp;
        }
    }

    return max;
}

/* kadanes algorithm -> O(n) */
int kadanes( int a[], int n )
{
    int meh = a[0], msf = a[0], i;

    for ( i = 1; i < n; i++ )
    {
        if ( meh < 0 )
            meh = a[i];
        else
            meh += a[i];

        if ( meh > msf )
            msf = meh;
    }
    return msf;
}

/*
The algorithm:

function max sub array 2d matrix ( a[][], N )
initialize max value to minimum integer

for each column in the array, start at this column
    create temp array of size N and initialize all elements to 0
    for each col in the array, start col number = column number above
        for every row in the matrix
            temp[row] = temp[row] + array[row][col]
            y <- compute max sum of temp sub array
            if y is larger than current max
                current max is y
        end for
    end for
end for

output max value
*/

int main()
{
    int size, i, j, k, x = INT_MIN;

    int temp[MAXN];
    int a[MAXN][MAXN];

    scanf("%i", &size );

    for ( i = 0; i < size; i++ )
        for ( j = 0; j < size; j++ )
            scanf("%i", &a[i][j] );

    for ( i = 0; i < size; i++ )
    {
        memset( temp, 0, ( size * sizeof( int ) ) );

        for ( j = i; j < size; j++ )
        {
            for ( k = 0; k < size; k++ )
                temp[k] += a[k][j];

            x = max( kadanes( temp, size ) , x );
        }
    }

    printf("%i\n", x );

    return 0;
}
