#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.355*/

#define MAXN 100001

struct entry {

    int num;
    int occ;
    struct entry *next;
};

typedef struct entry entry;

entry *table[MAXN];
int data[MAXN];
int push_pos;


int compare( const void *a, const void *b )
{
    return *( int * ) a - *( int * ) b;
}

void init()
{
    int i;

    for ( i = 0; i < MAXN; i++ ) table[i] = NULL;
}

unsigned hash( int x )
{
	unsigned h = x % 10;

	while ( x > 0 )
    {
        h ^= ( h << 5 ) + ( h >> 2 ) + ( x % 10 );
        x /= 10;
    }

	return h % MAXN;
}

void insert( int number )
{
    unsigned index = hash( number );
    entry *temp = table[index];

    while ( temp != NULL )
    {
        if ( temp->num == number ) /* duplicate */
        {
            temp->occ = temp->occ + 1; /* increment occurrences */
            return;
        }
        temp = temp->next;
    }

    entry *n = ( entry * ) malloc ( sizeof ( entry ) );
    n->num = number;
    n->occ = 1;
    n->next = table[index];
    table[index] = n;
    data[push_pos++] = number;
}

int search( int number )
{
    unsigned index = hash( number );
    entry *temp = table[index];

    while ( temp != NULL )
    {
        if ( temp->num == number ) /* duplicate */
        {
            return temp->occ;
        }
        temp = temp->next;
    }
    return 0;
}

int get_number( char c )
{
    if ( isdigit( c ) )
        return c - '0';
    if ( c == 'A' || c == 'B' || c == 'C' )
        return 2;
    else if ( c == 'D' || c == 'E' || c == 'F' )
        return 3;
    else if ( c == 'G' || c == 'H' || c == 'I' )
        return 4;
    else if ( c == 'J' || c == 'K' || c == 'L' )
        return 5;
    else if ( c == 'M' || c == 'N' || c == 'O' )
        return 6;
    else if ( c == 'P' || c == 'R' || c == 'S' )
        return 7;
    else if ( c == 'T' || c == 'U' || c == 'V' )
        return 8;
    else if ( c == 'W' || c == 'X' || c == 'Y' )
        return 9;
    else
        return -1;
}

void getline()
{
    char c;
    int x = 0;

    while ( ( c = getchar() ) != EOF && c != '\n' )
        if ( isalnum( c ) )
            x = 10 * x + get_number( c );
    insert( x );
}

int main()
{
    int i, j, ncases, nnums, c, fnd;

    scanf("%i", &ncases );

    for ( i = 0; i < ncases; i++ )
    {
        init();

        push_pos = 0;

        scanf("%i", &nnums );

        getchar();

        for ( j = 0; j < nnums; j++ )
            getline();

        qsort( &data, push_pos, sizeof( int ), compare );

        fnd = 0;

        for ( j = 0; j < push_pos; j++ )
        {
            if ( ( c = search( data[j] ) ) > 1 )
            {
                printf("%03i-%04i %i\n", ( data[j] / 10000 ), ( data[j] % 10000 ), c );
                fnd = 1;
            }
        }
        if ( fnd == 0 )
            printf("No duplicates.\n");
        if ( i != ncases - 1 )
            printf("\n");
    }

    return 0;
}
