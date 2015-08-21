#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

#define MAXN 35
#define in fp

using namespace std;

void traverse_neighbors(short src, bool mark);

vector<short> graph[MAXN + 1];
bool visited[MAXN + 1];

bool is_solution(short n) {
    for (short i = 1; i <= n; i++) {
        if (!visited[i]) return false;
    }
    return true;
}

void unvisit_neighbors(short src) {
    traverse_neighbors(src, false);
}

void visit_neighbors(short src) {
    traverse_neighbors(src, true);
}

void traverse_neighbors(short src, bool mark) {
    vector<short> temp = graph[src];
    visited[src] = mark;
    for (vector<short>::iterator it = temp.begin(); it != temp.end(); it++) {
        visited[*it] = mark;
    }
}

bool backtrack(short k, short n, short n_stations, short prev_node) {
    if (k == n_stations) {
        return (is_solution(n));
    }

    for (short v = prev_node + 1; v <= n; v++) { /* v iterates through the node to be selected for the station */
        visit_neighbors(v);
        if (backtrack(k + 1, n, n_stations, v)) {
            return true;
        }
        unvisit_neighbors(v);
    }

    return false;
}

void solve(short n) {
    for (short i = 1; i <= n; i++) { /* number of stations to use */
        memset(visited, 0, sizeof(visited));
        if (backtrack(0, n, i, 0)) {
            cout << i << endl;
            return;
        }
    }
}

int main() {

    ifstream fp("test.txt");

    short a, b, src, dst;

    while (in >> a >> b) { /* a holds the highest vertex */
        if (a == 0 && b == 0) break;
        for (short i = 0; i <= MAXN; i++) graph[i].clear();
        for (short i = 0; i < b; i++) {
            in >> src >> dst;
            graph[src].push_back(dst);
            graph[dst].push_back(src);
        }
        solve(a);
    }

    fp.close();

    return 0;
}
