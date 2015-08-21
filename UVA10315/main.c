#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXL 100
#define NCARDS 10
#define HANDSIZE 5
#define TRUE 1
#define FALSE 0
#define FAIL -1
#define WHITE 1
#define BLACK 0

int white[HANDSIZE];
int black[HANDSIZE];

int white_high[HANDSIZE];
int black_high[HANDSIZE];

int wi;
int bi;

int whr; /* hand rank */
int bhr;

int kc; /* keep comparing */

int compare( const void *a, const void *b )
{
    return *( int * ) a - *( int * ) b;
}

void init()
{
    int i;
    for ( i = 0; i < HANDSIZE; i++ ) white_high[i] = black_high[i] = 0;
    bi = wi = whr = bhr = 0;
}

int getvalue( char suit, char rank )
{
    int r = 0;
    if ( suit == 'C' )
        r = 100;
    else if ( suit == 'D' )
        r = 200;
    else if ( suit == 'H' )
        r = 300;
    else
        r = 400;

    if ( rank == 'T' )
        r += 10;
    else if ( rank == 'J' )
        r += 11;
    else if ( rank == 'Q' )
        r += 12;
    else if ( rank == 'K')
        r += 13;
    else if ( rank == 'A' )
        r += 14;
    else
        r += ( rank - '0' );
    return r;
}

int max_card( int a[] )
{
    int i;
    int max = a[0] % 100;
    for ( i = 1; i < HANDSIZE; i++ )
        if ( a[i] % 100 > max )
            max = a[i] % 100;
    return max;
}

/* 5 cards of the same suit with consecutive values. Ranked by the highest card in the hand.  */
int straight_flush( int hand[], int color )
{
    int i;
    int temp[HANDSIZE - 1];
    for ( i = 0; i < HANDSIZE - 1; i++ )
        temp[i] = hand[i+1] - hand[i];
    for ( i = 0; i < HANDSIZE - 1; i++ )
        if ( temp[i] != 1 )
            return FALSE;
    if ( color == BLACK )
    {
        black_high[bi++] = max_card( hand );
        bhr = 100;
    }
    else
    {
        white_high[wi++] = max_card( hand );
        whr = 100;
    }

    kc = FALSE;
    return TRUE;
}

int four_kind( int hand[], int color )
{
    int i;
    int temp[HANDSIZE];
    int occ[15];
    for ( i = 0; i < 15; i++ ) occ[i] = 0;
    for ( i = 0; i < HANDSIZE; i++ ) temp[i] = hand[i] % 100;
    for ( i = 0; i < HANDSIZE; i++ ) occ[ temp[i] ]++;
    for ( i = 2; i < 15; i++ ) /* the score depends on which card is the 4 of a kind */
    {
        if ( occ[i] == 4 )
        {
            if ( color == BLACK )
            {
                black_high[bi++] = i;
                bhr = 90;
            }
            else
            {
                white_high[wi++] = i;
                whr = 90;
            }
            kc = FALSE;
            return TRUE;
        }
    }
    return FALSE;
}

/* 3, 2 */
int full_house( int hand[], int color )
{
    int i;
    int temp[HANDSIZE];
    int occ[15];
    int tf, pf; /* triple found, pair found */
    int tv; /* triple value */
    tf = pf = FALSE;
    for ( i = 0; i < 15; i++ ) occ[i] = 0;
    for ( i = 0; i < HANDSIZE; i++ ) temp[i] = hand[i] % 100;
    for ( i = 0; i < HANDSIZE; i++ ) occ[ temp[i] ]++;
    for ( i = 2; i < 15; i++ )
    {
        if ( occ[i] == 3 )
        {
            tf = TRUE;
            tv = i;
        }
        else if ( occ[i] == 2 )
            pf = TRUE;
        else if ( occ[i] > 0 ) /* if there is any values except 2, 3 that are non zero */
            return FALSE;
    }

    if ( tf && pf )
    {
        if ( color == BLACK )
        {
            black_high[bi++] = tv;
            bhr = 80;
        }
        else
        {
            white_high[wi++] = tv;
            whr = 80;
        }
    }

    kc = FALSE;
    return TRUE;
}

int straight( int hand[], int color )
{
    int i;
    int temp[HANDSIZE];
    for ( i = 0; i < HANDSIZE; i++ ) temp[i] = hand[i] % 100;
    qsort( &temp, HANDSIZE, sizeof( int ), compare );
    for ( i = 0; i < HANDSIZE - 1; i++ )
        temp[i] = temp[i+1] - temp[i];
    for ( i = 0; i < HANDSIZE - 1; i++ )
        if ( temp[i] != 1 )
            return FALSE;
    if ( color == BLACK )
    {
        black_high[bi++] = max_card( hand );
        bhr = 60;
    }
    else
    {
        white_high[wi++] = max_card( hand );
        whr = 60;
    }

    kc = FALSE;
    return TRUE;
}

int three_kind( int hand[], int color )
{
    int i;
    int temp[HANDSIZE];
    int occ[15];
    for ( i = 0; i < 15; i++ ) occ[i] = 0;
    for ( i = 0; i < HANDSIZE; i++ ) temp[i] = hand[i] % 100;
    for ( i = 0; i < HANDSIZE; i++ ) occ[ temp[i] ]++;
    for ( i = 2; i < 15; i++ ) /* the score depends on which card is the 3 of a kind */
    {
        if ( occ[i] == 3 )
        {
            if ( color == BLACK )
            {
                black_high[bi++] = i;
                bhr = 50;
            }
            else
            {
                white_high[wi++] = i;
                whr = 50;
            }
            kc = FALSE;
            return TRUE;
        }
    }
    return FALSE;
}

