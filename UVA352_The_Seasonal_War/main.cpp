#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: dfs, flood fill
*/

using namespace std;

#define MAXN 25

void dfs(vector<string> &v, int NROWS, int NCOLS, int row, int col, bool visited[MAXN][MAXN]) {
    if (row < 0 || col < 0 || row >= NROWS || col >= NCOLS || visited[row][col] || v[row][col] != '1')
        return;
    visited[row][col] = true;
    dfs(v, NROWS, NCOLS, row, col - 1, visited);
    dfs(v, NROWS, NCOLS, row - 1, col - 1, visited);
    dfs(v, NROWS, NCOLS, row - 1, col, visited);
    dfs(v, NROWS, NCOLS, row - 1, col + 1, visited);
    dfs(v, NROWS, NCOLS, row, col + 1, visited);
    dfs(v, NROWS, NCOLS, row + 1, col + 1, visited);
    dfs(v, NROWS, NCOLS, row + 1, col, visited);
    dfs(v, NROWS, NCOLS, row + 1, col - 1, visited);
}

void clearArray(bool visited[MAXN][MAXN]) {
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            visited[i][j] = false;
}

int main() {
	int n, nrows, ncols, N = 1;
	string line;
	bool visited[MAXN][MAXN];

	while (cin >> n) {
        getline(cin, line);
        vector<string> v;
        for (int i = 0; i < n; i++) {
            getline(cin, line);
            v.push_back(line);
        }
        nrows = n;
        ncols = v[0].length();
        clearArray(visited);
        int soln = 0;
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                if (v[i][j] == '1' && !visited[i][j]) {
                    dfs(v, nrows, ncols, i, j, visited);
                    soln++;
                }
        cout << "Image number " << N++ << " contains " << soln << " war eagles." << endl;
	}
    return 0;
}
