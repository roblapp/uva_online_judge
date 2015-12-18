#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//#define read cin

int dfs(vector<vector<int> > &g, int vertex, int n, vector<vector<bool> > &disc) {

    vector<int> neighbors = g[vertex];
    for (vector<int>::iterator it = neighbors.begin(); it != neighbors.end(); it++) {
        if (!disc[vertex][*it]) {

        } else {

        }
    }
    return 0;
}

int shortestPath(vector<vector<int> > &g, int n) {
    vector<vector<bool> > isUsed(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {

    }

    return 0;
}

int main() {
    ifstream read("test.txt");
    int n, m, src, dst;

    while (read >> n >> m && (n != 0 || m != 0)) {
        vector<vector<int> > g(n);
        for (int i = 0; i < m; i++) {
            read >> src >> dst;
            g[src].push_back(dst);
            g[dst].push_back(src);
        }
        shortestPath(g, n);
    }


    read.close();
    return 0;
}
