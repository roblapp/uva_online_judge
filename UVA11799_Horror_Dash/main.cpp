#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

int main() {
    int i, ncases, n, x, msf, N = 1;
    cin >> ncases;
    while (ncases--) {
        cin >> n;
        msf = 0;
        for (i = 0; i < n; i++) {
            cin >> x;
            msf = max(msf, x);
        }
        cout << "Case " << N++ << ": " << msf << endl;
    }
    return 0;
}
