#include <iostream>
#include <cstdio>
#include <cstdlib>

#define MAXN 5
#define MAXOPER 3
#define SOLN 23

using namespace std;

const char opr[] = {'+', '-', '*'};


typedef struct {
    int x;
    bool used;
} data;

typedef struct {
    int data, pos;
} cand;

void construct_candidates(data a[], cand c[], int *ncandidates) {
    *ncandidates = 0;
    for (int i = 0; i < MAXN; i++) {
        if (!a[i].used) { /* If not used */
            c[*ncandidates].data = a[i].x;
            c[*ncandidates].pos = i;
            *ncandidates = *ncandidates + 1;
        }
    }
}

bool backtrack(data a[], int k, char prev_operator, int prev_number) {

    if (k == MAXN) {
        /* Check solution */
        return (prev_number == SOLN);
    }

    cand c[MAXN];
    int ncandidates = 0;

    construct_candidates(a, c, &ncandidates);

    for (int i = 0; i < ncandidates; i++) {
        /* Gives us an element from a that has not been used yet */
        /* Select a number, then add to prev_number */
        int can = c[i].data, pos = c[i].pos, temp;

        if (prev_operator == '+') temp = prev_number + can;
        else if (prev_operator == '-') temp = prev_number - can;
        else if (prev_operator == '*') temp = prev_number * can;
        else temp = can;

        a[pos].used = true;

        for (int j = 0; j < MAXOPER; j++) {
            if (backtrack(a, k + 1, opr[j], temp)) {
                return true;
            }
        }

        a[pos].used = false;
    }
    return false;
}

bool backtrack(data a[]) {

    for (int i = 0; i < MAXN; i++) {
        a[i].used = false;
    }
    return (backtrack(a, 0, 0, 0));
}

int prod(data a[]) {
    int res = 1;
    for (int i = 0; i < MAXN; i++) {
        res *= a[i].x;
    }
    return res;
}

int main() {

    int cnt;
    data a[MAXN];

    FILE *fp = stdin;

    while (fscanf(fp, "%i %i %i %i %i", &a[0].x, &a[1].x, &a[2].x, &a[3].x, &a[4].x)) {
        cnt = 0;
        for (int i = 0; i < MAXN; i++) if (a[i].x == 0) cnt++;
        if (cnt == MAXN) break;
        if (prod(a) < 23) printf("Impossible\n");
        else if (backtrack(a)) printf("Possible\n");
        else printf("Impossible\n");
    }

    fclose(fp);

    return 0;
}
