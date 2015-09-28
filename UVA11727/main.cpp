#include <iostream>

/*
Accepted: 0.000s
Description: super easy calculation
*/
using namespace std;

int main() {
    int i = 1, ncases, a, b, c, sum;
    cin >> ncases;
    while (ncases--) {
        cin >> a >> b >> c;
        sum = a + b + c;
        cout << "Case " << i++ << ": " << sum - min(a, min(b, c)) - max(a, max(b, c)) << endl;
    }
    return 0;
}
