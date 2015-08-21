#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED */

#define MAX 50

void swap( char *str, int a, int b )
{
    char temp = *( str + a );
    *( str + a ) = *( str + b );
    *( str + b ) = temp;
}

void permute( char *str )
{
    int n, j, k, r, s;

    n = strlen( str );
    j = n - 1;

    while ( j >= 0 && str[j] >= str[j+1] )
        j--;

    if ( j == - 1)
    {
        printf("No Successor\n");
        return;
    }

    k = n - 1;

    while ( k >= 0 && str[j] >= str[k] )
        k--;

    swap( str, j, k );

    r = n - 1;
    s = j + 1;

    while ( r > s )
    {
        swap( str, r, s );
        r--;
        s++;
    }

    printf("%s\n", str );
}

int main()
{
    char *str = ( char * ) malloc( MAX + 1 );

    while ( scanf("%s", str ) != EOF && strcmp( str, "#" ) != 0 )
        permute( str );

    free( str );

    return 0;
}
