#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.039 */

#define MAXR 32
#define MAXC 82

char a[MAXR][MAXC];
char sep[MAXC];
int sx, sy, nlines;

void show()
{
    int i, j;
    for ( i = 1; i < nlines; i++ )
    {
        for ( j = 1; a[i][j] != '\0'; j++ )
            putchar( a[i][j] );
        putchar('\n');
    }
    printf("%s\n", sep );
}

int getline( int ln )
{
    char c;
    int x = 1;
    int y = 0;

    while ( isspace( ( c = getchar() ) ) )
        ;
    while ( c != '\n' && c != '_' )
    {
        if ( c == '*' )
        {
            sx = ln;
            sy = x;
        }
        a[ln][x++] = c;
        c = getchar();
    }
    if ( c == '_' )
    {
        sep[y++] = '_';
        while ( ( c = getchar() ) != '\n' && c != EOF ) /* drain the line */
            sep[y++] = '_';
        sep[y] = '\0';
        return 0;
    }
    a[ln][x] = '\0';
    return 1;
}

void fill( int i, int j )
{
    if ( a[i][j] != ' ' && a[i][j] != '*' )
        return;
    a[i][j] = '#';
    fill( i - 1, j );
    fill( i + 1, j );
    fill( i, j - 1 );
    fill( i, j + 1 );
}

int main()
{
    int i, j, nc;

    for ( i = 0; i < MAXR; i++ )
        for ( j = 0; j < MAXC; j++ )
            a[i][j] = '.';
    for ( i = 0; i < MAXC; i++ )
        sep[i] = '\0';

    scanf("%i", &nc );

    for ( i = 0; i < nc; i++ )
    {
        nlines = 1;
        while ( getline( nlines ) > 0 )
            nlines++;
        fill( sx, sy );
        show();
    }

    return 0;
}
