#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.009s
Description: dfs
*/

using namespace std;

#define NALPHA 26
#define ASCII_DIFF 65

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

int dfs(vector<string> &v, int NROWS, int NCOLS, int row, int col, char currentLang, vector<vector<bool> > &visited) {
    if (row < 0 || col < 0 || row >= NROWS || col >= NCOLS || visited[row][col] || v[row][col] != currentLang)
        return 0;
    visited[row][col] = true;
    return 1 + dfs(v, NROWS, NCOLS, row - 1, col, currentLang, visited)
            + dfs(v, NROWS, NCOLS, row, col + 1, currentLang, visited)
            + dfs(v, NROWS, NCOLS, row + 1, col, currentLang, visited)
            + dfs(v, NROWS, NCOLS, row, col - 1, currentLang, visited);
}

int main() {
	int nrows, ncols, N = 1;
	string line;

	while (cin >> nrows >> ncols && (nrows != 0 || ncols != 0)) {
        getline(cin, line); /* Drain newline */
        vector<string> v(nrows);
        vector<vector<bool> > visited(nrows, vector<bool>(ncols, false));
        vector<vector<int> > freq(NALPHA);
        vector<Entry> soln;
        for (int i = 0; i < nrows; i++)
            getline(cin, v[i]);
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                if (!visited[i][j] && v[i][j] != '.')
                    freq[v[i][j] - ASCII_DIFF].push_back(dfs(v, nrows, ncols, i, j, v[i][j], visited));
        Entry e;
        for (int i = 0; i < NALPHA; i++) {
            if (freq[i].size() > 0) {
                e.c = (char)(i + ASCII_DIFF);
                for (int j = 0; j < (int) freq[i].size(); j++) {
                    e.freq = freq[i][j];
                    soln.push_back(e);
                }
            }
        }
        sort(soln.begin(), soln.end(), compare);
        cout << "Problem " << N++ << ":" << endl;
        for (int i = 0; i < (int) soln.size(); i++)
            cout << soln[i].c << " " << soln[i].freq << endl;
	}
    return 0;
}
