#include <iostream>
#include <vector>

/*
Accepted: 0.162s
Category: graphs
Algorithm: dfs with cycle checking - O(N)
*/

using namespace std;

int dfs(vector<int> &graph, int vertex, vector<bool> &disc, vector<bool> &proc, vector<int> &nreachable, int k, bool &cycleFound) {

    if (proc[vertex]) { /* will of course be discovered */
        return nreachable[vertex];
    }
    if (disc[vertex]) { /* discovered, but NOT processed, we have a cycle */
        cycleFound = true;
        return k; /* Return the size of the cycle */
    }
    disc[vertex] = true;
    nreachable[vertex] = dfs(graph, graph[vertex], disc, proc, nreachable, k + 1, cycleFound);
    if (!cycleFound)
        nreachable[vertex]++;
    proc[vertex] = true;
    return nreachable[vertex];
}

int main() {
	int ncases, nv, src, dst, N = 1;

	cin >> ncases;
	while (ncases--) {
        cin >> nv;
        vector<int> graph(nv), nreachable(nv, 0);
        vector<bool> disc(nv, false), proc(nv, false);
        for (int i = 0; i < nv; i++) {
            cin >> src >> dst;
            graph[src-1] = dst-1;
        }
        int vsoln = -1, solnmax = -1, temp;
        bool cycleFound;
        for (int i = 0; i < nv; i++) {
            if (!proc[i]) {
                cycleFound = false;
                if ((temp = dfs(graph, i, disc, proc, nreachable, 0, cycleFound)) > solnmax) {
                    solnmax = temp;
                    vsoln = i;
                }
            }
        }
        cout << "Case " << N++ << ": " << vsoln + 1 << endl;
	}
    return 0;
}
