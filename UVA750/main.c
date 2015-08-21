#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED */

#define SIZE 8
#define TRUE 1
#define FALSE 0

int p[SIZE][SIZE];

int sr;
int sc;
int s;

int check_row( int row )
{
    int i;

    for ( i = 0; i < SIZE; i++ )
        if ( p[row][i] )
            return FALSE;
    return TRUE;
}

int check_col( int col )
{
    int i;

    for ( i = 0; i < SIZE; i++ )
        if ( p[i][col] )
            return FALSE;
    return TRUE;
}

int check_fdiag( int row, int col )
{
    int tr = row;
    int tc = col;

    while ( tr >= 0 && tc >= 0 )
    {
        if ( p[tr][tc]) return FALSE;
        tr--;
        tc--;
    }

    row++;
    col++;

    while ( row < SIZE && col < SIZE)
    {
        if ( p[ row ][ col ] ) return FALSE;
        row++;
        col++;
    }

    return TRUE;
}

int check_bdiag( int row, int col )
{
    int tr = row, tc = col;

    while ( tr >= 0 && tc < SIZE )
    {
        if ( p[tr][tc] ) return FALSE;
        tr--;
        tc++;
    }

    row++;
    col--;

    while ( row < SIZE && col >= 0)
    {
        if ( p[row][col]) return FALSE;
        row++;
        col--;
    }

    return TRUE;
}

int check( int x, int y )
{
    return check_col( y ) && check_row( x ) && check_fdiag( x, y ) && check_bdiag( x, y );
}

void show()
{
    s++;

    printf("%2i      ", s );

    int row, col;

    for ( col = 0; col < SIZE; col++ )
    {
        for ( row = 0; row < SIZE; row++ )
        {
            if ( p[row][col] == TRUE )
            {
                if ( col < SIZE - 1 )
                    printf("%i ", row + 1 );
                else
                    printf("%i", row + 1 );
            }
        }
    }
    printf("\n");
}

void init( int x, int y )
{
    int i, j;

    for ( i = 0; i < SIZE; i++ )
        for ( j = 0; j < SIZE; j++ )
            p[i][j] = FALSE;

    sr = x - 1;
    sc = y - 1;
    p[sr][sc] = TRUE;
    s = 0;
}

void backtrack( int col )
{
    if ( col >= SIZE )
    {
        show();
    }
    else if ( col == sc )
    {
        backtrack( col + 1 );
    }
    else
    {
        int row;

        for ( row = 0; row < SIZE; row++ )
        {
            if ( check( row, col ) )
            {
                p[row][col] = TRUE;
                backtrack( col + 1 );
            }
            p[row][col] = FALSE;
        }
    }
}

int main()
{
    int i;
    int ncases;
    int x;
    int y;

    scanf("%i", &ncases );

    for ( i = 0; i < ncases; i++ )
    {
        scanf("%i %i", &x, &y );
        init( x, y );
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        backtrack( 0 );
        if ( i < ncases - 1 )
            printf("\n");
    }

    return 0;
}
