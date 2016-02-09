#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

/*
Accepted: 0.000s
Category: graphs
Algorithm: Kruskal's MST algorithm
*/

using namespace std;

#define ASCII_DIFF 'A'

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

bool compare(Edge ea, Edge eb) {
    if (ea.cost < eb.cost)
        return true;
    else if (ea.cost > eb.cost)
        return false;
    int mina = min(ea.x, ea.y);
    int minb = min(eb.x, eb.y);
    if (mina < minb)
        return true;
    else if (mina > minb)
        return false;
    return max(ea.x, ea.y) < max(eb.x, eb.y);
}

int main() {
	int ncases, nv, cost, n, N = 1, minc, maxc, k;
	string line, temp;

	cin >> ncases;
	while (ncases--) {
        cin >> nv; getline(cin, line); /* Drain newline */
        vector<Edge> edgeList;
        for (int i = 0; i < nv; i++) {
            getline(cin, line);
            stringstream ss(line);
            k = 0;
            while (getline(ss, temp, ',')) {
                cost = atoi(temp.c_str());
                if (i != k && cost > 0)
                    edgeList.push_back(Edge(i, k, cost));
                k++;
            }
        }
        sort(edgeList.begin(), edgeList.end(), compare);
        n = (int) edgeList.size();
        UnionFind uf(n);
        cout << "Case " << N++ << ":" << endl;
        for (int i = 0; i < n; i++) {
            if (!uf.isSameComponent(edgeList[i].x, edgeList[i].y)) {
                uf.unionSets(edgeList[i].x, edgeList[i].y);
                maxc = max(edgeList[i].x, edgeList[i].y);
                minc = min(edgeList[i].x, edgeList[i].y);
                cout << (char)(minc + ASCII_DIFF) << "-" << (char)(maxc + ASCII_DIFF) << " " << edgeList[i].cost << endl;
            }
        }
	}
    return 0;
}
