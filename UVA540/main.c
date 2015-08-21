#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXTEAMS 1001
#define MAXELEMENT 1000000
#define MAXLINE 50

/* ACCEPTED */

/**< structures */
struct node {

    int element;
    struct node *next;
};

struct list {

    struct node *head;
    struct node *tail;
};

/**< type definitions */
typedef struct node node;
typedef struct list list;

/**< global variables */
int team[MAXELEMENT];
int q[MAXTEAMS];
int in_q[MAXTEAMS];
int eq;
int dq;
list table[MAXTEAMS];

node *nalloc( int element )
{
    node *temp = ( node * ) malloc ( sizeof ( node ) );
    temp->element = element;
    temp->next = NULL;
    return temp;
}

void init()
{
    int i;

    for ( i = 0; i < MAXELEMENT; i++ ) team[i] = -1;

    for ( i = 0; i < MAXTEAMS; i++ )
    {
        q[i] = -1;
        in_q[i] = 0;
        table[i].head = table[i].tail = NULL;
    }

    eq = dq = 0;
}

void insert( int element, int team )
{
    node *temp = nalloc( element );

    if ( table[team].head == NULL )
        table[team].head = temp;
    else
        table[team].tail->next = temp;

    table[team].tail = temp;
}

void enqueue( int element )
{
    int team_num = team[element]; /* get the team number of the element */

    insert( element, team_num ); /* insert the element into the table in position corresponding to team number */

    if ( !in_q[team_num] ) /* if team is not in queue */
    {
        q[eq] = team_num; /* put team number in the q */
        eq = ( 1 + eq ) % MAXTEAMS; /* increment the enqueue index */
        in_q[team_num] = 1;
    }
}

void dequeue()
{
    int team_num = q[dq];

    node *temp = table[team_num].head;

    if ( temp == NULL )
    {
        printf("dequeue error.\n");
        exit( -1 );
    }

    printf("%i\n", temp->element );

    table[team_num].head = temp->next; /* shift the list */

    if ( table[team_num].head == NULL )
    {
        table[team_num].tail = NULL;
        in_q[team_num] = 0; /* team was fully removed */
        q[dq] = -1;
        dq = ( dq + 1 ) % MAXTEAMS;

        if ( q[dq] == -1 ) /* queue fully emptied */
            eq = dq = 0;
    }

    free( temp );
}

int main()
{
    int ncases;
    int nelements;
    int i;
    int j;
    int elem;
    int n = 0;
    char line[MAXLINE];
    int item;

    while ( scanf("%i", &ncases ) != EOF && ncases != 0 )
    {
        init();

        for ( i = 0; i < ncases; i++ )
        {
            scanf("%i", &nelements );

            for ( j = 0; j < nelements; j++ )
            {
                scanf("%i", &elem );
                team[elem] = ( i + 1 );
            }
        }

        ++n;

        printf("Scenario #%i\n", n );

        while ( scanf("%s", line ) != EOF && strcmp( line, "STOP" ) != 0 )
        {
            if ( strcmp( line, "ENQUEUE" ) == 0 )
            {
                scanf("%i", &item );
                enqueue( item );
            }
            else
            {
                dequeue();
            }
        }

        printf("\n");
    }

    return 0;
}
