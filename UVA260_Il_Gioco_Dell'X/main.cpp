#include <iostream>
#include <vector>
#include <cstring>

/*
Accepted: 0.033s
Description: dfs
*/

using namespace std;

#define MAXN 200

bool dfs(vector<string> &v, int N, int row, int col, bool visited[MAXN][MAXN]) {
    if (row < 0 || col < 0 || row >= N || col >= N || visited[row][col] || v[row][col] != 'b')
        return false;
    if (row == N - 1)
        return true;
    visited[row][col] = true;
    return dfs(v, N, row - 1, col - 1, visited) || dfs(v, N, row - 1, col, visited)
            || dfs(v, N, row, col - 1, visited) || dfs(v, N, row, col + 1, visited)
            || dfs(v, N, row + 1, col, visited) || dfs(v, N, row + 1, col + 1, visited);
}

void clearArray(bool visited[MAXN][MAXN]) {
    for (int i = 0; i < MAXN; i++)
        memset(visited[i], false, sizeof(visited[i]));
}

int main() {
	int n, N = 1;
	string line;
	bool visited[MAXN][MAXN];

	while (cin >> n && n != 0) {
        getline(cin, line); /* Drain newline */
        vector<string> v(n);
        for (int i = 0; i < n; i++)
            getline(cin, v[i]);
        clearArray(visited);
        bool blackWon = false;
        for (int i = 0; i < n && !blackWon; i++)
            if (v[0][i] == 'b' && !visited[0][i] && dfs(v, n, 0, i, visited))
                blackWon = true;
        (blackWon) ? cout << N++ << " B" << endl : cout << N++ << " W" << endl;
	}
    return 0;
}
