#include <iostream>
#include <fstream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* ACCEPTED 0.152s */


/*
With union find data structure - run time 0.152s
with graph data structure running an exit early bfs - 1.232s!!!
*/

#define MAXV 10000
#define IN cin

using namespace std;

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

void split_string(string line, int& res0, int &res1) {
    int i = 0, len = line.length();
    res0 = res1 = 0;
    while (!isdigit(line[i])) {
        i++;
    }

    res0 = (line[i] - 48);
    i++;
    while (isdigit(line[i])) {
        res0 = 10 * res0 + (line[i] - 48);
        i++;
    }

    while (!isdigit(line[i])) {
        i++;
    }

    res1 = (line[i] - 48);
    i++;
    while (i < len && isdigit(line[i])) {
        res1 = 10 * res1 + (line[i] - 48);
        i++;
    }
}

int main() {
    int i, n, x, y, z;
    int nqueries = 0, nsuccess = 0;
    string line;
    union_find s;

    IN >> n;
    getline(IN, line);
    getline(IN, line);

    for (i = 0; i < n; i++) {
        if (i > 0) cout << endl;

        nqueries = nsuccess = 0;
        IN >> z;
        init(&s, z);

        getline(IN, line);

        while (true) {
            if (!getline(IN, line) || line.empty()) {
                break;
            }

            split_string(line, x, y);

            if (line[0] == 'c') { /* add edge to graph */
                union_sets(&s, x, y);
            } else { /* a query */
                nqueries++;
                if (is_same_component(&s, x, y)) {
                    nsuccess++;
                }
            }
        }

        cout << nsuccess << "," << (nqueries - nsuccess) << endl;
    }

    return 0;
}

/*

BFS version 2

#include <iostream>
#include <fstream>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXV 100000

using namespace std;

struct vertex {
    int y;
    struct vertex *next;
};

struct graph {
    struct vertex *vertices[MAXV + 1];
    int nvertices;
};

typedef struct graph graph;
typedef struct vertex vertex;

void init_graph( graph *g ) {
    int i;
    g->nvertices = 0;
    for (i = 0; i <= MAXV; i++ ) g->vertices[i] = NULL;
}

void insert_edge( graph *g, int x, int y, bool dir ) {
    vertex *v = ( vertex * ) malloc ( sizeof( vertex ) );

    v->y = y;
    v->next = g->vertices[x];
    g->vertices[x] = v;

    if ( dir )
        insert_edge( g, y, x, false );
}

bool bfs(graph *g, int src, int dst) {
    int v = src, n;
    bool disc[MAXV + 1];
    vertex *temp;
    queue<int> q;

    memset(disc, 0, sizeof(disc));
    disc[v] = true;
    q.push(v);

    while (!q.empty()) {
        v = q.front();
        if (v == dst) return true;
        q.pop();
        temp = g->vertices[v];
        while (temp != NULL) {
            n = temp->y;
            if (!disc[n]) {
                disc[n] = true;
                q.push(n);
            }
            temp = temp->next;
        }
    }
    return false;
}

void split_string(string line, int& res0, int &res1) {
    int i = 0, len = line.length();
    res0 = res1 = 0;
    while (!isdigit(line[i])) {
        i++;
    }

    res0 = (line[i] - 48);
    i++;
    while (isdigit(line[i])) {
        res0 = 10 * res0 + (line[i] - 48);
        i++;
    }

    while (!isdigit(line[i])) {
        i++;
    }

    res1 = (line[i] - 48);
    i++;
    while (i < len && isdigit(line[i])) {
        res1 = 10 * res1 + (line[i] - 48);
        i++;
    }
}

int main() {
    int i, n, x, y, z;
    int nqueries = 0, nsuccess = 0;
    string line;
    graph g;

    cin >> n;
    getline(cin, line);
    getline(cin, line);

    for (i = 0; i < n; i++) {
        if (i > 0) cout << endl;
        init_graph(&g);
        nqueries = nsuccess = 0;
        cin >> z;

        getline(cin, line);

        while (true) {
            if (!getline(cin, line) || line.empty()) {
                break;
            }

            split_string(line, x, y);

            if (line[0] == 'c') {
                insert_edge(&g, x, y, true);
            } else {
                nqueries++;
                if (bfs(&g, x, y)) {
                    nsuccess++;
                }
            }
        }

        cout << nsuccess << "," << (nqueries - nsuccess) << endl;
    }

    return 0;
}

*/
