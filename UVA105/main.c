#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.032s */

#define MAXN 10000
#define TRUE 1
#define FALSE 0

int max(int a, int b) { return (a > b) ? a : b; }

int main() {

    int i, li, hi, ri, mri = 0;
    int *d = (int *) calloc( MAXN + 1, sizeof( int ) );
    while ( scanf("%i %i %i", &li, &hi, &ri ) == 3 ) {
        for ( i = li; i < ri; i++ ) {
            d[i] = max(hi, d[i]);
        }
        if ( ri > mri ) mri = ri;
    }
    i = 1;
    int cv = 0, x = TRUE;
    LOOP: while ( x ) {
        while ( d[i] == cv ) {
            i++;
            if ( i > mri ) {
                x = FALSE;
                goto LOOP;
            }
        }
        printf("%i ", i );
        if ( i == mri )
            printf("%i\n", d[i] );
        else
            printf("%i ", d[i] );
        cv = d[i];
    }

    return 0;
}
