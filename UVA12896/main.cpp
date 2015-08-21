#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cstring>

#define MAXN 101

using namespace std;

int main() {
    char a[10][4] = {
                {' '},
                {'.', ',', '?', '\"'},
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
                };

    int ni[MAXN];
    int pi[MAXN];

    int ncases, nkeys, row, col;

    cin >> ncases;

    while (ncases--) {
        cin >> nkeys;
        for (int i = 0; i < nkeys; i++) {
            cin >> ni[i];
        }
        for (int i = 0; i < nkeys; i++) {
            cin >> pi[i];
        }
        for (int i = 0; i < nkeys; i++) {
            row = ni[i];
            col = pi[i];
            cout << a[row][col-1];
        }
        cout << endl;
    }
    return 0;
}
