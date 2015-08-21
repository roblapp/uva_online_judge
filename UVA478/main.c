#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* ACCEPTED 0.022s */

#define MAX 10

bool circle_contains(double x0, double y0, double x1, double y1, double r) {
    return  r*r > (x0 - x1)*(x0 - x1) + (y0 - y1)*(y0 - y1);
}

double sign(double x0, double y0, double x1, double y1, double x2, double y2) {

    return (x0 - x2) * (y1 - y2) - (x1 - x2) * (y0 - y2);
}

bool triangle_contains(double x0, double y0, double x1, double y1, double x2, double y2, double x3, double y3) {

    bool b1, b2, b3;

    b1 = sign(x3, y3, x0, y0, x1, y1) < 0.0f;
    b2 = sign(x3, y3, x1, y1, x2, y2) < 0.0f;
    b3 = sign(x3, y3, x2, y2, x0, y0) < 0.0f;

    return ((b1 == b2) && (b2 == b3));
}

int main() {

    char c;
    int i, k = 0, t = 1;

    double x, y;

    FILE *fp = stdin;

    double r[MAX][6];
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
        } else if (c == 't') {
            for (i = 0; i < 6; i++) {
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
            } else if (type[i] == 't') {
                if (triangle_contains(r[i][0], r[i][1], r[i][2], r[i][3], r[i][4], r[i][5], x, y) ) {
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
