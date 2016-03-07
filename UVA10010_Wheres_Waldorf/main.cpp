#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Category: string processing, 2d grid search
Algorithm: 2d grid search algorithm
*/

using namespace std;

bool searchMatrix(vector<string> &v, int nrows, int ncols, string &s, int &solnRow, int &solnCol) {
    const int N = 8;
    int row, col, sindex, len = (int) s.length();
    int rowInc[] = {0, -1, -1, -1, 0, 1, 1, 1};
    int colInc[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            if (tolower(v[i][j]) == tolower(s[0])) {
                for (int k = 0; k < N; k++) {
                    row = i; col = j; sindex = 0;
                    while (row >= 0 and row < nrows and col >= 0 and col < ncols and
                            tolower(v[row][col]) == tolower(s[sindex])) {
                        sindex++;
                        if (sindex == len) {
                            solnRow = i + 1;
                            solnCol = j + 1;
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
	int ncases, nrows, ncols, nkeyWords, solnRow, solnCol, N = 0;
	string line;

	cin >> ncases;
	while (ncases--) {
        cin >> nrows >> ncols;
        vector<string> v;
        for (int i = 0; i < nrows; i++) {
            cin >> line;
            v.push_back(line);
        }
        cin >> nkeyWords;
        if (N++)
            cout << endl;
        for (int i = 0; i < nkeyWords; i++) {
            cin >> line;
            searchMatrix(v, nrows, ncols, line, solnRow, solnCol);
            cout << solnRow << " " << solnCol << endl;
        }
	}
    return 0;
}
