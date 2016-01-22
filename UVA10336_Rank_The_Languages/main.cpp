#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

/*
Accepted: 0.000s
Description: dfs
*/

using namespace std;

#define NALPHA 26
#define ASCII_DIFF 97

typedef struct {
    char c;
    int freq;
} Entry;

bool compare(Entry a, Entry b) {
    if (a.freq < b.freq)
        return false;
    else if (a.freq > b.freq)
        return true;
    else
        return a.c < b.c;
}

void dfs(vector<string> &v, int NROWS, int NCOLS, int row, int col, char currentLang, vector<vector<bool> > &visited) {
    if (row < 0 || col < 0 || row >= NROWS || col >= NCOLS || visited[row][col] || v[row][col] != currentLang)
        return;
    visited[row][col] = true;
    dfs(v, NROWS, NCOLS, row - 1, col, currentLang, visited);
    dfs(v, NROWS, NCOLS, row, col + 1, currentLang, visited);
    dfs(v, NROWS, NCOLS, row + 1, col, currentLang, visited);
    dfs(v, NROWS, NCOLS, row, col - 1, currentLang, visited);
}

int main() {
	int ncases, nrows, ncols, N = 1;
	string line;

	cin >> ncases; getline(cin, line);
	while (ncases--) {
        cin >> nrows >> ncols; getline(cin, line);
        vector<string> v(nrows);
        vector<vector<bool> > visited(nrows, vector<bool>(ncols, false));
        Entry cnt[NALPHA];
        for (int i = 0; i < NALPHA; i++) {
            cnt[i].c = (char) (i + ASCII_DIFF);
            cnt[i].freq = 0;
        }
        for (int i = 0; i < nrows; i++)
            getline(cin, v[i]);
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                if (!visited[i][j]) {
                    cnt[v[i][j] - ASCII_DIFF].freq++;
                    dfs(v, nrows, ncols, i, j, v[i][j], visited);
                }

        sort(cnt, cnt + NALPHA, compare);
        cout << "World #" << N++ << endl;
        for (int i = 0; i < NALPHA; i++) {
            if (cnt[i].freq > 0)
                cout << cnt[i].c << ": " << cnt[i].freq << endl;
        }
	}
    return 0;
}
