#include <iostream>
#include <cstring>

/*
ACCEPTED 0.009s
Note: Before I made 1 optimization, the first submission was 0.259s!!!
*/

using namespace std;

bool isPandigitalPair(int a, int b, bool isFourDigits) {
    bool m[10];
    int temp;
    memset(m, 0, sizeof(m));
    if (isFourDigits) { m[0] = true; }
    while (a > 0) {
        temp = a % 10;
        if (m[temp]) { return false; }
        m[temp] = true;
        a /= 10;
    }
    while (b > 0) {
        temp = b % 10;
        if (m[temp]) { return false; }
        m[temp] = true;
        b /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (!m[i]) { return false; }
    }
    return true;
}

int main() {
    int n, N = 0, x;
    bool solnFound, cond;
    while (cin >> n && n > 0) {
        solnFound = cond = false;
        if (N++) { cout << endl; }
        for (int i = 1234; i <= 98765 && (x = n*i) <= 99999; i++) {
            cond = (i < 10000);
            if (isPandigitalPair(i, x, cond)) {
                (cond) ? cout << (x) << " / 0" << (i) << " = " << n << endl :
                        cout << (x) << " / " << (i) << " = " << n << endl;
                solnFound = true;
            }
        }
        if (!solnFound) { cout << "There are no solutions for " << n << "." << endl; }
    }
    return 0;
}
