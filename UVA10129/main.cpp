#include <iostream>
#include <fstream>
#include <string>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ACCEPTED 0.072s */
/*
Algorithm used:

I exploited the mathematical properties
of graphs. This is a Euler path problem. From
graph theory it is known that a graph G has a Euler
path if:

1) every vertex has same in degree and out degree

OR

2) every vertex has same in degree and out degree EXCEPT
a vertex i and a vertex j such that indegree[i] = outdegree[i] + 1
and outdegree[j] = indegree[j] + 1

We also had to make sure the graph was connected. We can do this by
implementing a set union data structure.
*/

#define in cin
#define MAXV 26
#define DIFF 97

using namespace std;

int ind[MAXV];
int outd[MAXV];

struct union_find {
    int parent[MAXV];
    int size[MAXV];
    int n;
};

typedef struct union_find union_find;

void init(union_find *s, int n) {
    for (int i = 0; i <= n; i++) {
        s->parent[i] = i;
        s->size[i] = 0;
    }
    s->n = 0;
}

int find(union_find *s, int x) {
    if (s->parent[x] == x) {
        return x;
    }
    return find(s, s->parent[x]);
}

void union_sets(union_find *s, int x, int y) {
    int root0 = find(s, x);
    int root1 = find(s, y);

    if (root0 == root1) return;

    if (s->size[root0] >= s->size[root1]) {
        s->size[root0] = s->size[root0] + s->size[root1];
        s->parent[root1] = root0;
    } else {
        s->size[root1] = s->size[root0] + s->size[root1];
        s->parent[root0] = root1;
    }
}

bool is_same_component(union_find *s, int x, int y) {
    return (find(s, x) == find(s, y));
}

int main() {

    int n, ncases;
    string line;

    in >> ncases;

    for (int i = 0; i < ncases; i++) {
        in >> n;
        memset(ind, 0, sizeof(ind));
        memset(outd, 0, sizeof(outd));
        union_find u;
        init(&u, MAXV);
        for (int j = 0; j < n; j++) {
            in >> line;
            int pos = line.length() - 1;
            outd[line[0]-DIFF]++;
            ind[line[pos]-DIFF]++;
            union_sets(&u, line[0]-DIFF, line[pos]-DIFF);
        }
        int x = 0, y = 0;
        bool failed = false;
        for (int i = 0; i < MAXV && x < 2 && y < 2; i++) {
            if (ind[i] != outd[i]) {
                if (ind[i] == outd[i] + 1) {
                    x++;
                } else if (outd[i] == ind[i] + 1) {
                    y++;
                } else {
                    failed = true;
                    break;
                }
            }
        }
        if (failed || x != y || x > 1 || y > 1) {
            cout << "The door cannot be opened." << endl;
        } else {
            int k;
            for (k = 0; k < MAXV && ind[k] == 0; k++);
            for (int j = 0; j < MAXV; j++) {
                if ((ind[j] > 0 || outd[j] > 0) && !is_same_component(&u, j, k)) {
                    failed = true;
                    break;
                }
            }

            if (failed) {
                cout << "The door cannot be opened." << endl;
            } else {
                cout << "Ordering is possible." << endl;
            }
        }
    }

    return 0;
}
