#include <iostream>
#include <vector>
#include <sstream>

/*
Accepted: 0.009s
Description: graphs - articulation points
Info: I don't remember where I got this algorithm from but it has worked for
more than 1 UVA problem now. I understand this algorithm is based on DFS but
I didn't take the time to do a few examples by hand to really understand it.
I know the cases in which a vertex is an articulation point, but I don't see
immediately how this algorithm determines each of the cases.
*/

using namespace std;

void dfs(vector<vector<int> > &graph, int vertex, int time, vector<bool> &visited, vector<int> &disc, vector<int> &low,
         vector<int> &parent, vector<bool> &articulationPoints) {

    int children = 0;

    visited[vertex] = true;
    disc[vertex] = low[vertex] = ++time;
    for (vector<int>::iterator it = graph[vertex].begin(); it != graph[vertex].end(); it++) {
        int neighbor = *it;
        if (!visited[neighbor]) {
            children++;
            parent[neighbor] = vertex;
            dfs(graph, neighbor, time, visited, disc, low, parent, articulationPoints);
            low[vertex] = min(low[vertex], low[neighbor]); /* earliest reachable ancestor */

            /* if a root node with more than 1 child then articulation */
            if (parent[vertex] == -1 && children > 1)
                articulationPoints[vertex] = true;

            /* if not a root node and ? */
            if (parent[vertex] != -1 && low[neighbor] >= disc[vertex])
                articulationPoints[vertex] = true;
        } else if (neighbor != parent[vertex])
            low[vertex] = min(low[vertex], disc[neighbor]);
    }
}

int countArticulationPoints(vector<vector<int> > &graph, int N) {
    vector<bool> visited(N, false), isArticulationPoint(N, false);
    vector<int> discovered(N, 0), low(N, 0), parent(N, -1);
    int cnt = 0;

    for (int i = 0; i < N; i++)
        if (!discovered[i])
            dfs(graph, i, 0, visited, discovered, low, parent, isArticulationPoint);
    for (int i = 0; i < N; i++)
        if (isArticulationPoint[i])
            cnt++;
    return cnt;
}

int main() {
    int n, src, dst;
    string line;

    while (cin >> n && n != 0) {
        getline(cin, line); /* Drain newline */
        vector<vector<int> > graph(n);
        while (1) {
            getline(cin, line);
            stringstream ss(line);
            ss >> src;
            if (src == 0)
                break;
            while (ss >> dst) {
                graph[src-1].push_back(dst-1);
                graph[dst-1].push_back(src-1);
            }
        }
        cout << countArticulationPoints(graph, n) << endl;
    }
    return 0;
}
