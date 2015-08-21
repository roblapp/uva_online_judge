#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>

/* ACCEPTED 2.116s */
/*
Algorithm:

Dijkstra's single source shortest path.

*****NOTE: This problem had a submission time limit of almost 7 seconds,
so the horrible run time here isn't as bad as it would be on a normal
problem.
*/

#define MAXV 500
#define MAXLINE 100

using namespace std;

typedef struct {
    int y, d;
} edge_node;

vector<edge_node> g[MAXV + 1];

int max_distance(int src, bool has_existing[], int NV) { /* Dijkstra's algorithm */
    int dist[MAXV + 1];
    bool visited[MAXV + 1];
    int v, n, w, tm;
    vector<edge_node>::iterator it;
    for (int i = 0; i <= NV; i++) {
        dist[i] = (has_existing[i]) ? 0 : INT_MAX; /* If there is an existing station */
        visited[i] = false;
    }

    v = src;
    dist[v] = 0;

    while (!visited[v]) {
        visited[v] = true;
        for (it = g[v].begin(); it != g[v].end(); it++) { /* check neighbors of v */
            n = it->y; w = it->d;
            /* if we haven't processed n and using v as an intermediate vertex is shorter
                than the distance currently found between n and src, update*/
            if (dist[n] > dist[v] + w) {
                dist[n] = dist[v] + w;
            }
        }

        v = 1;
        tm = INT_MAX;
        for (int i = 1; i <= NV; i++) {
            if (!visited[i] and dist[i] < tm) {
                v = i;
                tm = dist[i];
            }
        }
    }
    tm = INT_MIN;
    for (int i = 1; i <= NV; i++) {
        if (dist[i] != INT_MAX and dist[i] > tm) {
            tm = dist[i];
        }
    }

    return tm; /* return the max of the min distances */
}

void ins(int x, int y, int d) {
    edge_node t;
    t.y = y;
    t.d = d;
    g[x].push_back(t);
}

int main() {

    int n, nexist, nint, x, y, d, N = 0, k, snode, soln;
    char line[MAXLINE + 1];
    bool exist[MAXV + 1];

    FILE *fp = stdin;

    fscanf(fp, "%i", &n);

    while (n--) {
        fscanf(fp, "%i %i", &nexist, &nint);
        for (int i = 0; i <= nint; i++) {
            g[i].clear();
            exist[i] = false;
        }
        soln = INT_MAX;
        snode = 1;
        for (int i = 0; i < nexist; i++) { /* read all of the existing fire stations
                                            and compute the furthest distance so far */
            fscanf(fp, "%i", &x); /* compute the furthest distance between x and each house */
            exist[x] = true;
        }

        fgets(line, MAXLINE + 1, fp);

        while (fgets(line, MAXLINE + 1, fp)) {
            if (sscanf(line, "%i %i %i", &x, &y, &d) != 3) {
                break;
            }
            ins(x, y, d);
            ins(y, x, d);
        }

        for (int i = 1; i <= nint; i++) {
            if (!exist[i] and (k = max_distance(i, exist, nint)) < soln) {
                soln = k;
                snode = i;
            }
        }

        if (N++) putchar('\n');
        printf("%i\n", snode);
    }

    fclose(fp);

    return 0;
}
