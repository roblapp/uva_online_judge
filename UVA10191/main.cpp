#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <climits>
#include <cstring>

#define in cin
#define MAXLEN 300
#define MAXN (18 - 10) * 60 + 1

using namespace std;

int get_index(int h, int m) {
    return (h - 10) * 60 + m; /* largest value this can return is 480 -> 18:00 */
}

void mark_index(int sh, int sm, int eh, int em, bool t[]) {

    int s = get_index(sh, sm);
    int e = get_index(eh, em);

    for (int i = s; i < e; i++) { /* Important note: NEVER can get to mark t[480] */
        t[i] = false;
    }
}

void kadanes(int n, bool t[]) {
    int maxsofar = 0, maxendhere = 0;
    bool prev_false = true;

    int s = 0, ms = 0;

    for (int i = 0; i < MAXN - 1; i++) {
        if (t[i]) {
            if (prev_false) { /* start the interval here */
                s = i;
            }
            maxendhere++;
            prev_false = false;
        } else {
            if (!prev_false) { /* end the interval at i - 1 */
                if (maxendhere > maxsofar) {
                    maxsofar = maxendhere;
                    ms = s;
                }
            }
            maxendhere = 0;
            prev_false = true;
        }
    }

    if (!prev_false) { /* end the interval at i - 1 */
        if (maxendhere > maxsofar) {
            maxsofar = maxendhere;
            ms = s;
        }
    }

    int hours = maxsofar / 60;
    int minutes = maxsofar % 60;
    if (hours > 0) {
        printf("Day #%i: the longest nap starts at %i:%.2i and will last for %i hours and %i minutes.\n", n, ms/60+10, ms%60, hours, minutes);
    } else {
        printf("Day #%i: the longest nap starts at %i:%.2i and will last for %i minutes.\n", n, ms/60+10, ms%60, minutes);
    }
}

int main() {

    int n, sh, sm, eh, em, k = 1;
    bool t[MAXN];
    char line[MAXLEN];
    FILE *fp = stdin;

    while (fscanf(fp, "%i", &n) == 1) {
        memset(t, true, sizeof(t));
        for (int i = 0; i < n; i++) {
            fscanf(fp, "%i:%i %i:%i", &sh, &sm, &eh, &em);
            fgets(line, MAXLEN, fp);

            mark_index(sh, sm, eh, em, t);
        }

        kadanes(k++, t);
    }

    fclose(fp);


    return 0;
}
