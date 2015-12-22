#include <iostream>
#include <vector>

/*
Accepted: 0.095s
Description: complete search - backtracking
*/

using namespace std;

#define read cin

void process(vector<int> &walk) {
    int N = (int) walk.size();
    cout << "(";
    for (int i = 0; i < N; i++)
        (i > 0) ? cout << "," << walk[i] + 1 : cout << walk[i] + 1;
    cout << ")" << endl;
}

void dfsHelper(vector<vector<bool> > &g, int currentVertex, int currentWalkLength, int goalWalkLength,
                vector<int> &walk, bool used[], int &nsolutions) {
    if (currentWalkLength >= goalWalkLength) {
        nsolutions++;
        process(walk);
        return;
    }

    int N = (int) g.size();
    vector<bool> neighbors = g[currentVertex];
    for (int i = 0; i < N; i++) {
        if (i != currentVertex && neighbors[i] && !used[i]) {
            used[i] = true;
            walk.push_back(i);
            dfsHelper(g, i, currentWalkLength + 1, goalWalkLength, walk, used, nsolutions);
            walk.pop_back();
            used[i] = false;
        }
    }
}

int dfs(vector<vector<bool> > &g, int goalWalkLength) {
    int N = (int) g.size(), nsolutions = 0;
    bool used[N];
    vector<int> walk;
    for (int i = 0; i < N; i++)
        used[i] = false;
    walk.push_back(0);
    used[0] = true;
    dfsHelper(g, 0, 0, goalWalkLength, walk, used, nsolutions);
    return nsolutions;
}

int main() {
    int numNodes, n, x;
    bool first = true;

    do {
        read >> numNodes >> n;
        if (!first)
            cout << endl;
        first = false;
        vector<vector<bool> > g(numNodes);
        for (int i = 0; i < numNodes; i++) {
            for (int j = 0; j < numNodes; j++) {
                read >> x;
                g[i].push_back(x);
            }
        }
        x = dfs(g, n);
        if (x == 0)
            cout << "no walk of length " << n << endl;
    } while (read >> x && x < 0);

    return 0;
}