int two_pair( int hand[], int color )
{
    int i;
    int temp[HANDSIZE];
    int occ[15];
    int pc; /* pair count */
    pc = 0;
    for ( i = 0; i < 15; i++ ) occ[i] = 0;
    for ( i = 0; i < HANDSIZE; i++ ) temp[i] = hand[i] % 100;
    for ( i = 0; i < HANDSIZE; i++ ) occ[ temp[i] ]++;
    for ( i = 14; i >= 2; i-- )
        if ( occ[i] == 2 )
            pc++;

    if ( pc != 2 )
        return FALSE;

    for ( i = 14; i >= 2; i-- )
    {
        if ( occ[i] == 2 )
        {
            if ( color == BLACK )
            {
                black_high[bi++] = i;
                bhr = 40;
            }
            else
            {
                white_high[wi++] = i;
                whr = 40;
            }
        }
    }

    /* at this point we know there is 2 pairs */
    for ( i = 2; i < 15; i++ )
    {
        if ( occ[i] == 1 ) /* place the last high card in the array */
        {
            if ( color == BLACK )
                black_high[bi++] = i;
            else
                white_high[wi++] = i;
            break;
        }
    }
    kc = TRUE;
    return TRUE;
}

int pair( int hand[], int color )
{
    int i;
    int temp[HANDSIZE];
    int occ[15];
    int pf; /* pair count */
    pf = FALSE;
    for ( i = 0; i < 15; i++ ) occ[i] = 0;
    for ( i = 0; i < HANDSIZE; i++ ) temp[i] = hand[i] % 100;
    for ( i = 0; i < HANDSIZE; i++ ) occ[ temp[i] ]++;
    for ( i = 14; i >= 2; i-- )
        if ( occ[i] == 2 )
            pf = TRUE;

    if ( !pf )
        return FALSE;

    for ( i = 2; i < 15; i++ )
    {
        if ( occ[i] == 2 )
        {
            if ( color == BLACK )
            {
                black_high[bi++] = i;
                bhr = 30;
            }
            else
            {
                white_high[wi++] = i;
                whr = 30;
            }
            break;
        }
    }

    for ( i = 14; i >= 2; i-- )
    {
        if ( occ[i] > 0 && occ[i] < 2 )
        {
            if ( color == BLACK )
                black_high[bi++] = i;
            else
                white_high[wi++] = i;
        }
    }

    kc = TRUE;
    return TRUE;
}

int high_card( int hand[], int color )
{
    int i;
    int temp[HANDSIZE];
    int occ[15];
    for ( i = 0; i < 15; i++ ) occ[i] = 0;
    for ( i = 0; i < HANDSIZE; i++ ) temp[i] = hand[i] % 100;
    for ( i = 0; i < HANDSIZE; i++ ) occ[ temp[i] ]++;

    for ( i = 14; i >= 2; i-- )
    {
        if ( occ[i] > 0 )
        {
            if ( color == BLACK )
            {
                black_high[bi++] = i;
                bhr = 20;
            }
            else
            {
                white_high[wi++] = i;
                whr = 20;
            }
        }
    }
    kc = TRUE;
    return TRUE;
}

/* 5 cards of the same suit... 100, 200, 300, 400 */
int flush( int hand[], int color )
{
    int i;
    int temp[HANDSIZE];
    int val;
    for ( i = 0; i < HANDSIZE; i++ ) temp[i] = hand[i] / 100;
    val = temp[0];
    for ( i = 1; i < HANDSIZE; i++ )
        if ( temp[i] != val )
            return FALSE;

    high_card( hand, color );

    if ( color == BLACK )
        bhr = 70;
    else
        whr = 70;

    kc = TRUE;
    return TRUE;
}

void getline( char line[] )
{
    char suit, rank;
    int i = 0;
    int nc = 0;

    while ( nc < NCARDS )
    {
        if ( !isspace( line[i] ) )
        {
            rank = line[i];
            i++;
            suit = line[i];

            if ( nc < HANDSIZE )
                black[nc++] = getvalue( suit, rank );
            else
                white[nc++%HANDSIZE] = getvalue( suit, rank );
        }

        i++;
    }

    qsort( &black, HANDSIZE, sizeof( int ), compare );
    qsort( &white, HANDSIZE, sizeof( int ), compare );
}

void score( int hand[], int color )
{
    if ( straight_flush( hand, color ) || four_kind( hand, color ) || full_house( hand, color ) ||
        flush( hand, color ) || straight( hand, color ) || three_kind( hand, color ) ||
        two_pair( hand, color ) || pair( hand, color ) )
    {
        return;
    }

    high_card( hand, color );
}

int main()
{
    int i;
    char line[MAXL];

    while ( fgets( line, MAXL, stdin ) != NULL )
    {
        getline( line );
        i = 0;
        init();
        kc = FALSE;

        score( black, BLACK );
        score( white, WHITE );

        if ( whr < bhr )
        {
            printf("Black wins.\n");
        }
        else if ( whr > bhr )
        {
            printf("White wins.\n");
        }
        else
        {
            while ( kc == TRUE && i < HANDSIZE && black_high[i] == white_high[i] )
                i++;
            if ( kc == FALSE || i == HANDSIZE )
                printf("Tie.\n");
            else if ( black_high[i] > white_high[i] )
                printf("Black wins.\n");
            else
                printf("White wins.\n");
        }
    }

    return 0;
}
