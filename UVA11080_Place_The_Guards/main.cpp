#include <iostream>
#include <vector>
#include <queue>

/*
Accepted: 0.003s
Description: graphs - coloring/bipartite checking
*/

using namespace std;

#define WHITE 1
#define BLACK -1
#define UNCOLORED 0

struct Entry {
    int nwhites, nblacks;
    Entry() : nwhites(0), nblacks(0) {};
};

bool processEdge(int src, int dst, vector<int> &colors, vector<Entry> &colorCount, int componentNumber) {
    if (colors[src] == colors[dst])
        return false;
    if (colors[dst] != UNCOLORED) /* Don't color already colored vertices again */
        return true;
    colors[dst] = -1*colors[src];
    if (colors[dst] == WHITE)
        colorCount[componentNumber].nwhites++;
    else
        colorCount[componentNumber].nblacks++;
    return true;
}

bool bfs(vector<vector<int> > &graph, int N, int vertex, vector<int> &colors, vector<Entry> &colorCount,
                                      int componentNumber, vector<bool> &disc, vector<bool> &processed) {
    int v;
    queue<int> q;
    q.push(vertex);
    colors[vertex] = WHITE;
    colorCount[componentNumber].nwhites++;
    disc[vertex] = true;

    while (!q.empty()) {
        v = q.front(); q.pop();
        processed[v] = true;
        for (vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++) {
            if (!processed[*it]) {
                if (!processEdge(v, *it, colors, colorCount, componentNumber))
                    return false;
            }
            if (!disc[*it]) {
                disc[*it] = true;
                q.push(*it);
            }
        }
    }
    return true;
}

int process(vector<vector<int> > &graph) {
    int N = (int) graph.size(), ncomponents = 0;
    vector<bool> disc(N, false), processed(N, false);
    vector<int> colors(N, UNCOLORED);
    vector<Entry> colorCount(N);
    for (int i = 0; i < N; i++) {
        if (!disc[i]) {
            if (!bfs(graph, N, i, colors, colorCount, ncomponents, disc, processed))
                return -1;
            ncomponents++;
        }
    }
    int cnt = 0;
    for (int i = 0; i < ncomponents; i++)
        cnt += min(max(1, colorCount[i].nwhites), max(1, colorCount[i].nblacks));
    return cnt;
}

int main() {
	int ncases, nv, ne, src, dst;

	cin >> ncases;
	while (ncases--) {
        cin >> nv >> ne;
        vector<vector<int> > graph(nv);
        for (int i = 0; i < ne; i++) {
            cin >> src >> dst;
            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }
        cout << process(graph) << endl;
	}
    return 0;
}
