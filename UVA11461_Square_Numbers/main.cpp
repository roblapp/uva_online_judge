#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

#define MAXN 100000

using namespace std;

int main() {
    int a, b, i, cnt;
    int c[MAXN + 1];
    for (i = 0; i <= MAXN; i++) c[i] = 0;
    cnt = 1;
    for (i = 1; i*i <= MAXN; i++) {
        c[i*i] = cnt;
        cnt++;
    }
    cnt = 1;
    for (i = 1; i <= MAXN; i++) {
        if (c[i] == 0) c[i] = cnt;
        else cnt = c[i];
    }
    while (cin >> a >> b && (a != 0 || b != 0)) {
        if (c[a] != c[a-1]) cout << c[b] - c[a] + 1 << endl;
        else cout << c[b] - c[a] << endl;
    }
    return 0;
}
