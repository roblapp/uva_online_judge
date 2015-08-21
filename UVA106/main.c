#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* ACCEPTED 0.355s */
/*
m, n coprime and m - n odd
a = m^2-n^2
b = 2mn
c = m^2+n^2
c <= N
*/

int gcd(int a, int b){
    while (b != 0){
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int main() {

    int m, n, N, a, b, c, result, count;

    while ( scanf("%i", &N ) == 1 ) {
        int *p = (int *) calloc( N + 1, sizeof( int ) );
        result = count = 0;
        for ( m = 1; m < sqrt( N ); m += 2 ) {
			for ( n = 2; n < (N/2) && m*m + n*n <= N; n += 2 ) {
				if ( gcd( m, n ) == 1 ) result++;
				a = abs( m*m - n*n );
				b = abs( 2*m*n );
				c = abs( m*m + n*n );
				int k = 1;
				while (k * c <= N) {
					p[k*a] = 1;
					p[k*b] = 1;
					p[k*c] = 1;
					k++;
				}
			}
		}
		for ( m = 1; m <= N; m++ ) {
            if ( p[m] == 0 ) count++;
		}
        free( p );
		printf("%i %i\n", result, count );
    }

    return 0;
}
