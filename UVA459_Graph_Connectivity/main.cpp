#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

/*
Accepted: 0.000s
Description: bfs, connected components
*/

using namespace std;

#define read cin
#define out cout
#define DIFF 'A'

void bfs(vector<vector<int> > &vg, int src, int parent[]) {
    int vertex;
    queue<int> q;

    parent[src] = src;
    q.push(src);
    while (!q.empty()) {
        vertex = q.front(); q.pop();
        vector<int> neighbors = vg[vertex];
        for (vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
            if (parent[*it] == -1) { /* Not yet visited */
                parent[*it] = src;
                q.push(*it);
            }
        }
    }
}

int solve(vector<vector<int> > &gv, int N) {
    int parent[N];
    for (int i = 0; i < N; i++)
        parent[i] = -1;
    for (int i = 0; i < N; i++)
        if (parent[i] == -1)
            bfs(gv, i, parent);
     sort(parent, parent + N);
     int x = parent[0], cnt = 1;
     for (int i = 1; i < N; i++) {
        if (parent[i] != x) {
            x = parent[i];
            cnt++;
        }
     }
     return cnt;
}

int main() {
	int ncases, N, src, dst, X = 0;
	string line;

	read >> ncases; getline(read, line); getline(read, line);
	while (ncases--) {
        getline(read, line);
        N = line[0] - DIFF + 1;
        vector<vector<int> > gv(N);
        while (getline(read, line) && !line.empty()) {
            src = line[0] - DIFF;
            dst = line[1] - DIFF;
            gv[src].push_back(dst);
            gv[dst].push_back(src);
        }
        if (X++)
            out << endl;
        out << solve(gv, N) << endl;
	}
    return 0;
}
