#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: complete search - backtracking
*/

using namespace std;

#define read cin

void dfs(vector<vector<int> > &g, int v, vector<vector<bool> > &isUsed, int sum, int &maxPath) {
    int vdst;
    maxPath = max(maxPath, sum);
    vector<int> neighbors = g[v];
    for (int i = 0, len = (int) neighbors.size(); i < len; i++) {
        vdst = neighbors[i];
        if (!isUsed[v][vdst] && !isUsed[vdst][v]) {
            isUsed[v][vdst] = isUsed[vdst][v] = true;
            dfs(g, vdst, isUsed, sum + 1, maxPath);
            isUsed[v][vdst] = isUsed[vdst][v] = false;
        }
    }
}

int longestPath(vector<vector<int> > &g, int n) {
    int maxPath = 0;
    for (int i = 0; i < n; i++) {
        vector<vector<bool> > isUsed(n, vector<bool>(n, false));
        dfs(g, i, isUsed, 0, maxPath);
    }
    return maxPath;
}

int main() {
    int n, m, src, dst;

    while (read >> n >> m && (n != 0 || m != 0)) {
        vector<vector<int> > g(n);
        for (int i = 0; i < m; i++) {
            read >> src >> dst;
            g[src].push_back(dst);
            g[dst].push_back(src);
        }
        cout << longestPath(g, n) << endl;
    }
    return 0;
}
