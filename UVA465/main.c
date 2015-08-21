#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.009 */

#define MAXDIGITS 500
#define MAXL 1000
#define TRUE 1
#define FALSE 0

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

void show( bignum *b )
{
    int i;
    for ( i = b->lastdigit; i >= 0; i--)
    {
        printf("%c", b->digits[i] + '0' );
    }

    printf("\n");
}

int compare( bignum *a, bignum *b )
{
    if ( a->lastdigit < b->lastdigit )
    {
        return -1;
    }
    else if (  a->lastdigit > b->lastdigit )
    {
        return 1;
    }
    else
    {
        int i = a->lastdigit;
        while ( i >= 0 && a->digits[i] == b->digits[i] )
            i--;

        if ( i < 0 ) return 0;
        else return a->digits[i] - b->digits[i];
    }
}

void zero_justify( bignum *b )
{
    if ( b->lastdigit < 1 ) return;

    while ( b->lastdigit > 0 && b->digits[b->lastdigit] == 0 )
    {
        b->lastdigit = b->lastdigit - 1;
    }
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
    zero_justify( b );
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
    char op, line[MAXL], a[MAXDIGITS], b[MAXDIGITS], mi[] = "2147483647";
    bignum ba, bb, bc, MAXINT;
    int i, j;

    new_bignum( mi, &MAXINT );

    while ( fgets( line, MAXL, stdin ) != NULL )
	{
	    printf("%s", line );

	    op = i = j = 0;

	    while ( !isdigit( line[i] ) )
            i++;

        while ( isdigit( line[i] ) )
        {
            a[j++] = line[i++];
        }
	    a[j] = '\0';
	    while ( line[i] != '+' && line[i] != '*' )
            i++;
        op = line[i++];

        while ( !isdigit( line[i] ) )
            i++;
        j = 0;
        while ( isdigit( line[i] ) )
        {
            b[j++] = line[i++];
        }
        b[j] = '\0';

        new_bignum( a, &ba );
        new_bignum( b, &bb );

        if ( compare( &ba, &MAXINT ) > 0 )
        {
            printf("first number too big\n");
        }

        if ( compare( &bb, &MAXINT ) > 0 )
        {
            printf("second number too big\n");
        }

        init( &bc );

        if ( op == '*' )
        {
            mult( &ba, &bb, &bc );

            if ( compare( &bc, &MAXINT ) > 0 )
            {
                printf("result too big\n");
            }
        }
        else
        {
            add( &ba, &bb, &bc );

            if ( compare( &bc, &MAXINT ) > 0 )
            {
                printf("result too big\n");
            }
        }
	}

    return 0;
}
