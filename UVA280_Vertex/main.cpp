#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

void bfs(vector<vector<int> > &gv, int startVertex, bool visited[]) {
    int currentVertex;
    queue<int> q;
    q.push(startVertex);

    while (!q.empty()) { /* While there are elements to be processed */
        currentVertex = q.front(); q.pop();
        vector<int> neighbors = gv[currentVertex];
        for (vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) { /* Check for unvisited neighbors */
            if (!visited[*it]) {
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}

int main() {
	int n, x, temp;

	while (cin >> n && n != 0) {
        vector<vector<int> > gv(n + 1, vector<int>());
        while (cin >> x && x != 0) {
            vector<int> v;
            while (cin >> temp && temp != 0)
                v.push_back(temp);
            gv[x] = v;
        }

        cin >> x;
        bool visited[n + 1]; /* Declare bool array for BFS */
        int cnt;
        while (x--) {
            cin >> temp;
            memset(visited, false, sizeof(visited));
            bfs(gv, temp, visited);
            cnt = 0; /* Count the number of vertices unreachable from a start vertex */
            vector<int> uv; /* list of unreachable vertices */
            for (int i = 1; i <= n; i++)
                if (!visited[i]) {
                    cnt++;
                    uv.push_back(i);
                }
            cout << cnt;
            for (int i = 0; i < cnt; i++)
                cout << " " << uv[i];
            cout << endl;
        }
	}
    return 0;
}
