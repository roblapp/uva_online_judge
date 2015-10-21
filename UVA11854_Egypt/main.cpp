#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc, simple math
*/

using namespace std;

int main() {
    int a, b, c, ma, mb, mc, sum;
    while (cin >> a >> b >> c && (a != 0 || b != 0 || c != 0)) {
        sum = a + b + c;
        ma = min(a, min(b, c));
        mc = max(a, max(b, c));
        mb = sum - ma - mc;
        if (ma*ma + mb*mb == mc*mc) cout << "right" << endl;
        else cout << "wrong" << endl;
    }
    return 0;
}
