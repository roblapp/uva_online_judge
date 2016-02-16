#include <iostream>
#include <cmath>

using namespace std;

void extractInt(string &expr, int &i, int &xcoeff, int &nonxcoeff) {
    bool isNeg = false;
    if (expr[i] == '-') {
        isNeg = true;
        i++;
    } else if (expr[i] == '+') {
        i++;
    }
    if (isdigit(expr[i])) {
        int res = 0;
        bool is_x = false;
        while (isdigit(expr[i])) {
            res = 10*res + (expr[i] - '0') ;
            i++;
        }
        if (expr[i] == 'x') {
            is_x = true;
            i++;
        }
        if (isNeg)
            res *= -1;
        if (is_x) {
            xcoeff += res;
        } else {
            nonxcoeff += res;
        }
    } else if (expr[i] == 'x') {
        int res = 1;
        if (isNeg)
            res *= -1;
        xcoeff += res;
        i++;
    }
}

bool solve(string &expr, int &soln) {
    bool isLhs = true;
    int lhsX = 0, lhsC = 0, rhsX = 0, rhsC = 0;
    int i = 0, N = (int) expr.length();
    while (i < N) {
        if (expr[i] == '=') {
            isLhs = false;
            i++;
        } else {
            (isLhs) ? extractInt(expr, i, lhsX, lhsC) : extractInt(expr, i, rhsX, rhsC);
        }
    }

    rhsX -= lhsX;
    lhsX = 0;
    lhsC -= rhsC;
    rhsC = 0;

    if (rhsX == lhsX) {
        if (lhsC == rhsC) { /* infinitely many solutions */
            soln = 0;
        } else { /* inconsistent system */
            soln = -1;
        }
        return false;
    }
    soln = (int) floor(lhsC*1.0/rhsX); /* unique solution */
    return true;
}

int main() {
	int n, soln;
	string line;

	cin >> n;
	while (n--) {
        cin >> line;
        if (solve(line, soln))
            cout << soln << endl;
        else
            (soln == 0) ? cout << "IDENTITY" << endl : cout << "IMPOSSIBLE" << endl;
	}
    return 0;
}
