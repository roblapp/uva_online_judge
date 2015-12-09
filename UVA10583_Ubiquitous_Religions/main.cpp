#include <iostream>

using namespace std;

/*
Accepted: 0.286s
Description: data structures - union find
*/

#define read cin
#define MAXV 50000 + 1

typedef struct {
    int parent[MAXV];
    int componentSize[MAXV];
    int n;
    int numSets;
} UnionFind;

void init(UnionFind &s, int n) {
    for (int i = 0; i <= n; i++) {
        s.parent[i] = i;
        s.componentSize[i] = 0;
    }
    s.n = 0;
    s.numSets = n;
}

int findParent(UnionFind &s, int x) {
    if (s.parent[x] == x) {
        return x;
    }
    return findParent(s, s.parent[x]);
}

void unionSets(UnionFind &s, int x, int y) {
    int root0 = findParent(s, x);
    int root1 = findParent(s, y);

    if (root0 == root1) return;

    if (s.componentSize[root0] >= s.componentSize[root1]) {
        s.componentSize[root0] += s.componentSize[root1];
        s.parent[root1] = root0;
    } else {
        s.componentSize[root1] += s.componentSize[root0];
        s.parent[root0] = root1;
    }
    s.numSets--;
}

bool isSameComponent(UnionFind &s, int x, int y) {
    return (findParent(s, x) == findParent(s, y));
}

int main() {
    int n, m, x, y, N = 1;
    UnionFind uf;

    while (read >> n >> m && (n != 0 || m != 0)) {
        init(uf, n);
        for (int i = 0; i < m; i++) {
            read >> x >> y;
            unionSets(uf, x, y);
        }
        cout << "Case " << N++ << ": " << uf.numSets << endl;
    }
    return 0;
}
