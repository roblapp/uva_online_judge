#include <iostream>
#include <cmath>

/*
Accepted: 0.169s
Category: math-base conversion, bignum
*/

using namespace std;

#define MAX_BASE 36

int toInt(char c) {
    return (c >= 'A') ? c - 'A' + 10 : c - '0';
}

char toChar(int x) {
    return (x >= 10) ? 'A' + x - 10 : x + '0';
}

long double applyBase(string &x, int b) {
    long double res = 0;
    long double exp = (int) x.length() - 1;
    for (int i = 0; x[i]; i++)
        res += toInt(x[i])*pow(b, exp--);
    return res;
}

int findMinBase(string &num) {
    char cm = 0;
    for (int i = 0; num[i]; i++)
        if (num[i] > cm)
            cm = num[i];
    return toInt(cm) + 1;
}

bool findMatchingBases(string &x, string &y, int &baseA, int &baseB) {
    int minBaseX = max(2, findMinBase(x));
    int minBaseY = max(2, findMinBase(y));
    for (int bx = minBaseX; bx <= MAX_BASE; bx++) {
        for (int by = minBaseY; by <= MAX_BASE; by++) {
            if (applyBase(x, bx) == applyBase(y, by)) {
                baseA = bx;
                baseB = by;
                return true;
            }
        }
    }
    return false;
}

int main() {
	int solnA, solnB;
	string x, y;

	while (cin >> x >> y) {
        if (findMatchingBases(x, y, solnA, solnB))
            cout << x << " (base " << solnA << ") = " << y << " (base " << solnB << ")" << endl;
        else
            cout << x << " is not equal to " << y << " in any base 2..36" << endl;
	}
    return 0;
}
