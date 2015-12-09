class UnionFind {
public:
    int parent[MAXN];
    int componentSize[MAXN];
    int n, numberOfDisjointSets;

    UnionFind(int _n) {
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            componentSize[i] = i;
        }
        n = _n;
        numberOfDisjointSets = n;
    }

    int findParent(int x) {
        if (parent[x] == x)
            return x;
        return findParent(parent[x]);
    }

    void unionSets(int x, int y) {
        int root0 = findParent(x);
        int root1 = findParent(y);

        if (root0 == root1) return;

        if (componentSize[root0] >= componentSize[root1]) {
            componentSize[root0] += componentSize[root1];
            parent[root1] = root0;
        } else {
            componentSize[root1] += componentSize[root0];
            parent[root0] = root1;
        }
        numberOfDisjointSets--;
    }

    bool isSameComponent(int x, int y) {
        return (findParent(x) == findParent(y));
    }
};