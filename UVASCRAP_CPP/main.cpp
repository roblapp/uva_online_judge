#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAXN 100

using namespace std;

bool isPandigitalPair(int a, int b, bool isFourDigits) {
    bool m[10];
    int temp;
    memset(m, 0, sizeof(m));
    if (isFourDigits) {
        m[0] = true;
    }
    while (a > 0) {
        temp = a % 10;
        if (m[temp]) {
            return false;
        }
        m[temp] = true;
        a /= 10;
    }
    while (b > 0) {
        temp = b % 10;
        if (m[temp]) {
            return false;
        }
        m[temp] = true;
        b /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (!m[i]) {
            return false;
        }
    }
    return true;
}

bool isFiveDigits(int n) {
    string temp = "";
    while (n > 0) {
        temp += (n % 10) + 48;
        n /= 10;
    }
    return (temp.length() == 5);
}

int main() {
    int n, N = 0;
    bool solnFound, cond;

    while (cin >> n && n > 0) {
        solnFound = cond = false;
        if (N++) {
            cout << endl;
        }
        for (int i = 1234; i <= 98765 && isFiveDigits(n*i); i++) {
            cond = (i < 10000);
            if (isPandigitalPair(i, n*i, cond)) {
                if (cond) {
                    cout << (n*i) << " / 0" << (i) << " = " << n << endl;
                } else {
                    cout << (n*i) << " / " << (i) << " = " << n << endl;
                }

                solnFound = true;
            }
        }
        if (!solnFound) {
            cout << "There are no solutions for " << n << "." << endl;
        }
    }

    return 0;
}
