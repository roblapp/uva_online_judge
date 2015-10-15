#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc.
Info: Just make sure each of the blocks can slide up the same
number of positions. Watch out for invalid input!
*/

using namespace std;

int main() {
    int i, a, b, ncases, n, dist, N = 0;
    bool soln;
    cin >> ncases;
    while (ncases--) {
        cin >> n;
        soln = true;
        for (i = 0; i < n; i++) {
            cin >> a >> b;
            if (soln) {
                if (i == 0) dist = a - b;
                else if (a - b != dist) soln = false;
            }
        }
        if (N++) cout << endl;
        if (n >= 0 and soln) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
