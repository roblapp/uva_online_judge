#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>

/*
Accepted: 0.326s
Category: graphs
Algorithm: Kruskal's MST algorithm
*/

using namespace std;

#define ASCII_DIFF '0'

struct Edge {
    int x, y, cost;
    Edge() { Edge(0, 0, 0); }
    Edge(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {};
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

bool compare(Edge na, Edge nb) {
    return na.cost < nb.cost;
}

int computeEdgeCost(string &sa, string &sb) {
    int N = 4, cost = 0, cmax, cmin;
    for (int i = 0; i < N; i++) {
        cmax = max(sa[i], sb[i]) - ASCII_DIFF;
        cmin = min(sa[i], sb[i]) - ASCII_DIFF;
        cost += min(cmax - cmin, 10 - cmax + cmin);
    }
    return cost;
}

int main() {
	int ncases, nv, ne, nDistinctVertices, cost;
	string vertexString;

	cin >> ncases;
	while (ncases--) {
        cin >> nv;
        map<string,int> m;
        map<string,int>::iterator it;
        vector<string> reverseMap;
        string init = "0000";
        nDistinctVertices = 0;
        cost = INT_MAX;
        for (int i = 0; i < nv; i++) {
            cin >> vertexString;
            it = m.find(vertexString);
            if (it == m.end()) {
                m[vertexString] = i;
                reverseMap.push_back(vertexString);
                nDistinctVertices++;
                cost = min(cost, computeEdgeCost(init, vertexString));
            }
        }
        vector<Edge> edgeList;
        for (int i = 0; i < nDistinctVertices - 1; i++) {
            for (int j = i + 1; j < nDistinctVertices; j++) {
                edgeList.push_back(Edge(m[reverseMap[i]], m[reverseMap[j]], computeEdgeCost(reverseMap[i], reverseMap[j])));
            }
        }
        sort(edgeList.begin(), edgeList.end(), compare);
        ne = (int) edgeList.size();
        UnionFind uf(nDistinctVertices);
        for (int i = 0; i < ne; i++) {
            if (!uf.isSameComponent(edgeList[i].x, edgeList[i].y)) {
                uf.unionSets(edgeList[i].x, edgeList[i].y);
                cost += edgeList[i].cost;
            }
        }
        cout << cost << endl;
	}
    return 0;
}
