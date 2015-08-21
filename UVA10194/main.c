#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ACCEPTED 0.016 */

#define MAXT 31
#define MAXNUMTEAMS 30
#define TNAME 101
#define SIZE 100

struct map_entry {

    char tn[MAXT];
    int index;
    struct map_entry *next;
};

struct entry {

    char tn[MAXT];
    int pe, gp, w, t, l, gs, ga;
};

typedef struct map_entry map_entry;
typedef struct entry entry;

map_entry *table[SIZE];

entry a[MAXT];

void init()
{
    int i;

    for ( i = 0; i < SIZE; i++ ) table[i] = NULL;
}

int compare( const void *ta, const void *tb )
{
    entry a = *( entry * )ta;
    entry b = *( entry * )tb;

    if ( a.pe > b.pe )
        return -1;
    else if ( a.pe < b.pe )
        return 1;
    else /* same points earned */
    {
        if ( a.w > b.w )
            return -1;
        else if ( a.w < b.w )
            return 1;
        else /* same wins */
        {
            int x = a.gs - a.ga;
            int y = b.gs - b.ga;

            if ( x > y )
                return -1;
            else if ( x < y )
                return 1;
            else /* same point difference */
            {
                if ( a.gs > b.gs )
                    return -1;
                else if ( a.gs < b.gs )
                    return 1;
                else /* same goals scored */
                {
                    if ( a.gp < b.gp )
                        return -1;
                    else if ( a.gp > b.gp )
                        return 1;
                    else /* same games played */
                        return ( strcasecmp( a.tn, b.tn ) );
                }
            }
        }
    }
}

unsigned hash( void *key )
{
	unsigned char *p = key;
	unsigned h = 0;

	while ( *p )
    {
        h ^= ( h << 5 ) + ( h >> 2 ) + *p;
        p++;
    }

	return h % SIZE;
}

void put( char key[], int value )
{
    unsigned index = hash( key );

    map_entry *n = ( map_entry * ) malloc ( sizeof ( map_entry ) );
    strcpy( n->tn, key );
    n->index = value;
    n->next = table[index];
    table[index] = n;
}

int get( char key[] )
{
    unsigned index = hash( key );
    map_entry *temp = table[index];

    while ( temp != NULL )
    {
        if ( strcmp( temp->tn, key ) == 0 )
        {
            return temp->index;
        }
        temp = temp->next;
    }
    return -1;
}

int getline( char data[] )
{
    int i = 0;
    char c;

    while ( ( c = getchar() ) != EOF && c != '\n' )
        data[i++] = c;
    data[i] = '\0';

    return i;
}

void parse_game_data( char to[], char tt[], int *so, int *st )
{
    char c;
    int i = 0;

    while ( ( c = getchar() ) != '#' )
    {
        to[i++] = c;
    }
    to[i] = '\0';

    while ( isdigit( ( c = getchar() ) ) )
    {
        *so = 10 * ( *so ) + ( c - '0' );
    }

    while ( isdigit( ( c = getchar() ) ) )
    {
        *st = 10 * ( *st ) + ( c - '0' );
    }

    i = 0;

    while ( ( c = getchar() ) != '\n' && c != EOF )
    {
        tt[i++] = c;
    }
    tt[i] = '\0';
}


int main()
{
    int i, j, ncases, nteams, ngames, so, st, io, it;

    char tourn[TNAME], team[MAXT], to[MAXT], tt[MAXT];

    scanf("%i", &ncases );
    getchar();

    for ( i = 0; i < ncases; i++ ) /* for each case */
    {
        getline( tourn ); /* read tournament name */

        scanf("%i", &nteams );
        getchar();

        for ( j = 0; j < nteams; j++ )
        {
            getline( team );
            put( team, j );
            a[j].ga = a[j].gp = a[j].gs = a[j].l = a[j].pe = a[j].t = a[j].w = 0;
            strcpy( a[j].tn, team );
        }

        scanf("%i", &ngames );
        getchar();

        for ( j = 0; j < ngames; j++ )
        {
            so = st = 0;

            parse_game_data( to, tt, &so, &st );

            io = get( to ); /* obtain position in array */
            it = get( tt ); /* obtain position in array */

            a[io].gp = a[io].gp + 1; /* games played */
            a[it].gp = a[it].gp + 1;

            a[io].gs = a[io].gs + so; /* goals scored, goals against */
            a[it].ga = a[it].ga + so;

            a[io].ga = a[io].ga + st;
            a[it].gs = a[it].gs + st;

            if ( so > st ) /* wins, losses and ties */
            {
                a[io].w = a[io].w + 1;
                a[it].l = a[it].l + 1;
                a[io].pe = a[io].pe + 3;
            }
            else if ( so < st )
            {
                a[it].w = a[it].w + 1;
                a[io].l = a[io].l + 1;
                a[it].pe = a[it].pe + 3;
            }
            else
            {
                a[io].t = a[io].t + 1;
                a[it].t = a[it].t + 1;
                a[io].pe = a[io].pe + 1;
                a[it].pe = a[it].pe + 1;
            }
        }

        qsort( &a, nteams, sizeof( entry ), compare );

        printf("%s\n", tourn );

        for ( j = 0; j < nteams; j++ )
        {
            printf("%i) %s %ip, %ig (%i-%i-%i), %igd (%i-%i)\n", ( j + 1 ), a[j].tn, a[j].pe, a[j].gp, a[j].w,
                   a[j].t, a[j].l, ( a[j].gs - a[j].ga ), a[j].gs, a[j].ga );
        }
        if ( i != ncases - 1 )
            printf("\n");
    }

    return 0;
}
