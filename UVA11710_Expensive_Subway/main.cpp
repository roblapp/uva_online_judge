#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
Accepted: 0.502s
Description: graphs
Algorithm: Kruskal's MST algorithm
*/

using namespace std;

struct Node {
    int x, y, cost;
    Node() { Node(0, 0, 0); }
    Node(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {};
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> componentSize;
    int n, numberOfDisjointSets;
public:
    UnionFind(int _n) {
        n = _n;
        for (int i = 0; i < n; i++) {
            parent.push_back(i);
            componentSize.push_back(1);
        }
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

    int getNumberOfDisjointSets() {
        return numberOfDisjointSets;
    }
};

bool compare(Node na, Node nb) {
    return na.cost < nb.cost;
}

int main() {
	int nv, ne, cost;
	string src, dst;

	while (cin >> nv >> ne and (nv != 0 or ne != 0)) {
        map<string, int> m;
        for (int i = 0; i < nv; i++) {
            cin >> src;
            m[src] = i;
        }
        vector<Node> edgeList;
        for (int i = 0; i < ne; i++) {
            cin >> src >> dst >> cost;
            edgeList.push_back(Node(m[src], m[dst], cost));
        }
        cin >> src;
        UnionFind uf(nv);
        cost = 0;
        sort(edgeList.begin(), edgeList.end(), compare);
        for (int i = 0; i < ne; i++) {
            if (!uf.isSameComponent(edgeList[i].x, edgeList[i].y)) {
                uf.unionSets(edgeList[i].x, edgeList[i].y);
                cost += edgeList[i].cost;
            }
        }
        if (uf.getNumberOfDisjointSets() == 1)
            cout << cost << endl;
        else
            cout << "Impossible" << endl;
	}
    return 0;
}
