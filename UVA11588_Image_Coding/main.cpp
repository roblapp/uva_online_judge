#include <iostream>
#include <string>

/*
Accepted: 0.000s
Description: ad-hoc
*/

#define read cin
#define NALPHA 26
#define DIFF 'A'

using namespace std;

int main() {
    string line;
    int a[NALPHA];
    int i, j, k, ncases, rows, cols, ip, nip, m, cnt;
    read >> ncases;
    for (k = 1; k <= ncases; k++) {
        for (i = 0; i < NALPHA; i++) a[i] = 0;
        read >> rows >> cols >> ip >> nip; getline(read, line);
        for (i = 0; i < rows; i++) {
            getline(read, line);
            for (j = 0; j < cols; j++) {
                a[line[j]-DIFF]++;
            }
        }
        m = cnt = 0;
        for (i = 0; i < NALPHA; i++) {
            if (a[i] > m) {
                m = a[i];
                cnt = 1;
            } else if (a[i] == m) {
                cnt++;
            }
        }
        cout << "Case " << k << ": " << (m*cnt*ip + (rows*cols - m*cnt)*nip) << endl;
    }
    return 0;
}
