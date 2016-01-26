#include <iostream>
#include <vector>

/*
Accepted: 0.013s
Description: dfs
*/

using namespace std;

void dfs(vector<string> &v, int NROWS, int NCOLS, int row, int col, vector<vector<bool> > &visited) {
    if (row < 0 || col < 0 || row >= NROWS || col >= NCOLS || visited[row][col] || v[row][col] == '.')
        return;
    visited[row][col] = true;
    dfs(v, NROWS, NCOLS, row - 1, col, visited);
    dfs(v, NROWS, NCOLS, row, col + 1, visited);
    dfs(v, NROWS, NCOLS, row + 1, col, visited);
    dfs(v, NROWS, NCOLS, row, col - 1, visited);
}

int main() {
	int ncases, n, N = 1;
	string line;

	cin >> ncases;
	while (ncases--) {
        cin >> n; getline(cin, line); /* Drain newline */
        vector<string> v;
        vector<vector<bool> > visited(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            v.push_back(line);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!visited[i][j] && v[i][j] == 'x') {
                    dfs(v, n, n, i, j, visited);
                    cnt++;
                }
        cout << "Case " << N++ << ": " << cnt << endl;
	}
    return 0;
}
