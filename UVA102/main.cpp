#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

/* ACCEPTED 0.088 */

#define NCOLORS 3
#define NBINS 3

using namespace std;

int data[NBINS][NCOLORS];
int temp[NBINS];
bool used[NBINS];
int min_moves;
char soln[NBINS + 1];

void process_solution( int nmoves ) {
    if ( nmoves > min_moves ) return;
    char l[] = "BGC";
    char t[NBINS + 1];
    for ( int i = 0; i < NBINS; i++ ) {
        t[i] = l[ temp[i] ];
    }
    t[NBINS] = 0;
    if ( nmoves == min_moves ) {
        if ( strcmp( soln, t ) > 0 ) {
            strcpy( soln, t );
        }
    } else {
        min_moves = nmoves;
        strcpy( soln, t );
    }
}

void construct_candidates( int c[], int *ncandidates ) {
    *ncandidates = 0;
    for ( int i = 0; i < NBINS; i++ ) {
        if ( !used[i] ) {
            c[*ncandidates] = i;
            *ncandidates = *ncandidates + 1;
        }
    }
}

void solve( int color, int nmoves ) {
    if ( color >= NCOLORS ) {
        process_solution( nmoves );
    }

    int c[NBINS], ncandidates, moves;
    construct_candidates( c, &ncandidates );
    for ( int i = 0; i < ncandidates; i++ ) { /* 0 1 2... */
        moves = 0;
        for ( int j = 0; j < NBINS; j++ ) { /* */
            if ( c[i] != j ) {
                moves += data[j][color];
            }
        }
        used[c[i]] = true;
        temp[c[i]] = color;
        solve( color + 1, nmoves + moves );
        used[c[i]] = false;
        temp[c[i]] = -1;
    }
}

int main()
{
    bool x = true;
    LOOP: while ( x ) {
        for ( int i = 0; i < NBINS; i++ ) {
            for ( int j = 0; j < NCOLORS; j++ ) {
                if ( scanf( "%i", &data[i][j] ) == EOF ) {
                    x = false;
                    goto LOOP;
                }
            }
        }
        memset( used, false, sizeof( used ) );
        min_moves = INT_MAX;
        solve( 0, 0 );
        printf("%s %i\n", soln, min_moves );
    }
    return 0;
}
