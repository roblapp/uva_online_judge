#include <iostream>
#include <map>

/*
Accepted: 0.945s
Description: data structures - union find
*/

using namespace std;

#define read cin
#define out cout
#define MAXN 100000 + 1 /* This is a large upper bound - could experiment and try smaller */

class UnionFind {
public:
    int parent[MAXN];
    int componentSize[MAXN];

    int findParent(int x) {
        if (parent[x] == x)
            return x;
        return findParent(parent[x]);
    }

    int unionSets(int x, int y) {
        int root0 = findParent(x);
        int root1 = findParent(y);

        if (root0 == root1) return componentSize[root0];
        int result;

        if (componentSize[root0] >= componentSize[root1]) {
            componentSize[root0] += componentSize[root1];
            parent[root1] = root0;
            result = componentSize[root0];
        } else {
            componentSize[root1] += componentSize[root0];
            parent[root0] = root1;
            result = componentSize[root1];
        }
        return result;
    }

    bool isSameComponent(int x, int y) {
        return (findParent(x) == findParent(y));
    }
};

int main() {
    int ncases, n, k, posSrc, posDst;
    string line, src, dst;
    map<string, int> m;
    map<string, int>::iterator it;
    UnionFind uf;

    read >> ncases;
    while (ncases--) {
        read >> n; getline(read, line);
        m.clear();
        k = 0;
        for (int i = 0; i < n; i++) {
            read >> src >> dst; getline(read, line);
            if ((it = m.find(src)) == m.end()) {
                m[src] = k;
                uf.parent[k] = k;
                uf.componentSize[k] = 1;
                posSrc = k++;
            } else
                posSrc = it->second;
            if ((it = m.find(dst)) == m.end()) {
                m[dst] = k;
                uf.parent[k] = k;
                uf.componentSize[k] = 1;
                posDst = k++;
            } else
                posDst = it->second;
            out << uf.unionSets(posSrc, posDst) << endl;
        }
    }
    return 0;
}
