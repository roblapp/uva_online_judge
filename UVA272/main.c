#include <stdio.h>
#include <stdlib.h>

/* ACCEPTED 0.012 */

#define MAXLINE 1000

int main() {
    int i, cnt = 0;
    char line[MAXLINE + 1];
    while (fgets(line, MAXLINE + 1, stdin) != NULL) {
        for (i = 0; line[i] != 0; i++)
            if (line[i] == '"') (cnt++ % 2 == 0) ? printf("``") : printf("\'\'");
            else putchar(line[i]);
    }
    return 0;
}
