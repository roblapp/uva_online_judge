#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Category: string processing, string matching (2D grid)
Algorithm: 2D grid search
Info: exact same problem as UVa 10010 Where's Waldorf? except
with this problem words cannot be backwards in the verticle
position.
*/

using namespace std;

bool searchMatrix(vector<string> &v, int nrows, int ncols, string &s, int &startRow, int &startCol, int &endRow, int &endCol) {
    const int N = 7;
    int row, col, sindex, len = (int) s.length();
    int rowInc[] = {0, -1, -1, 0, 1, 1, 1};
    int colInc[] = {-1, -1, 1, 1, 1, 0, -1};

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (v[i][j] == s[0]) {
                for (int k = 0; k < N; k++) {
                    row = i; col = j; sindex = 0;
                    while (row >= 0 and row < nrows and col >= 0 and col < ncols and
                            v[row][col] == s[sindex]) {
                        sindex++;
                        if (sindex == len) {
                            startRow = i + 1;
                            startCol = j + 1;
                            endRow = row + 1;
                            endCol = col + 1;
                            return true;
                        }
                        row += rowInc[k];
                        col += colInc[k];
                    }
                }
            }
        }
    }
    return false;
}

int main() {
	int n, sr, sc, er, ec;
	string line;
	vector<string> v;

	cin >> n;
	for (int i = 0; i < n; i++) {
        cin >> line;
        v.push_back(line);
    }
    while (cin >> line and line != "0") {
        if (searchMatrix(v, n, n, line, sr, sc, er, ec))
            cout << sr << "," << sc << " " << er << "," << ec << endl;
        else
            cout << "Not found" << endl;
    }
    return 0;
}
