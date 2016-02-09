#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

/*
Accepted: 0.196s
Category: graphs
Algorithm: Kruskal's MST algorithm
*/

using namespace std;

struct Node {
    int x, y, n;
    Node(int _x, int _y, int _n) : x(_x), y(_y), n(_n) {}
};

double distanceBetweenNodes(Node &na, Node &nb) {
    int x = na.x - nb.x;
    int y = na.y - nb.y;
    return sqrt(x*x + y*y);
}

struct Edge {
    Node src, dst;
    double dist;
    Edge(Node &_src, Node &_dst) : src(_src), dst(_dst), dist(distanceBetweenNodes(_src, _dst)) {};
};

bool compare(Edge ea, Edge eb) {
    return ea.dist < eb.dist;
}

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

int main() {
	int ncases, nv, src, dst, ne, nstates;
	double maxDist, roadDist, railDist;

	cin >> ncases;
	for (int i = 1; i <= ncases; i++) {
        cin >> nv >> maxDist;
        vector<Node> pointv;
        for (int j = 0; j < nv; j++) {
            cin >> src >> dst;
            pointv.push_back(Node(src, dst, j));
        }
        vector<Edge> edgeList;
        for (int j = 0; j < nv - 1; j++)
            for (int k = j + 1; k < nv; k++)
                edgeList.push_back(Edge(pointv[j], pointv[k]));
        sort(edgeList.begin(), edgeList.end(), compare);

        ne = (int) edgeList.size();
        UnionFind uf(nv);
        roadDist = railDist = 0;
        nstates = 0;
        for (int j = 0; j < ne; j++) {
            if (!uf.isSameComponent(edgeList[j].src.n, edgeList[j].dst.n)) {
                uf.unionSets(edgeList[j].src.n, edgeList[j].dst.n);
                if (edgeList[j].dist <= maxDist) {
                    roadDist += edgeList[j].dist;
                } else {
                    railDist += edgeList[j].dist;
                    nstates++;
                }
            }
        }
        cout << "Case #" << i << ": " << nstates + 1 << " " << nearbyint(roadDist) << " " << nearbyint(railDist) << endl;
	}
    return 0;
}
