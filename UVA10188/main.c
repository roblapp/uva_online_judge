#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/* ACCEPTED 0.016 */

#define MAXLEN 12000
#define TRUE 1
#define FALSE 0

char soln[MAXLEN + 1];
char team[MAXLEN + 1];
int sl, tl;

void readline( char line[], int *cp, FILE *fp ) {
    char c;
    while ( ( c = fgetc( fp ) ) != EOF && c != '\n' ) {
        line[(*cp)++] = c;
    }
    line[(*cp)++] = '\n';
    line[*cp] = 0;
}

int accepted() {
    if ( sl != tl ) return FALSE;
    return ( strcmp( soln, team ) == 0 );
}

int pres_error() {
    int i = 0, j, nsd = 0, ntd = 0, ndm = 0;
    for ( i = 0; i < sl; i++ )
        if ( isdigit( soln[i] ) )
            nsd++;
    for ( i = 0; i < tl; i++ )
        if ( isdigit( team[i] ) )
            ntd++;
    if ( nsd != ntd ) return FALSE;
    i = j = 0;
    while ( ndm < nsd ) {
        while ( i < sl && !isdigit( soln[i] ) ) {
            i++;
        }
        if ( i == sl ) return FALSE;
        while ( j < tl && !isdigit( team[j] ) ) {
            j++;
        }
        if ( j == tl ) return FALSE;
        if ( soln[i] != team[j] ) return FALSE;
        else ndm++;
        i++; j++;
    }
    return TRUE;
}

int main()
{
    int i, j, k = 0, n, m;

    while ( scanf("%i", &n ) == 1 && n != 0 ) {
        k++;
        soln[0] = team[0] = 0;
        j = 0;
        getchar();
        for ( i = 0; i < n; i++ ) {
            readline( soln, &j, stdin );
        }
        sl = j;
        scanf("%i", &m);
        j = 0;
        getchar();
        for ( i = 0; i < m; i++ ) {
            readline( team, &j, stdin );
        }
        tl = j;
        printf("Run #%i: ", k );
        if ( accepted() ) {
            printf("Accepted\n");
        } else if ( pres_error() ) {
            printf("Presentation Error\n");
        } else {
            printf("Wrong Answer\n");
        }
    }

    return 0;
}
