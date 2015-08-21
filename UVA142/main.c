#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

/* ACCEPTED 0.016s */

#define MAX_RECT 25
#define MAX_ICON 50
#define DIFF 65

struct rect {
    char region;
    int vertices[4];
};

struct icon {
    int number;
    int vertices[2];
};

typedef struct rect rect;
typedef struct icon icon;

rect r[MAX_RECT];
icon i[MAX_ICON];

int rectindex = 0;
int iconindex = 0;

int main() {
    char c;
    int j, k, x, y;
    bool check_hidden = false;
    bool avail[MAX_ICON];
    int soln[MAX_ICON];
    int solnname[MAX_ICON];
    FILE *fp = stdin;

    for (j = 0; j < MAX_ICON; j++) {
        avail[j] = true;
    }
    while (true) {
        while ((c = fgetc(fp)) != EOF && c != '\n' && c != 'I' && c != 'R' && c != 'M' && c != '#')
            ;
        for (j = 0; j < MAX_ICON; j++) soln[j] = solnname[j] = -1;

        if (c == 'I') {
            fscanf(fp, "%i %i", &i[iconindex].vertices[0], &i[iconindex].vertices[1]);
            i[iconindex].number = iconindex + 1;
            iconindex++;
        } else if (c == 'R') {
            fscanf(fp, "%i %i %i %i", &r[rectindex].vertices[0], &r[rectindex].vertices[1],
                                        &r[rectindex].vertices[2], &r[rectindex].vertices[3]);
            r[rectindex].region = (char) (rectindex + DIFF);
            rectindex++;
        } else if (c == 'M') {
            if (!check_hidden) {
                for (k = 0; k < iconindex; k++) {
                    x = i[k].vertices[0];
                    y = i[k].vertices[1];
                    for (j = rectindex - 1; j >= 0; j--) {
                        if (x >= r[j].vertices[0] && x <= r[j].vertices[2] &&
                            y >= r[j].vertices[1] && y <= r[j].vertices[3]) {
                            avail[k] = false;
                        }
                    }
                }
                check_hidden = true;
            }

            fscanf(fp, "%i %i", &x, &y);
            bool check = true;
            int dist = INT_MAX;
            /* Check regions first*/
            for (j = rectindex - 1; j >= 0; j--) {
                /* if item is in region... */
                if (x >= r[j].vertices[0] && x <= r[j].vertices[2] &&
                            y >= r[j].vertices[1] && y <= r[j].vertices[3]) {
                    check = false;
                    printf("%c", r[j].region);
                    break;
                }
            }
            int ind = 0;
            if (check) {
                for (j = 0; j < iconindex; j++) {
                    if (avail[j]) {
                        int temp = (x - i[j].vertices[0]) * (x - i[j].vertices[0]) +
                                    (y - i[j].vertices[1]) * (y - i[j].vertices[1]);
                        if (temp <= dist) {
                            dist = temp;
                            soln[ind] = dist;
                            solnname[ind++] = j;
                        }
                    }
                }

                for (j = 0; j < MAX_ICON; j++) {
                    if (soln[j] == dist) {
                        printf("%3i", i[solnname[j]].number);
                    }
                }
            }
            putchar('\n');
        } else if (c == '#') break;

        while ((c = fgetc(fp)) != EOF && c != '\n')
            ;
    }

    fclose(fp);

    return 0;
}
