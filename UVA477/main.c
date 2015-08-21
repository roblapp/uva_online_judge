#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ACCEPTED 0.022s */

#define MAX 10

bool circle_contains(double x0, double y0, double x1, double y1, double r) {
    return  r*r > (x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1);
}

int main() {

    char c;
    int i, k = 0, t = 1;

    double x, y;

    FILE *fp = stdin;

    double r[MAX][4];
    char type[MAX];

    while ((c = fgetc(fp)) != '*') {
        if (c == 'r') {
            for (i = 0; i < 4; i++) {
                fscanf(fp, "%lf", &r[k][i]);
            }
            type[k++] = c;
        } else if (c == 'c') {
            for (i = 0; i < 3; i++) {
                fscanf(fp, "%lf", &r[k][i]);
            }
            type[k++] = c;
        }

        fgetc(fp);
    }
    bool seen;
    while (fscanf(fp, "%lf %lf", &x, &y) == 2 && (x != 9999.9 || y != 9999.9)) {
        seen = false;
        for (i = 0; i < k; i++) {
            if (type[i] == 'r') {
                if (x > r[i][0] && x < r[i][2] && y < r[i][1] && y > r[i][3]) {
                    printf("Point %i is contained in figure %i\n", t, (i + 1));
                    seen = true;
                }
            } else if (type[i] == 'c') {
                if (circle_contains(r[i][0], r[i][1], x, y, r[i][2]) ) {
                    printf("Point %i is contained in figure %i\n", t, (i + 1));
                    seen = true;
                }
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
