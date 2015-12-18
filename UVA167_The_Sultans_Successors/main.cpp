#include <iostream>
#include <vector>
#include <iomanip>

/*
Accepted: 0.000s
Description: complete search, backtracking
*/

using namespace std;

#define read cin

typedef struct {
    int x, y;
}  point;

void process(vector<vector<bool> > &m, vector<point> &v) {
    point p;
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (m[row][col]) {
                p.x = row;
                p.y = col;
                v.push_back(p);
            }
        }
    }
}

bool isValidMove(vector<vector<bool> > &m, int row, int col) {
    int tempRow = row;
    int tempCol = col;
    while (row > 0 && col > 0) {
        row--;
        col--;
    }

    while (row < 8 && col < 8)
        if (m[row++][col++]) return false;

    row = tempRow;
    col = tempCol; /* restore */
    while (row > 0 && col < 7) {
        row--;
        col++;
    }
    while (row < 8 && col >= 0) {
        if (m[row++][col--]) return false;
    }
    col = tempCol;
    for (int i = 0; i < 8; i++)
        if (m[i][col]) return false;

    return true;
}

void backtrack(vector<vector<bool> > &m, int row, vector<point> &v) {
    if (row >= 8) {
        process(m, v);
        return;
    }

    for (int col = 0; col < 8; col++) {
        if (isValidMove(m, row, col)) {
            m[row][col] = true;
            backtrack(m, row + 1, v);
            m[row][col] = false;
        }
    }
}

void solve8Queens(vector<vector<bool> > &m, vector<point> &v) {
    backtrack(m, 0, v);
}

int main() {
    int ncases, x, solnLen,  maxSum, tempSum;
    vector<vector<bool> > m(8, vector<bool>(8));
    vector<vector<int> > board(8, vector<int>(8));
    vector<point> v;
    point p;

    read >> ncases;
    solve8Queens(m, v);
    solnLen = (int) v.size();

    while (ncases--) {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                read >> x;
                board[i][j] = x;
            }
        }
        maxSum = 0;
        for (int i = 0; i < solnLen; i += 8) {
            tempSum = 0;
            for (int j = 0; j < 8; j++) {
                p = v[i + j];
                tempSum += board[p.x][p.y];
            }
            maxSum = max(maxSum, tempSum);
        }
        cout << setw(5) << maxSum << endl;
    }
    return 0;
}
