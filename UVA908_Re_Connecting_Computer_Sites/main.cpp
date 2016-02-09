#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.000s
Description: graphs
Algorithm: Kruskal's minimum spanning tree
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
	int n, src, dst, cost, soln0, soln1, k, m, N = 0;

	while (cin >> n) {
	    soln0 = 0;
	    vector<Node> edgeList;
        for (int i = 0; i < n-1; i++) {
            cin >> src >> dst >> cost;
            soln0 += cost;
        }
        cin >> k;
        for (int i = 0; i < k; i++) {
            cin >> src >> dst >> cost;
            edgeList.push_back(Node(src-1, dst-1, cost));
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> src >> dst >> cost;
            edgeList.push_back(Node(src-1, dst-1, cost));
        }
        UnionFind uf(n);
        soln1 = 0;
        sort(edgeList.begin(), edgeList.end(), compare);
        for (int i = 0, ne = k + m; i < ne; i++) {
            if (!uf.isSameComponent(edgeList[i].x, edgeList[i].y)) {
                uf.unionSets(edgeList[i].x, edgeList[i].y);
                soln1 += edgeList[i].cost;
            }
        }
        if (N++)
            cout << endl;
        cout << soln0 << endl << soln1 << endl;
	}
    return 0;
}
