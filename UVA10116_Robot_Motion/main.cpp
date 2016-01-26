#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description:
*/

using namespace std;

struct Entry {
    int rowInc, colInc, k;
};

void traverse(vector<vector<Entry> > &v, int nrows, int ncols, int startCol, int &nsteps, int &loopSize) {
    int currentRow = 0;
    int currentCol = startCol;
    int tempRow, tempCol;

    nsteps = 0;
    loopSize = 0;
    while (currentRow >= 0 && currentRow < nrows && currentCol >= 0 && currentCol < ncols) {
        ++nsteps;
        if (v[currentRow][currentCol].k == 0) {
            v[currentRow][currentCol].k = nsteps;
            tempRow = currentRow + v[currentRow][currentCol].rowInc;
            tempCol = currentCol + v[currentRow][currentCol].colInc;
            currentRow = tempRow;
            currentCol = tempCol;
        } else {
            loopSize = nsteps - v[currentRow][currentCol].k;
            nsteps -= loopSize + 1;
            return;
        }
    }
}

int main() {
	int nrows, ncols, startCol, nsteps, loopSize;
	string line;

	while (cin >> nrows >> ncols >> startCol && (nrows != 0 || ncols != 0 || startCol != 0)) {
        getline(cin, line); /* Drain newline */
        vector<vector<Entry> > v;
        Entry e;
        for (int i = 0; i < nrows; i++) {
            getline(cin, line);
            vector<Entry> vTemp;
            for (int j = 0; line[j]; j++) {
                if (line[j] == 'N') {
                    e.rowInc = -1;
                    e.colInc = 0;
                } else if (line[j] == 'S') {
                    e.rowInc = 1;
                    e.colInc = 0;
                } else if (line[j] == 'E') {
                    e.rowInc = 0;
                    e.colInc = 1;
                } else {
                    e.rowInc = 0;
                    e.colInc = -1;
                }
                e.k = 0;
                vTemp.push_back(e);
            }
            v.push_back(vTemp);
        }
        traverse(v, nrows, ncols, startCol - 1, nsteps, loopSize);
        if (loopSize == 0)
            cout << nsteps << " step(s) to exit" << endl;
        else
            cout << nsteps << " step(s) before a loop of " << loopSize << " step(s)" << endl;
	}
    return 0;
}
