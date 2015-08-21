#include <iostream>
#include <fstream>
#include <climits>
#include <queue>

/* ACCEPTED 1.319s */
/*
Not a great time, but it will suffice.

Algorithm:

Kruskal's MST algorithm, priority queues and set union data structures.
*/

#define MAXV 10000
#define MAXTOWNS 750
#define in cin

using namespace std;

struct union_find {
    int parent[MAXV];
    int size[MAXV];
    int n;
};

struct vertex {
    int n, px, py;
};

struct edge {
    int d, src, dst;
};

class compare_edge {
    public:
    bool operator()(edge& a, edge& b) {
       return (a.d > b.d);
    }
};

typedef struct union_find union_find;
typedef struct vertex vertex;
typedef struct edge edge;

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

int dist(vertex& temp0, vertex& temp1) {
    return (temp0.px - temp1.px) * (temp0.px - temp1.px) + (temp0.py - temp1.py) * (temp0.py - temp1.py);
}

int main() {

    int a, b, ncases, ncities, nexist;
    vertex towns[MAXTOWNS];
    union_find uf;

    priority_queue<edge, vector<edge>, compare_edge> q;

    in >> ncases;

    for (int i = 0; i < ncases; i++) {

        init(&uf, MAXV);

        in >> ncities;

        for (int j = 0; j < ncities; j++) {
            towns[j].n = (j + 1);
            in >> towns[j].px >> towns[j].py;

        }
        edge temp;
        for (int j = 0; j < ncities - 1; j++) {
            for (int k = j + 1; k < ncities; k++) {
                temp.d = dist(towns[j], towns[k]);
                temp.src = towns[j].n;
                temp.dst = towns[k].n;
                q.push(temp);
            }
        }

        in >> nexist;

        for (int j = 0; j < nexist; j++) {
            /* merge these components */
            in >> a >> b;
            union_sets(&uf, a, b);
        }
        edge e;
        bool found = false;
        if (i > 0) cout << endl;
        while (!q.empty()) {
            e = q.top();
            q.pop();
            if (!is_same_component(&uf, e.src, e.dst)) {
                union_sets(&uf, e.src, e.dst);
                found = true;
                cout << e.src << " " << e.dst << endl;
            }
        }
        if (!found) cout << "No new highways need" << endl;
    }

    return 0;
}
