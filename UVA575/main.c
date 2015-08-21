#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 1000

/* ACCEPTED */

int main()
{
    char buff[MAX + 1];
    int i;
    int sum;
    int len;
    int exp;

    while ( scanf("%s", buff ) != EOF && strcmp( buff, "0" ) != 0 )
    {
        i = sum = 0;
        len = strlen( buff );
        exp = 1;

        for ( i = len - 1; i >= 0; i-- )
            sum += ( buff[i] - '0' ) * ( pow( 2, exp++ ) - 1 );

        printf("%i\n", sum );
    }

    return 0;
}
