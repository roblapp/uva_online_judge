#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

/* ACCEPTED 0.042s */
/*
Algorithm:

DFS/Articulation points

*/

#define MAXV 105
#define NIL (-1)
#define in cin

using namespace std;

class Graph {
    vector<int> vertices[MAXV + 1];
    int nVertices;

    void APUtil(int v, bool visited[], int disc[], int low[], int parent[], bool ap[]);

public:
    Graph(int nVertices);
    void addEdge(int v, int w);
    void showArticulationPoints(string temp[], int n);
    void clearGraph();
};

Graph::Graph(int nVertices) {
    this->nVertices = nVertices;
}

void Graph::addEdge(int src, int dst) {
    vertices[src].push_back(dst);
    vertices[dst].push_back(src);
}

void Graph::APUtil(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]) {

    static int time = 0;

    int children = 0;

    visited[u] = true;

    disc[u] = low[u] = ++time;

    vector<int>::iterator it;

    for (it = vertices[u].begin(); it != vertices[u].end(); it++) {

        int v = *it;

        if (!visited[v]) {
            children++;
            parent[v] = u;
            APUtil(v, visited, disc, low, parent, ap);

            low[u] = min(low[u], low[v]);

            if (parent[u] == NIL and children > 1) {
                ap[u] = true;
            }

            if (parent[u] != NIL and low[v] >= disc[u]) {
                ap[u] = true;
            }
        } else if (v != parent[u]) {

            low[u] = min(low[u], disc[v]);
        }
    }
}

void Graph::showArticulationPoints(string temp[], int n) {
    bool *visited = new bool[nVertices];
    int *disc = new int[nVertices];
    int *low = new int[nVertices];
    int *parent = new int[nVertices];
    bool *ap = new bool[nVertices];

    for (int i = 0; i < nVertices; i++) {
        parent[i] = NIL;
        visited[i] = false;
        ap[i] = false;
    }

    for (int i = 0; i < nVertices; i++)
        if (visited[i] == false)
            APUtil(i, visited, disc, low, parent, ap);

    vector<string> res;
    for (int i = 0; i < nVertices; i++)
        if (ap[i]) {
            res.push_back(temp[i]);
        }
    sort(res.begin(), res.end());
    cout << "City map #" << n << ": " << res.size() << " camera(s) found" << endl;
    for (vector<string>::iterator it = res.begin(); it != res.end(); it++) {
        cout << *it << endl;
    }
}

void Graph::clearGraph() {
    nVertices = 0;
    for (int i = 0; i <= MAXV; i++) {
        vertices[i].clear();
    }
}


int main() {

    int nv, ne, src, dst, N = 0;
    string db[MAXV + 1];
    map<string, int> indexer;
    string a, b, line;

    while (in >> nv and nv != 0) {
        Graph g(nv);
        indexer.clear();
        for (int i = 0; i < nv; i++) {
            in >> line;
            db[i] = line;
            indexer[line] = i;
        }
        in >> ne;
        for (int i = 0; i < ne; i++) {
            in >> a >> b;
            src = indexer[a];
            dst = indexer[b];
            g.addEdge(src, dst);
        }

        if (N++) {
            cout << endl;
        }

        g.showArticulationPoints(db, N);
    }

    return 0;
}
