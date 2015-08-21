#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIFF 48

void add(char *a, char *b, int ndigits) {
    int i, sum = 0, carry = 0;
    char *result = (char *)calloc(ndigits + 1, sizeof(char));
    for ( i = 0; i < ndigits; i++ ) {
        sum = (a[ndigits-i-1] - DIFF) + (b[ndigits-i-1] - DIFF) + carry;
        result[ndigits-i-1] = (char)((sum % 10) + DIFF);
        carry = sum / 10;
    }
    printf("%s\n", result);
   free(result);
}

int main() {
    int i, j, x, y, ncases, ndigits, N = 0;
    FILE *fp = stdin;
    fscanf(fp,"%i", &ncases);
    fgetc(fp); fgetc(fp);
    for ( i = 0; i < ncases; i++ ) {
        fscanf(fp, "%i", &ndigits);
        char *a = (char *)calloc(ndigits + 1, sizeof(char));
        char *b = (char *)calloc(ndigits + 1, sizeof(char));
        for ( j = 0; j < ndigits; j++ ) {
            fscanf(fp,"%i %i", &x, &y );
            a[j] = (char) (x + DIFF);
            b[j] = (char) (y + DIFF);
        }
        if (N++) putchar('\n');
        add( a, b, ndigits);
        free(a); free(b);
        fgetc(fp); fgetc(fp);
    }
    fclose(fp);
    return 0;
}
