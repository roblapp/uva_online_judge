#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.032 */

#define MAXN 252
#define MAXL 100

char a[MAXN][MAXN];
char name[MAXL];
int m, n; /* col, row */

int max( int a, int b )
{
    return ( a > b ) ? a : b;
}

int min( int a, int b )
{
    return ( a < b ) ? a : b;
}

void init()
{
    int i, j;
    for ( i = 0; i < MAXN; i++ )
        for ( j = 0; j < MAXN; j++ )
            a[i][j] = 'O';
}

void show()
{
    int i, j;
    printf("%s\n", name );
    for ( i = 1; i <= n; i++ )
    {
        for ( j = 1; j <= m; j++ )
        {
            putchar( a[i][j] );
        }
        putchar('\n');
    }
}

void v( int sr, int er, int col, char color )
{
    if ( sr < 1 || sr > n || er < 1 || er > m || col < 1 || col > m )
        return;
    int i;
    for ( i = sr; i <= er; i++ )
        a[i][col] = color;
}

void h( int row, int sc, int ec, char color )
{
    if ( sc < 1 || sc > m || ec < 1 || ec > m || row < 1 || row > n )
        return;
    int i;
    for ( i = sc; i <= ec; i++ )
        a[row][i] = color;
}

void k( int sr, int er, int sc, int ec, char color )
{
    if ( sr < 1 || sr > n || sc < 1 || sc > m || er < 1 || ec > m || er < 1 || er > n )
        return;
    int i, j;
    for ( i = sr; i <= er; i++ )
        for ( j = sc; j <= ec; j++ )
            a[i][j] = color;
}

void f( int row, int col, char oc, char color )
{
    if ( row < 1 || row > n || col < 1 || col > m || a[row][col] != oc )
        return;

    a[row][col] = color;
    f( row - 1, col, oc, color );
    f( row, col - 1, oc, color );
    f( row, col + 1, oc, color );
    f( row + 1, col, oc, color );
}

int main()
{
    char c;
    int x, y, z, w;

    while ( ( c = getchar() ) != 'X' )
    {
        if ( c == 'I' )
        {
            scanf("%i %i", &m, &n );
            while ( getchar() != '\n' )
                ;
            init();
        }
        else if ( c == 'C' )
        {
            while ( getchar() != '\n' )
                ;
            init();
        }
        else if ( c == 'L' )
        {
            scanf("%i %i", &x, &y );
            getchar();
            c = getchar();
            while ( getchar() != '\n' )
                ;
            a[y][x] = c;
        }
        else if ( c == 'V' )
        {
            scanf("%i %i %i", &x, &y, &z );
            while ( isspace( ( c = getchar() ) ) )
                ;
            while ( getchar() != '\n' )
                ;
            v( min( y, z), max( y, z ), x, c );
        }
        else if ( c == 'H' )
        {
            scanf("%i %i %i", &x, &y, &z );
            while ( isspace( ( c = getchar() ) ) )
                ;
            while ( getchar() != '\n' )
                ;
            h( z, min( x, y ), max( x, y ), c );
        }
        else if ( c == 'K' )
        {
            scanf("%i %i %i %i", &x, &y, &z, &w );
            while ( isspace( ( c = getchar() ) ) )
                ;
            while ( getchar() != '\n' )
                ;
            k( min( y, w ), max( y, w ), min( x, z ), max( x, z ), c );
        }
        else if ( c == 'F' )
        {
            scanf("%i %i", &x, &y );
            getchar();
            c = getchar();
            while ( getchar() != '\n' )
                ;
            if ( a[y][x] != c )
                f( y, x, a[y][x], c );
        }
        else if ( c == 'S' )
        {
            x = 0;
            getchar();
            while ( ( c = getchar() ) != '\n' )
            {
                name[x++] = c;
            }
            name[x] = '\0';
            show();
        }
        else
        {
            while ( ( c = getchar() ) != '\n' )
                ;
        }
    }

    return 0;
}
