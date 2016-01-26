#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: dfs
*/

using namespace std;

int dfs(vector<string> &v, int NROWS, int NCOLS, int row, int col, vector<vector<bool> > &visited) {
    if (row < 0 || col < 0 || row >= NROWS || col >= NCOLS || visited[row][col] || v[row][col] != '1')
        return 0;
    visited[row][col] = true;
    return 1 + dfs(v, NROWS, NCOLS, row, col - 1, visited)
            + dfs(v, NROWS, NCOLS, row - 1, col - 1, visited)
            + dfs(v, NROWS, NCOLS, row - 1, col, visited)
            + dfs(v, NROWS, NCOLS, row - 1, col + 1, visited)
            + dfs(v, NROWS, NCOLS, row, col + 1, visited)
            + dfs(v, NROWS, NCOLS, row + 1, col + 1, visited)
            + dfs(v, NROWS, NCOLS, row + 1, col, visited)
            + dfs(v, NROWS, NCOLS, row + 1, col - 1, visited);
}

int main() {
	int ncases, nrows, ncols, tempMax, N = 0;
	string line;

	cin >> ncases; getline(cin, line); getline(cin, line); /* Drain newline */
	while (ncases--) {
	    vector<string> v;
        while (getline(cin, line) && !line.empty())
            v.push_back(line);
        nrows = (int) v.size();
        ncols = v[0].length();
        vector<vector<bool> > visited(nrows, vector<bool>(ncols, false));
        tempMax = 0;
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                if (!visited[i][j] && v[i][j] == '1')
                    tempMax = max(tempMax, dfs(v, nrows, ncols, i, j, visited));
        if (N++)
            cout << endl;
        cout << tempMax << endl;
	}
    return 0;
}
