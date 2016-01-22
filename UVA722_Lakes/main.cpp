#include <iostream>
#include <vector>

/*
Accepted: 0.019s
Description: dfs
*/

using namespace std;

int dfs(vector<string> &v, int NROWS, int NCOLS, int row, int col, vector<vector<bool> > &visited) {
    if (row < 0 || col < 0 || row >= NROWS || col >= NCOLS || visited[row][col] || v[row][col] != '0')
        return 0;
    visited[row][col] = true;
    return 1 + dfs(v, NROWS, NCOLS, row - 1, col, visited)
            + dfs(v, NROWS, NCOLS, row, col + 1, visited)
            + dfs(v, NROWS, NCOLS, row + 1, col, visited)
            + dfs(v, NROWS, NCOLS, row, col - 1, visited);
}

int main() {
	int ncases, row, col, nrows, ncols, N = 0;
	string line;

	cin >> ncases;
	while (ncases--) {
        vector<string> v;
        cin >> row >> col; getline(cin, line); /* Drain newline */
        while (getline(cin, line) && !line.empty()) {
            v.push_back(line);
        }
        nrows = (int) v.size();
        ncols = v[0].length();
        vector<vector<bool> > visited(nrows, vector<bool>(ncols, false));
        if (N++)
            cout << endl;
        cout << dfs(v, nrows, ncols, row - 1, col - 1, visited) << endl;
	}
    return 0;
}
