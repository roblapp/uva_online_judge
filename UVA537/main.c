#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.009 */

#define MAX 100
#define MILLI 0.001
#define KILO 1000
#define MEGA 1000000


double *pui;

int parse( char *s )
{
    /*input will have the form*/
    /*scan until we reach W, V, or A*/
    double value, power;
    int i = 0, sign;

    sign = ( *s == '-' ) ? -1 : 1;

    if ( *s == '-' || *s == '+' )
        i++;

    for ( value = 0.0; isdigit( *( s + i ) ); i++ )
        value = 10.0 * value + ( *( s + i ) - '0' );


    if ( *( s + i ) == '.' )
        i++;

    for ( power = 1.0; isdigit( *( s + i ) ); i++ )
    {
         value = 10.0 * value + ( *( s + i ) - '0' );
         power *= 10.0;
    }

    value = sign * value / power;

    /*now we are left with kW and or W*/
    if ( *( s + i ) == 'm' )
    {
        value *= MILLI;
        i++;
    }
    else if ( *( s + i ) == 'k' )
    {
        value *= KILO;
        i++;
    }
    else if ( *( s + i ) == 'M' )
    {
        value *= MEGA;
        i++;
    }

    /*now we are left with W, V, or A*/
    if ( *( s + i ) == 'W' ) /*P*/
    {
        *( pui ) = value;
        return 0;
    }
    else if ( *( s + i ) == 'V' )/*U*/
    {
        *( pui + 1 ) = value;
        return 1;
    }
    else /*I*/
    {
        *( pui + 2 ) = value;
        return 2;
    }
}

void clear_array()
{
    int i;

    for ( i = 0; i < 3; i++ )
    {
        *( pui + i ) = 0.0;
    }
}

int main()
{
    int i, x, j, k;
    char type, suffix;
    char *s = ( char * ) malloc( MAX );
    double result;

    pui = ( double * ) malloc( 3*sizeof( double ) );

    scanf("%i\n", &x );

    /*
    P = U*I
    I = P/U
    U = P/I
    */
    for ( i = 1; i <= x; i++ )
    {
        fgets( s, MAX, stdin );

        clear_array();

        char *a = strchr( s, '=' ); /*find first =*/

        char *b = strrchr( s, '=' ); /*find last =*/

        j = parse( ( a + 1 ) );

        k = parse( ( b + 1 ) );

        if ( j != 0 && k != 0 ) /*solve for P*/
        {
            result = *( pui + 1 ) * ( *( pui + 2 ) );
            type = 'P';
            suffix = 'W';
        }
        else if ( j != 1 && k != 1 ) /*solve for U*/
        {
            result = *( pui ) / ( *( pui + 2 ) );
            type = 'U';
            suffix = 'V';
        }
        else /*solve for I*/
        {
            result = *( pui ) / ( *( pui + 1 ) );
            type = 'I';
            suffix = 'A';
        }

        printf("Problem #%i\n%c=%.2lf%c\n\n", i, type, result, suffix );
    }

    free( s );

    free( pui );

    return 0;
}
