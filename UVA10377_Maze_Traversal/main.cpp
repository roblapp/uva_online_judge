#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: simulation
*/

using namespace std;

void rot(int &rowInc, int &colInc, bool isRotateRight) {
    int rotateFactor = (isRotateRight) ? 1 : -1;
    if (rowInc == 0) { /* traveling east or west */
        if (colInc == -1) { /* traveling west */
            colInc = 0;
            rowInc = -1*rotateFactor; /* now traveling north */
        } else { /* traveling east */
            colInc = 0;
            rowInc = 1*rotateFactor; /* now traveling south */
        }
    } else { /* traveling north or south */
        if (rowInc == -1) { /* traveling north */
            colInc = 1*rotateFactor; /* traveling west */
            rowInc = 0;
        } else {
            colInc = -1*rotateFactor; /* traveling east */
            rowInc = 0;
        }
    }
}

char getDirection(int rowInc, int colInc) {
    if (rowInc == 0) { /* traveling east or west */
        if (colInc == -1) { /* traveling west */
            return 'W';
        } else { /* traveling east */
            return 'E';
        }
    } else { /* traveling north or south */
        if (rowInc == -1) { /* traveling north */
            return 'N';
        } else {
            return 'S';
        }
    }
}

char dfs(vector<string> &v, int &row, int &col, int rowInc, int colInc, int k, string &dir) {
    if (dir[k] == 'Q')
        return getDirection(rowInc, colInc);
    if (dir[k] == 'R') {
        rot(rowInc, colInc, true);
    } else if (dir[k] == 'L') {
        rot(rowInc, colInc, false);
    } else if (dir[k] == 'F') {
        int tempRow = row + rowInc;
        int tempCol = col + colInc;
        if (tempRow >= 0 && tempRow < (int) v.size() && tempCol >= 0
                && tempCol < (int) v[row].length() && v[tempRow][tempCol] == ' ') {
            row = tempRow; /* only update if successful */
            col = tempCol;
        }
    } else {
        /* invalid command */
    }
    return dfs(v, row, col, rowInc, colInc, k + 1, dir);
}

int main() {
	int ncases, nrows, ncols, startRow, startCol, rowInc, colInc, N = 0;
	string line;

	cin >> ncases;
	while (ncases--) {
        cin >> nrows >> ncols; getline(cin, line); /* Drain newline */
        vector<string> v;
        for (int i = 0; i < nrows; i++) {
            getline(cin, line);
            for (int j = (int) line.length(); j < ncols; j++)
                line += ' ';
            v.push_back(line);
        }
        cin >> startRow >> startCol; getline(cin, line); /* Drain newline */
        string dir;
        while (getline(cin, line) && !line.empty())
            for (int i = 0; line[i]; i++)
                if (!isspace(line[i]))
                    dir += line[i];
        rowInc = -1;
        colInc = 0;
        startRow--;
        startCol--;
        char direction = dfs(v, startRow, startCol, rowInc, colInc, 0, dir);
        if (N++)
            cout << endl;
        cout << startRow + 1 << " " << startCol + 1 << " " << direction << endl;
	}
    return 0;
}
