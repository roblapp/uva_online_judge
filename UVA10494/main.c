#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**< structures */
struct node {

    char x;
    char y;
    struct node *next;
    struct node *prev;
};

struct list {

    struct node *HEAD;
    struct node *TAIL;
    int size;
};

/**< typedef's */
typedef struct node node;

typedef struct list list;

/**< global variables */
list *ONE;

/**< prototypes */
node *nalloc();
list *list_alloc();
void show_list( list *a );
list *add( list *a, list *b );
void show_number( list *num );


/**< general functions */
int max( int a, int b )
{
    return a > b ? a : b;
}


/**< list functions */
void remove_first( list *a )
{
    if ( a->HEAD == NULL )
    {
        printf("error. empty list\n");
        return;
    }
    else if ( a->HEAD->next == NULL ) /*one digit number*/
    {
       node *temp = a->HEAD;
       free( temp );
       a->HEAD = a->TAIL = NULL;
    }
    else
    {
        node *temp = a->HEAD;
        a->HEAD = a->HEAD->next;
        a->HEAD->prev = NULL;
        free( temp );
    }

    a->size--;
}

void add_first( list *a, char digit )
{
    if ( a->HEAD == NULL )
    {
        a->HEAD = a->TAIL = nalloc();
        a->HEAD->x = a->TAIL->x = digit;
        a->HEAD->y = a->TAIL->y = ( 9 - ( digit - '0' ) ) + '0';
    }
    else
    {
        node *temp = nalloc();
        temp->x = digit;
        temp->y = ( 9 - ( digit - '0' ) ) + '0';
        temp->next = a->HEAD;
        a->HEAD->prev = temp;
        a->HEAD = temp;
    }

    a->size++;
}

void add_last( list *a, char digit )
{
    if ( a->HEAD == NULL )
    {
        a->HEAD = a->TAIL = nalloc();
        a->HEAD->x = a->TAIL->x = digit;
        a->HEAD->y = a->TAIL->y = ( 9 - ( digit - '0' ) ) + '0';
    }
    else
    {
        node *temp = nalloc();
        temp->x = digit;
        temp->y = ( 9 - ( digit - '0' ) ) + '0';
        temp->prev = a->TAIL;
        a->TAIL->next = temp;
        a->TAIL = temp;
    }

    a->size++;
}


/**< memory allocating functions */
node *nalloc()
{
    node *temp = ( node * ) malloc( sizeof( node ) );
    temp->next = temp->prev = NULL;
    return temp;
}

list *list_alloc()
{
    list *temp = ( list * ) malloc( sizeof( list ) );
    temp->size = 0;
    temp->HEAD = temp->TAIL = NULL; /* set the HEAD and TAIL pointers to NULL */
    return temp;
}




/**< number functions */

/** \brief - compares two numbers lexicographically.
 *
 * \param - first number
 * \param - second number
 * \return - returns -1 if a < b, 0 if a = b, and 1 if a > b
 *
 */

int compare( list *a, list *b )
{
    if ( a->size > b->size )
    {
        return 1;
    }
    else if ( a->size < b->size )
    {
        return -1;
    }
    else /* the numbers contain the same amount of digits */
    {
        node *a_temp = a->HEAD;
        node *b_temp = b->HEAD;

        while ( a_temp != NULL && a_temp->x == b_temp->x )
        {
            a_temp = a_temp->next;
            b_temp = b_temp->next;
        }

        if ( a_temp == NULL ) /* reached the end of both numbers, so they must be equal */
        {
            return 0;
        }
        else if ( a_temp->x > b_temp->x )
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}


list *add( list *a, list *b )
{
    if ( a->TAIL == NULL || b->TAIL == NULL )
    {
        printf("error. null tail\n");
        exit( -1 );
    }

    list *result = list_alloc();
    node *a_temp = a->TAIL;
    node *b_temp = b->TAIL;
    int k = max( a->size, b->size );
    int sum, carry = 0, num_one, num_two;

    while ( k >= 0 )
    {
        num_one = ( a_temp == NULL ) ? 0 : ( a_temp->x - '0' );
        num_two = ( b_temp == NULL ) ? 0 : ( b_temp->x - '0' );
        sum = num_one + num_two + carry;
        if ( k != 0 || sum != 0)
            add_first( result, ( sum % 10 ) + '0' );
        carry = sum / 10;
        if ( a_temp != NULL )
            a_temp = a_temp->prev;
        if ( b_temp != NULL )
            b_temp = b_temp->prev;
        k--;
    }

    return result;
}


list *subtract( list *a, list *b )
{
    if ( a->TAIL == NULL || b->TAIL == NULL )
    {
        printf("error. null tail\n");
        exit( -1 );
    }

    int comp = compare( a, b );

    list *result = list_alloc();

    if ( comp == 0 )
    {
        add_last( result, '0' );
        return result;
    }
    else if ( comp < 0 ) /* a < b */
    {
        result = subtract( b, a );
        add_first( result, '-' );
        return result;
    }

    node *a_temp = a->TAIL;
    node *b_temp = b->TAIL;
    int k = max( a->size, b->size );
    int sum, carry = 0, num_one, num_two;

    while ( k > 0 )
    {
        num_one = ( a_temp == NULL ) ? 0 : ( a_temp->x - '0' );
        num_two = ( b_temp == NULL ) ? 9 : ( b_temp->y - '0' );
        sum = num_one + num_two + carry;
        if ( k != 0 || sum != 0)
            add_first( result, ( sum % 10 ) + '0' );
        carry = sum / 10;
        if ( a_temp != NULL )
            a_temp = a_temp->prev;
        if ( b_temp != NULL )
            b_temp = b_temp->prev;
        k--;
    }

    return add( result, ONE );
}






void show_comp( list *num )
{
    node *temp = num->HEAD;
    int i = 0;
    char n[ num->size + 1 ];

    while ( temp != NULL )
    {
        n[i++] = temp->y;
        temp = temp->next;
    }

    n[i] = '\0';

    printf("%s\n", n );

}

void show_number( list *num )
{
    node *temp = num->HEAD;
    int i = 0;
    char n[ num->size + 1 ];

    /*
    while ( temp != NULL && temp->x == '0' )
    {
        temp = temp->next;
    }
    */

    while ( temp != NULL )
    {
        n[i++] = temp->x;
        temp = temp->next;
    }

    n[i] = '\0';

    printf("%s\n", n );
}

int main()
{
    list *a = list_alloc();
    list *b = list_alloc();
    list *result;

    ONE = list_alloc();
    add_last( ONE, '1' );

    char c;
    int index = 0;

    while ( ( c = getchar() ) != EOF && c != 'q' )
    {
        if ( c == '\n' )
        {
            index++;
        }
        else if ( isdigit( c ) )
        {
            if ( index == 0 )
                add_last( a, c );
            else
                add_last( b, c );
        }
    }

    result = subtract( a, b );

    show_number( result );

    free( ONE );
    free( a );
    free( b );
    free( result );

    return 0;
}

void show_list( list *a )
{
    node *temp = a->HEAD;

    char s[a->size + 1];
    int i = 0;

    printf("{ ");

    while ( temp != NULL )
    {
        s[i++] = temp->x;
        temp = temp->next;
    }

    s[i] = '\0';

    printf("%s", s );
    printf(" }\n");
}
