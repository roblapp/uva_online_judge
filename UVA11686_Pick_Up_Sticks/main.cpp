#include <iostream>
#include <vector>
#include <stack>

/*
Accepted: 0.938s
Description: topological sorting
Info: terrible runtime. However, the problem description said that the graphs
can have between 1 and 1,000,000 vertices and or edges. Also, most of the
people who solved this problem had much higher run times. At the time of AC
I was 403/1809 which is still better than most.
*/

using namespace std;

bool dfs(vector<vector<int> > &graph, vector<bool> &discovered, vector<bool> &processed, int vertex, stack<int> &soln) {
    discovered[vertex] = true;
    for (vector<int>::iterator it = graph[vertex].begin(); it != graph[vertex].end(); it++) {
        if (discovered[*it] && !processed[*it]) {/* A cycle was found */
            return false; /* No topological sort possible */
        } else if (!processed[*it]) {
            if (!dfs(graph, discovered, processed, *it, soln))
                return false;
        }
    }
    processed[vertex] = true;
    soln.push(vertex);
    return true;
}

bool topologicalSort(vector<vector<int> > &graph, stack<int> &soln) {
    int n = (int) graph.size();
    bool isPossible = true;
    vector<bool> discovered(n, false);
    vector<bool> processed(n, false);
    for (int i = 0; i < n && isPossible; i++)
        if (!discovered[i])
            isPossible = dfs(graph, discovered, processed, i, soln);
    return isPossible;
}

int main() {
	int n, m, src, dst;

	while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<vector<int> > graph(n);
        for (int i = 0; i < m; i++) {
            cin >> src >> dst;
            graph[src-1].push_back(dst-1);
        }
        stack<int> soln;
        if (topologicalSort(graph, soln)) {
            while (!soln.empty()) {
                cout << soln.top() + 1 << endl;
                soln.pop();
            }
        } else
            cout << "IMPOSSIBLE" << endl;
	}
    return 0;
}
