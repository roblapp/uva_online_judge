#include <iostream>
/*
Accepted: 0.000s
Description: ad-hoc/arithmetic progression
*/

using namespace std;

int main() {
    int ncases, a, b, N = 1;
    cin >> ncases;
    while (ncases--) {
        cin >> a >> b;
        if (a % 2 == 0) a++;
        if (b % 2 == 0) b--;
        cout << "Case " << N++ << ": " << (((b*b - a*a + 2*a + 2*b) >> 1) >> 1) << endl;
    }
    return 0;
}
