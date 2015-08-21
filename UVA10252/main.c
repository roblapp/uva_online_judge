#include <stdio.h>
#include <stdlib.h>

/*
ACCEPTED 0.019s
*/

#define MAXLINE 1005

const int n = 26;
const int diff = 97;
int a[26];

void init() {
    int i;
    for ( i = 0; i < n; i++ ) {
        a[i] = 0;
    }
}

int compare( const void *a, const void *b ) {
    char *pa = (char *)a;
    char *pb = (char *)b;
    if ( *pa < *pb ) {
        return -1;
    } else if ( *pa > *pb ) {
        return 1;
    }
    return 0;
}

void process( char line[] ) {
    int i = 0;
    while ( line[i] != 0 && line[i] != '\n' ) {
        a[line[i]-diff]++;
        i++;
    }
}

void find() {
    char c;
    char res[MAXLINE];
    int i = 0;
    while ( ( c = getchar() ) != EOF && c != '\n' ) {
        if ( a[c-diff] > 0 ) {
            res[i++] = c;
            a[c-diff]--;
        }
    }
    res[i] = 0;
    qsort( res, i, sizeof( char ), compare );
    printf("%s\n", res );
}

int main() {
    char line[MAXLINE];
    init();
    while( fgets( line, MAXLINE, stdin ) != NULL ) {
        process( line );
        find();
        init();
    }

    return 0;
}
