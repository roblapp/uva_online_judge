#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

//#define read cin
#define MAXN 5000 + 1

class UnionFind {
public:
    int parent[MAXN];
    int componentSize[MAXN];
    int n, numberOfDisjointSets, maxComponent;

    void init(int _n) {
        for (int i = 0; i <= _n; i++) {
            parent[i] = i;
            componentSize[i] = 1;
        }
        n = _n;
        numberOfDisjointSets = n;
        maxComponent = 1;
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
            maxComponent = max(maxComponent, componentSize[root0]);
            parent[root1] = root0;
        } else {
            componentSize[root1] += componentSize[root0];
            maxComponent = max(maxComponent, componentSize[root1]);
            parent[root0] = root1;
        }
        numberOfDisjointSets--;
    }

    bool isSameComponent(int x, int y) {
        return (findParent(x) == findParent(y));
    }
};

int main() {
    ifstream read("test.txt");
    int c, r, src, dst;
    string line, srcStr, dstStr;
    map<string, int> m;
    UnionFind uf;

    while (read >> c >> r && (c != 0 || r != 0)) {
        uf.init(c);
        m.clear();
        getline(read, line); /* Drain newline */
        for (int i = 0; i < c; i++) {
            getline(read, line);
            m[line] = i;
        }
        for (int i = 0; i < r; i++) {
            getline(read, line);
            stringstream ss(line);
            ss >> srcStr >> dstStr;
            src = m[srcStr];
            dst = m[dstStr];
            uf.unionSets(src, dst);
        }
        cout << uf.maxComponent << endl;
        getline(read, line);
    }
    read.close();
    return 0;
}
