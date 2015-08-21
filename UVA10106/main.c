#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/* ACCEPTED 0.016 */

#define MAXDIGITS 500

struct bignum
{
    char digits[MAXDIGITS];
    int lastdigit;
};

typedef struct bignum bignum;

int max( int a, int b )
{
    return ( a > b ) ? a : b;
}

void zero_justify( bignum *b )
{
    if ( b->lastdigit < 1 ) return;

    while ( b->lastdigit > 0 && b->digits[b->lastdigit] == 0 )
    {
        b->lastdigit = b->lastdigit - 1;
    }
}

void show( bignum *b )
{
    int i;
    for ( i = b->lastdigit; i >= 0; i--)
    {
        printf("%c", b->digits[i] + '0' );
    }

    printf("\n");
}

void init( bignum *b )
{
    int i;
    for ( i = 0; i < MAXDIGITS; i++ ) b->digits[i] = 0;
    b->lastdigit = 0;
}

void new_bignum( char a[], bignum *b )
{
    int i;
    int n = strlen( a ) - 1;
    init( b );
    for ( i = 0; a[i] != '\0'; i++ )
        b->digits[n-i] = a[i] - '0';
    b->lastdigit = n;
}

void digit_shift( bignum *b, int d )
{
    int i = b->lastdigit;

    for ( i = b->lastdigit; i >= 0; i-- )
    {
        b->digits[i + d] = b->digits[i];
    }

    for ( i = 0; i < d; i++ )
    {
        b->digits[i] = 0;
    }

    b->lastdigit = b->lastdigit + d;
}

void add( bignum *a, bignum *b, bignum *c )
{
    int i, len, sum, carry = 0;

    init( c );

    len = max( a->lastdigit, b->lastdigit ) + 1;

    for ( i = 0; i <= len; i++ )
    {
        sum = a->digits[i] + b->digits[i] + carry;
        c->digits[i] = ( sum % 10 );
        carry = sum / 10;
    }

    c->lastdigit = len;

    zero_justify( c );
}

void mult( bignum *a, bignum *b, bignum *c )
{
    int i, j, pd, carry;
    bignum temp;
    bignum row;

    init( c );
    init( &temp );
    init( &row );

    for ( j = 0; j <= b->lastdigit; j++ )
    {
        carry = 0;

        for ( i = 0; i <= a->lastdigit; i++ )
        {
            pd = b->digits[j] * a->digits[i] + carry;
            row.digits[i] = pd % 10;
            carry = pd / 10;
            row.lastdigit = i;
        }
        if ( carry > 0 && i > 0 )
        {
            row.digits[i] = carry;
            row.lastdigit = i;
        }
        digit_shift( &row, j );
        add( &row, c, &temp );
        *c = temp;
    }
    zero_justify( c );
}

int main()
{
    char a[MAXDIGITS];
    char b[MAXDIGITS];
    bignum ba, bb, bc;

    while ( scanf("%s %s", a, b ) == 2 )
    {
        new_bignum( a, &ba );
        new_bignum( b, &bb );

        mult( &ba, &bb, &bc );

        show( &bc );
    }

    return 0;
}
