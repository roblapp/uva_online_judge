#include <iostream>

/*
Accepted: 0.000s
Description: 1D array processing
*/

#define read cin
#define MAXN 1422+1
#define CHARGE_AMT 200

using namespace std;

int main() {
    int i, n, x, sum;
    bool s[MAXN];
    bool failed;
    while (read >> n && n != 0) {
        for (i = 0; i < MAXN; i++) s[i] = false;
        for (i = 0; i < n; i++) {
            read >> x;
            s[x] = true;
        }
        sum = 0;
        failed = false;
        for (i = 0; i < MAXN && !failed; i++) {
            if (s[i]) sum = CHARGE_AMT;
            if (sum <= 0) failed = true;
            sum--;
        }
        for (i = MAXN - 2; i >= 0 && !failed; i--) {
            if (s[i]) sum = CHARGE_AMT;
            if (sum <= 0) failed = true;
            sum--;
        }
        if (!failed && sum >= 0) cout << "POSSIBLE" << endl;
        else cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
