#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b;
    while ( scanf("%i %i", &a, &b ) != EOF ) printf("%i\n", (2*a*b) );
    return 0;
}
