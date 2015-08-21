#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 52

/* ACCEPTED */

struct card {

    char rank;
    char suit;
    struct card *next;
};


typedef struct card card;


card *table[MAX];
int last_card; /* inclusive */


void init_table( card *table[] )
{
    int i;

    for ( i = 0; i < MAX; i++ ) table[i] = NULL;
}

card *card_alloc( char x, char y )
{
    card *temp = ( card * ) malloc( sizeof( card ) );
    temp->rank = x;
    temp->suit = y;
    temp->next = NULL;
    return temp;
}

void shift_left( int pos )
{
    int i;

    for ( i = pos; i < last_card; i++ ) table[i] = table[i+1];

    table[last_card] = NULL;

    last_card--;
}

void move_card( int src, int dest )
{
    card *temp = table[src];
    card *prev = NULL;
    card *temp_two = table[dest];

    while ( temp->next != NULL )
    {
        prev = temp;
        temp = temp->next;
    }

    while ( temp_two->next != NULL ) temp_two = temp_two->next;

    temp_two->next = temp;

    if ( prev == NULL ) shift_left( src );
    else prev->next = NULL;
}

card *top_card( int src )
{
    card *temp = table[src];

    while ( temp->next != NULL ) temp = temp->next;

    return temp;
}

int equals( card *x, card *y )
{
    return ( x->rank == y->rank || x->suit == y->suit ) ? 1 : 0;
}

int parse_card_data()
{
    int i;
    char rank, suit;

    init_table( table );

    for ( i = 0; i < MAX; i++ )
    {
        rank = getchar();

        if ( rank == '#' ) return 0;

        suit = getchar();

        table[i] = card_alloc( rank, suit );

        getchar(); /* get white space or new line character */
    }

    last_card = MAX - 1;

    return 1;
}

void count()
{
    int i = 0;
    int count;

    if ( last_card == 0 ) printf("%i pile remaining:", ( last_card + 1 ) );
    else printf("%i piles remaining:", ( last_card + 1 ) );

    for ( i = 0; i <= last_card; i++ )
    {
        card *temp = table[i];
        count = 0;

        while ( temp != NULL )
        {
            temp = temp->next;
            count++;
        }

        printf(" %i", count );
    }
    printf("\n");
}

void play()
{
    int i = 1;

    while ( i <= last_card )
    {
        if ( i > 2 )
        {
            if ( equals( top_card( i ), top_card( i - 3 ) ) == 1 )
            {
                move_card( i, i - 3 );
                i = 0;
            }
        }

        if ( i > 0 )
        {
            if ( equals( top_card( i ), top_card( i - 1 ) ) == 1 )
            {
                move_card( i, i - 1 );
                i = 0;
            }
        }
        i++;
    }

    count();
}

int main()
{
    while ( parse_card_data() )
    {
        play();
    }

    return 0;
}
