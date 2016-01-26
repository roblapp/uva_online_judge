#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <sstream>
#include <iomanip>

/*
Accepted: 0.045s
Description: dfs
*/

using namespace std;

void dfs(vector<string> &v, int NROWS, int NCOLS, int row, int col, char currentSpecies, int k, vector<vector<int> > &soln) {
    if (row < 0 || col < 0 || row >= NROWS || col >= NCOLS || soln[row][col] > 0 || v[row][col] != currentSpecies)
        return;
    soln[row][col] = k;
    dfs(v, NROWS, NCOLS, row, col - 1, currentSpecies, k, soln);
    dfs(v, NROWS, NCOLS, row - 1, col - 1, currentSpecies, k, soln);
    dfs(v, NROWS, NCOLS, row - 1, col, currentSpecies, k, soln);
    dfs(v, NROWS, NCOLS, row - 1, col + 1, currentSpecies, k, soln);
    dfs(v, NROWS, NCOLS, row, col + 1, currentSpecies, k, soln);
    dfs(v, NROWS, NCOLS, row + 1, col + 1, currentSpecies, k, soln);
    dfs(v, NROWS, NCOLS, row + 1, col, currentSpecies, k, soln);
    dfs(v, NROWS, NCOLS, row + 1, col - 1, currentSpecies, k, soln);
}

int main() {
	int index, nrows, ncols, k, tempMax;
	string line;

	while (1) {
        vector<string> v;
        while (getline(cin, line) && line != "%") {
            index = 0;
            stringstream ss("");
            while (line[index]) {
                if (isalpha(line[index]))
                    ss << line[index];
                index++;
            }
            v.push_back(ss.str());
        }
        nrows = (int) v.size();
        ncols = v[0].length();
        k = 1;

        vector<vector<int> > soln(nrows, vector<int>(ncols, 0));
        for (int i = 0; i < nrows; i++)
            for (int j = 0; j < ncols; j++)
                if (soln[i][j] == 0)/* If not yet visited */
                    dfs(v, nrows, ncols, i, j, v[i][j], k++, soln);
        int nspaces[ncols];
        memset(nspaces, 0, sizeof(nspaces));
        for (int j = 0; j < ncols; j++) {
            tempMax = 0;
            for (int i = 0; i < nrows; i++) {
                if (soln[i][j] > tempMax)
                    tempMax = soln[i][j];
            }
            nspaces[j] = (int) (log10(tempMax) + 1);
        }

        for (int i = 0; i < nrows; i++) {
            for (int j = 0; j < ncols; j++)
                (j > 0) ? cout << setw(1 + nspaces[j]) << soln[i][j] : cout << setw(nspaces[j]) << soln[i][j];
            cout << endl;
        }
        cout << "%" << endl;
        if (line != "%")
            break;
	}
    return 0;
}
