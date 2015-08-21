#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED 0.012s */

#define MAXC 50
#define MAXL 100
#define TRUE 1
#define FALSE 0

typedef int bool;

bool grid[MAXC + 1][MAXC + 1];
int x, y, vx, vy, maxx, maxy;
char cd;

void set_dir( char d );

void init() {
    int i, j;
    for ( i = 0; i <= MAXC; i++ ) {
        for ( j = 0; j <= MAXC; j++ ) {
            grid[i][j] = FALSE;
        }
    }
}

bool decode_execute_instruction( char inst ) {
    bool cont_next = TRUE;
    if ( inst == 'F' ) {
        if ( cd == 'N' ) {
            if ( y + 1 > maxy ) {
                if ( !grid[x][y] ) {
                    cont_next = FALSE;
                }
            } else
                y++;
        } else if ( cd == 'S' ) {
            if ( y - 1 < 0 ) {
                if ( !grid[x][y] ) {
                    cont_next = FALSE;
                }
            } else
                y--;
        } else if ( cd == 'E' ) {
            if ( x + 1 > maxx ) {
                if ( !grid[x][y] ) {
                    cont_next = FALSE;
                }
            } else
                x++;
        } else if ( cd == 'W' ) {
            if ( x - 1 < 0 ) {
                if ( !grid[x][y] ) {
                    cont_next = FALSE;
                }
            } else
                x--;
        }
    } else if ( inst == 'L' ) {
        if ( cd == 'N' ) {
            set_dir( 'W' );
        } else if ( cd == 'S' ) {
            set_dir( 'E' );
        } else if ( cd == 'E' ) {
            set_dir( 'N' );
        } else if ( cd == 'W' ) {
            set_dir( 'S' );
        }
    } else if ( 'R' ) {
        if ( cd == 'N' ) {
            set_dir( 'E' );
        } else if ( cd == 'S' ) {
            set_dir( 'W' );
        } else if ( cd == 'E' ) {
            set_dir( 'S' );
        } else if ( cd == 'W' ) {
            set_dir( 'N' );
        }
    }
    if ( !cont_next ) grid[x][y] = TRUE;
    return cont_next;
}

void set_dir( char d ) { cd = d; }

int main() {
    int i, len;
    char idir, inst[MAXL + 1];
    scanf("%i %i", &maxx, &maxy );
    while ( scanf("%i %i %c", &x, &y, &idir ) == 3 ) {
        scanf("%s", inst );
        len = strlen(inst);
        set_dir( idir );
        for ( i = 0; i < len && decode_execute_instruction( inst[i] ); i++ );
        if ( i != len ) printf("%i %i %c LOST\n", x, y, cd );
        else printf("%i %i %c\n", x, y, cd );
    }
    return 0;
}
