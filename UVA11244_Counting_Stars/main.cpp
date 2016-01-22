#include <iostream>
#include <vector>

/*
Accepted: 0.009s
Description: 2d grid search
*/

using namespace std;

bool isCandidate(vector<string> &v, int NROWS, int NCOLS, int row, int col) {
    if (row < 0 || col < 0 || row >= NROWS || col >= NCOLS)
        return true;
    return (v[row][col] == '.');
}

int main() {
	int nrows, ncols;
	string line;

	while (cin >> nrows >> ncols && (nrows != 0 || ncols != 0)) {
        getline(cin, line); /* Drain newline */
        vector<string> v(nrows);
        for (int i = 0; i < nrows; i++)
            getline(cin, v[i]);
        int cnt = 0;
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                if (v[i][j] == '*'
                        && isCandidate(v, nrows, ncols, i, j-1) && isCandidate(v, nrows, ncols, i-1, j-1)
                        && isCandidate(v, nrows, ncols, i-1, j) && isCandidate(v, nrows, ncols, i-1, j+1)
                        && isCandidate(v, nrows, ncols, i, j+1) && isCandidate(v, nrows, ncols, i+1, j+1)
                        && isCandidate(v, nrows, ncols, i+1, j) && isCandidate(v, nrows, ncols, i+1, j-1)) {
                            cnt++;
                        }
        cout << cnt << endl;
	}
    return 0;
}
