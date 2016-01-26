#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

/*
Accepted: 0.046s
Description: bfs, connected components
Info: Alternatively, I could have used a union-find.
*/

using namespace std;

int bfs(vector<vector<int> > &graph, int n, int start, bool visited[]) {
    if (visited[start])
        return 0;
    int vertex, cnt = 0;
    queue<int> q;

    visited[start] = true;
    q.push(start);
    while (!q.empty()) {
        vertex = q.front(); q.pop();
        cnt++;
        vector<int> neighbors = graph[vertex];
        for (vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
            if (!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
    return cnt;
}

int main() {
	int ncases, n, m, l, src, dst, start;

	cin >> ncases;
	while (ncases--) {
        cin >> n >> m >> l;
        vector<vector<int> > graph(n);
        for (int i = 0; i < m; i++) {
            cin >> src >> dst;
            graph[src-1].push_back(dst-1);
        }
        int total = 0;
        bool visited[n];
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < l; i++) {
            cin >> start;
            total += bfs(graph, n, start-1, visited);
        }
        cout << total << endl;
	}
    return 0;
}
