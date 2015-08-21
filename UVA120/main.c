#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 30

/* ACCEPTED*/

int *a;

void show_array();

int get_max( int s )
{
    int max = *( a + s );
    int i = s;

    while ( --s >= 0 )
    {
        if ( *( a + s ) > max )
        {
            max = *( a + s );
            i = s;
        }
    }

    return i;
}

void reverse( int x, int y )
{
    while ( x < y )
    {
        int temp = a[x];
        a[x] = a[y];
        a[y] = temp;
        x++;
        y--;
    }
}

/* pos inclusive */
void solve( int pos, const int len )
{
    show_array( len );

    int max;

    while ( pos > 0 )
    {
        max = get_max( pos );

        if ( max != pos )
        {
            if ( max != 0 )
            {
                reverse( 0, max );
                printf("%i ", ( len - max ) );
            }

            reverse( 0, pos );
            printf("%i ", ( len - pos ) );
        }

        pos--;
    }

    printf("0\n" );
}

void show_array( const int len )
{
    int i;

    for ( i = 0; i < len; i++ )
    {
        ( i != len - 1 ) ? printf("%i ", a[i] ) : printf("%i\n", a[i] );
    }
}

int main()
{
    a = ( int * ) calloc( MAX, sizeof( int ) );

    char c;
    int num = 0;
    int pos = 0;

    while ( ( c = getchar() ) != EOF && c != 'q' )
    {
        if ( isspace( c ) )
        {
            if ( c == '\n' )
            {
                *( a + pos ) = num;
                solve( pos, pos + 1 );
                memset( a, 0, MAX );
                num = pos = 0;
            }
            else
            {
                *( a + pos ) = num;
                num = 0;
                pos++;
            }
        }
        else if ( isdigit( c ) )
        {
            num = 10 * num + ( c - '0' );
        }
   }

    free( a );

    return 0;
}
