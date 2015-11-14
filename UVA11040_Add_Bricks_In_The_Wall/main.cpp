#include <iostream>

/*
Accepted: 0.000s
Description: 2d array processing
*/

#define read cin
#define MAXN 10

using namespace std;

void initMatrix(int a[MAXN][MAXN]) {
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            a[i][j] = 0;
}

void showMatrix(int a[MAXN][MAXN]) {
    for (int i = 1; i < MAXN; i++) {
        for (int j = 1; j <= i; j++) {
            (j > 1) ? cout << " " << a[i][j] : cout << a[i][j];
        }
        cout << endl;
    }
}

void solveTriangle(int a[MAXN][MAXN], int row, int col) {
    if (row > 7) return;
    int temp = (a[row][col] - a[row+2][col] - a[row+2][col+2]) >> 1;
    a[row+2][col+1] = temp;
    a[row+1][col] = a[row+2][col] + temp;
    a[row+1][col+1] = a[row+2][col+2] + temp;
    (row == col) ? solveTriangle(a, row + 2, 1) : solveTriangle(a, row, col + 2);
}

int main() {
    int ncases, x;
    int a[MAXN][MAXN];
    read >> ncases;
    while (ncases--) {
        initMatrix(a);
        for (int i = 1; i <= 9; i+=2) {
            for (int j = 1; j <= i; j+=2) {
                read >> x;
                a[i][j] = x;
            }
        }
        solveTriangle(a, 1, 1);
        showMatrix(a);
    }
    return 0;
}
