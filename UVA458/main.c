#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* ACCEPTED 0.026 */

int main() {
    char c;
    while ( ( c = getchar() ) != EOF )
        ( c == '\n' ) ? putchar( c ) : putchar( c - 7 );
    return 0;
}
