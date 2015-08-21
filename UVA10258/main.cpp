#include <cstdio>
#include <cstdlib>

/* ACCEPTED 0.018s */
/*
Algorithm:

Ad-hoc

IMPORTANT LESSON LEARNED:
I received many RTE due to a mistake in the call
to qsort... I originally had qsort(array + 1, MAXSTUDENTS + 1, sizeof(entry), compare)
and it should have been qsort(array + 1, MAXSTUDENTS, sizeof(entry), compare)...
I mistakenly put the additional bytes in the location to be sorted.

NOTE:
This is almost valid ANSI C code... just remove the C++ style #includes as
well as the using namespace std statement
*/

#define MAXSTUDENTS 100
#define MAXLINE 100 /* I changed this after the submission from 1000 to 100 so if this doesn't work change it back */
#define MAXPROBLEMS 15

using namespace std;

typedef struct {
    int contestant, num_solved, time_penalty; bool sub_made;
} entry;

typedef struct {
    int sub_time, n_bad_sub; bool solved;
} sub_entry;

int compare(const void *pa, const void *pb) {
    entry a = *((entry *) pa);
    entry b = *((entry *) pb);

    if (a.num_solved != b.num_solved) return (b.num_solved - a.num_solved);
    if (a.time_penalty != b.time_penalty) return (a.time_penalty - b.time_penalty);
    return (a.contestant - b.contestant);
}

int main() {

    int n, cn, p, t, N = 0;
    char res, line[MAXLINE];
    entry d[MAXSTUDENTS + 1];
    sub_entry c_times[MAXSTUDENTS + 1][MAXPROBLEMS + 1];

    scanf("%i", &n);
    fgets(line, MAXLINE, stdin);
    fgets(line, MAXLINE, stdin);

    while (n--) {
        for (int i = 1; i <= MAXSTUDENTS; i++) {
            for (int j = 1; j <= MAXPROBLEMS; j++) {
                c_times[i][j].sub_time = c_times[i][j].n_bad_sub = c_times[i][j].solved = 0;
            }
            d[i].contestant = i;
            d[i].num_solved = d[i].time_penalty = d[i].sub_made = false;
        }

        while (fgets(line, MAXLINE, stdin)) {
            if (sscanf(line, "%i %i %i %c", &cn, &p, &t, &res) != 4) { break; }
            if (res == 'I') { /* add item to submission list */
                if (!c_times[cn][p].solved) { c_times[cn][p].n_bad_sub++; }
            } else if (res == 'C') {
                if (!c_times[cn][p].solved) {
                    c_times[cn][p].solved = true;
                    c_times[cn][p].sub_time = t;
                }
            }
            d[cn].sub_made = true;
        }

        for (int i = 1; i <= MAXSTUDENTS; i++) { /* for each student */
            for (int j = 1; j <= MAXPROBLEMS; j++) { /* check each problem number */
                if (c_times[i][j].solved) { /* contestant successfully solved the problem */
                /* check each submission and see if it's the j_th submission */
                    d[i].num_solved++;
                    d[i].time_penalty += c_times[i][j].sub_time;
                    d[i].time_penalty += (20*c_times[i][j].n_bad_sub);
                }
            }
        }
        /* now sort them */
        qsort(d + 1, MAXSTUDENTS, sizeof(entry), compare);
        if (N++) { putchar('\n'); }
        for (int i = 1; i <= MAXSTUDENTS; i++) {
            if (d[i].sub_made) { printf("%i %i %i\n", d[i].contestant, d[i].num_solved, d[i].time_penalty); }
        }
    }

    return 0;
}
