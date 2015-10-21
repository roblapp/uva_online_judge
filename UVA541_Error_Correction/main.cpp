#include <iostream>

/*
Accepted: 0.003s
Description: ad-hoc
*/

#define MAXN 100
#define read cin

using namespace std;

int main() {
    int i, j, x, temp, ner, nec, nor, noc, n;
    int row, col;
    bool m[MAXN][MAXN];
    while (read >> n and n != 0) {
        ner = nec = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                read >> x;
                m[i][j] = x;
            }
        }
        for (i = 0; i < n; i++) {
            temp = 0;
            for (j = 0; j < n; j++) {
                if (m[i][j]) {
                    temp++;
                }
            }
            if (temp % 2 == 0) {
                ner++;
            } else {
                row = i + 1;
            }
        }
        for (i = 0; i < n; i++) {
            temp = 0;
            for (j = 0; j < n; j++) {
                if (m[j][i]) {
                    temp++;
                }
            }
            if (temp % 2 == 0) {
                nec++;
            } else {
                col = i + 1;
            }
        }
        nor = n - ner;
        noc = n - nec;
        if (nor == noc && nor == 0) {
            cout << "OK" << endl;
        } else if (nor == noc && nor == 1) {
            cout << "Change bit (" << row << "," << col << ")" << endl;
        } else {
            cout << "Corrupt" << endl;
        }
    }
    return 0;
}
