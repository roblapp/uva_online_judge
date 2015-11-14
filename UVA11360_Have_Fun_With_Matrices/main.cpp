#include <iostream>

/*
Accepted: 0.000s
Description: 2d array processing
*/

#define read cin
#define out cout
#define MAXN 10

using namespace std;

void transpose(int a[MAXN][MAXN], int n) {
    int temp[MAXN][MAXN];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            temp[j][i] = a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = temp[i][j];
}

int main() {
    int ncases, n, m, x, y, N = 1;
    string line;
    int a[MAXN][MAXN];
    read >> ncases; getline(read, line); /* consume newline */
    while (ncases--) {
        read >> n; getline(read, line); /* consume newline */
        for (int i = 0; i < n; i++) {
            getline(read, line);
            for (int j = 0; j < n; j++) {
                a[i][j] = line[j] - '0';
            }
        }
        read >> m; getline(read, line); /* consume newline */
        for (int t = 0; t < m; t++) {
            read >> line;
            if (line == "transpose") {
                transpose(a, n);
            } else if (line == "row") {
                read >> x >> y;
                int temp[n];
                for (int i = 0; i < n; i++) {
                    temp[i] = a[x-1][i];
                }
                for (int i = 0; i < n; i++) {
                    a[x-1][i] = a[y-1][i];
                    a[y-1][i] = temp[i];
                }
            } else if (line == "col") {
                read >> x >> y;
                int temp[n];
                for (int k = 0; k < n; k++) {
                    temp[k] = a[k][x-1];
                }
                for (int k = 0; k < n; k++) {
                    a[k][x-1] = a[k][y-1];
                    a[k][y-1] = temp[k];
                }
            } else if (line == "inc") {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        a[i][j] = (a[i][j] + 1) % 10;
                    }
                }
            } else if (line == "dec") {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        a[i][j] = (a[i][j] + 9) % 10;
                    }
                }
            }
            getline(read, line); /* consume newline */
        }
        out << "Case #" << N++ << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                out << a[i][j];
            }
            out << endl;
        }
        out << endl;
    }
    return 0;
}
