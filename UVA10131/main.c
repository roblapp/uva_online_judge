#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ACCEPTED 0.009 */

#define MAXE 1000

struct data {
    int x, weight, iq;
};

typedef struct data data;

/* sort by decreasing iq and find the longest increasing sequence
by using weight as the data */
data dp[MAXE + 1];
int nelements = 0;

int compare( const void *a, const void *b ) {
    data da = *(data *) a;
    data db = *(data *) b;
    /* if they have the same IQ and different weight, then sort by decreasing weight */
    if ( da.iq == db.iq && da.weight != db.weight ) {
        return db.weight - da.weight;
    } else
        return db.iq - da.iq; /* otherwise sort by decreasing IQ */
}

void reconstruct_path( int max, int j, int lis[], data dp[] ) {
    if ( max == 0 ) return;
    if ( lis[j] == max ) {
        reconstruct_path( max - 1, j - 1, lis, dp );
        printf("%i\n", dp[j].x + 1 );
    } else {
        reconstruct_path( max, j - 1, lis, dp );
    }
}

int main() {
    int i = 0, j, a, b, temp, max = 1;
    while ( scanf("%i %i", &a, &b ) == 2 ) {
        data d;
        d.x = i;
        d.weight = a;
        d.iq = b;
        dp[i] = d;
        i++;
    }
    nelements = i;
    qsort( dp, nelements, sizeof( data ), compare );
    int *lis = (int *) calloc( nelements, sizeof( int ) );
    lis[0] = 1;
    for ( i = 1; i < nelements; i++ ) {
        temp = 0;
        for ( j = 0; j < i; j++ ) {
            if ( dp[j].weight < dp[i].weight && dp[j].iq > dp[i].iq && lis[j] > temp ) {
                temp = lis[j];
            }
        }
        lis[i] = temp + 1;
        if ( lis[i] > max ) max = lis[i];
    }
    printf("%i\n", max );
    reconstruct_path( max, nelements - 1, lis, dp );
    return 0;
}
