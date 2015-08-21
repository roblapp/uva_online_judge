#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char input[ MAX + 1 ];
int input_ptr = 0; /*length of input string*/

char result[ 2*MAX + 1 ];
int sum_first_digit = 2*MAX;

int max( int a, int b )
{
    return ( a < b ) ? b : a;
}

void init()
{
    int i;

    for ( i = 0; i <= 2*MAX; i++ )
    {
        result[i] = '0';
    }

    result[i] = '\0';
}

void display()
{
    char *temp = result;

    while ( *temp == '0' )
    {
        temp++;
    }

    printf( "%s\n", temp );
}

void add()
{
    int sum_index = 2*MAX;

    int i = input_ptr - 1; /*number of times we iterate through input*/
    int j = 2*MAX - sum_first_digit - 1; /*number of times we iterate through input*/

    int k = max( input_ptr, 2*MAX - sum_first_digit ) + 1;

    int sum = 0, carry = 0;
    int digit_one, digit_two;

    while ( k >= 0 )
    {
        digit_one = ( i >= 0 ) ? input[i] - '0' : 0;

        digit_two = ( j >= 0 ) ? result[ sum_index ] - '0' : 0;

        sum = digit_one + digit_two + carry;

        carry = sum / 10;

        result[ sum_index ] = ( sum % 10 ) + '0';

        k--; i--; j--; sum_index--;
    }

    sum_first_digit = sum_index + 1;
}

int main()
{
    char c;

    init();

    while ( ( c = getchar() ) != EOF )
    {
        if ( input_ptr == 0 && c == '0' )
        {
            display();
            break;
        }

        if ( c == '\n' )
        {
            input[input_ptr] = '\0';
            add();
            input_ptr = 0;
        }
        else if ( isdigit( c ) )
        {
            input[ input_ptr++ ] = c;
        }
    }

    return 0;
}
