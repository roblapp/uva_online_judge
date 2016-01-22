#include <iostream>
#include <vector>
#include <sstream>

/*
Accepted: 0.006s
Description: dfs/flood fill
Info: 1st submission was 0.059s without optimization
*/

using namespace std;

#define read cin
#define out cout
#define MAXN 100

int dfs(vector<string> &v, int nrows, int ncols, int row, int col, bool visited[MAXN][MAXN]) {
    if (row < 0 || col < 0 || row >= nrows || col >= ncols || visited[row][col] || v[row][col] != 'W')
        return 0;
    visited[row][col] = true;
    return 1 + dfs(v, nrows, ncols, row, col - 1, visited) + dfs(v, nrows, ncols, row - 1, col - 1, visited)
            + dfs(v, nrows, ncols, row - 1, col, visited) + dfs(v, nrows, ncols, row - 1, col + 1, visited)
            + dfs(v, nrows, ncols, row, col + 1, visited) + dfs(v, nrows, ncols, row + 1, col + 1, visited)
            + dfs(v, nrows, ncols, row + 1, col, visited) + dfs(v, nrows, ncols, row + 1, col - 1, visited);
}

void resetArray(bool visited[MAXN][MAXN]) {
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            visited[i][j] = false;
}

int main() {
	int ncases, a, b, N = 0, nrows, ncols, prev;
	string line;
	bool visited[MAXN][MAXN];

	read >> ncases; getline(read, line); getline(read, line);
	while (ncases--) {
        vector<string> v;
        while (getline(read, line) && (line[0] == 'W' || line[0] == 'L'))
           v.push_back(line);
        nrows = (int) v.size();
        ncols = v[0].length();
        if (N++)
            out << endl;
        prev = 0;
        resetArray(visited);
        do {
            stringstream ss(line);
            ss >> a >> b;
            a--; b--;
            if (visited[a][b]) { /* optimization - reuse answer if already visited location */
                /* prev will contain the answer */
            } else {
                resetArray(visited);
                prev = dfs(v, nrows, ncols, a, b, visited);
            }
            out << prev << endl;
        } while (getline(read, line) && !line.empty());
	}
    return 0;
}
