#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

/* ACCEPTED 0.016s */
/*
Algorithm:

Ad hoc
*/

#define ALPHA 26
#define DIFF 65
#define MAXL 100

using namespace std;

int soundex_code(char c) {
    if (c == 'B' or c == 'F' or c == 'P' or c == 'V') return 1;
    if (c == 'C' or c == 'G' or c == 'J' or c == 'K' or c == 'Q' or c == 'S' or c == 'X' or c == 'Z') return 2;
    if (c == 'D' or c == 'T') return 3;
    if (c == 'L') return 4;
    if (c == 'M' or c == 'N') return 5;
    if (c == 'R') return 6;
    return (-1);
}

int main() {

    char line[MAXL];
    int code, pcode;

    while (fgets(line, MAXL, stdin)) {
        int len = strlen(line);
        pcode = -2;
        for (int i = 0; i < len; i++) {
            code = soundex_code(line[i]);
            if (code != pcode and code > -1) {
                cout << code;
            }
            pcode = code;
        }
        cout << endl;
    }

    return 0;
}
