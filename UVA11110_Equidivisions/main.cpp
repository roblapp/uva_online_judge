#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>

/*
Accepted: 0.006s
Description: dfs
*/

using namespace std;

int dfs(vector<vector<int> > &v, int nrows, int ncols, int row, int col, int partitionNumber, vector<vector<bool> > &visited) {
    if (row < 0 || col < 0 || row >= nrows || col >= ncols || visited[row][col] || v[row][col] != partitionNumber)
        return 0;
    visited[row][col] = true;
    return 1 + dfs(v, nrows, ncols, row, col - 1, partitionNumber, visited)
            + dfs(v, nrows, ncols, row - 1, col, partitionNumber, visited)
            + dfs(v, nrows, ncols, row, col + 1, partitionNumber, visited)
            + dfs(v, nrows, ncols, row + 1, col, partitionNumber, visited);
}

bool process(vector<vector<int> > &v, vector<vector<bool> > &visited, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (!visited[i][j])
                if (dfs(v, n, n, i, j, v[i][j], visited) != n)
                    return false;
    return true;
}

int main() {
	int n, row, col;
	string line;

	while (cin >> n && n != 0) {
	    getline(cin, line); /* Drain newline */
        vector<vector<int> > v(n, vector<int>(n, n-1));
        vector<vector<bool> > visited(n, vector<bool>(n, false));

        for (int i = 0; i < n - 1; i++) {
            getline(cin, line);
            stringstream ss(line);
            while (ss >> row >> col)
                v[row-1][col-1] = i;
        }
        (process(v, visited, n)) ? cout << "good" << endl : cout << "wrong" << endl;
	}
    return 0;
}
