#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

int main() {
    int i, n, ncases, prev, x, low, high, N = 1;
    cin >> ncases;
    while (ncases--) {
        cin >> n;
        low = high = 0;
        for (i = 0; i < n; i++) {
            if (i == 0) {
                cin >> prev;
            } else {
                cin >> x;
                if (prev - x < 0) high++;
                else if (prev - x > 0) low++;
                prev = x;
            }
        }
        cout << "Case " << N++ << ": " << high << " " << low << endl;
    }

    return 0;
}
