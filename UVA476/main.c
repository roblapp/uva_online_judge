#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ACCEPTED 0.016 */

#define MAX 10

int main() {

    char c;
    int i, k = 0, t = 1;

    double x, y;

    FILE *fp = stdin;

    double r[MAX][4];

    while ((c = fgetc(fp)) != '*') {
        for (i = 0; i < 4; i++) {
            fscanf(fp, "%lf", &r[k][i]);
        }
        k++;
        fgetc(fp);
    }
    bool seen;
    while (fscanf(fp, "%lf %lf", &x, &y) == 2 && (x != 9999.9 || y != 9999.9)) {
        seen = false;
        for (i = 0; i < k; i++) {
            if (x > r[i][0] && x < r[i][2] && y < r[i][1] && y > r[i][3]) {
                printf("Point %i is contained in figure %i\n", t, (i + 1));
                seen = true;
            }
        }
        if (!seen) {
            printf("Point %i is not contained in any figure\n", t);
        }
        t++;
    }

    fclose(fp);

    return 0;
}
