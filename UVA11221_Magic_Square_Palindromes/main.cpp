#include <iostream>
#include <cmath>
#include <algorithm>

/*
Accepted: 0.006s
Description: ad-hoc
*/

#define read cin

using namespace std;

bool isSquare(int x) {
    for (int i = 1; i <= 100; i++)
        if (i*i == x) return true;
    return false;
}

void createInverted(string &s, int n, string &inverted) {
    int row, col;
    for (col = 0; col < n; col++) {
        for (row = 0; row < n; row++) {
            inverted += s[col + row*n];
        }
    }
}

int main() {
    int i, len, ncases, cnt, n, N = 1;
    string line, tempLine, inverted, rTempLine, rInverted;
    read >> ncases; getline(read, line);
    while (ncases--) {
        getline(read, line);
        tempLine = "";
        cnt = 0;
        for (i = 0, len = line.length(); i < len; i++) {
            if (isalpha(line[i])) {
                tempLine += line[i];
                cnt++;
            }
        }
        cout << "Case #" << N++ << ":" << endl;
        if (!isSquare(cnt)) {
            cout << "No magic :(" << endl;
        } else {
            n = sqrt(cnt);
            inverted = "";
            rTempLine = tempLine;
            reverse(rTempLine.begin(), rTempLine.end());
            createInverted(tempLine, n, inverted);
            rInverted = inverted;
            reverse(rInverted.begin(), rInverted.end());
            if (tempLine == rTempLine and inverted == rInverted and rTempLine == inverted)
                cout << n << endl;
            else
                cout << "No magic :(" << endl;
        }
    }
    return 0;
}
