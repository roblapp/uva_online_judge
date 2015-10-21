#include <iostream>
#include <cmath>

/*
Accepted: 0.006s
Description: counting divisors, factoring
See: http://www.mathblog.dk/uva-294-divisors/
*/

using namespace std;

int divisorCount(int x) {
    int i, res = 1, N = (int) sqrt(x), pow;
    for (i = 2; i <= N; i = (i == 2 ? 3 : i + 2)) {
        pow = 0;
        while (x % i == 0) {
            pow++;
            x /= i;
        }
        if (pow > 0) {
            res = res * (pow + 1);
            N = (int) sqrt(x);
        }
    }
    if (x != 1) {
        res *= (1 + 1);
    }
    return res;
}

int main() {
    int i, ncases, a, b, temp, res = 0, resNum;
    cin >> ncases;
    while (ncases--) {
        cin >> a >> b;
        resNum = a;
        res = 1;
        for (i = a; i <= b; i++) {
            if ((temp = divisorCount(i)) > res) {
                res = temp;
                resNum = i;
            }
        }
        cout << "Between " << a << " and " << b << ", " << resNum << " has a maximum of " << res << " divisors." << endl;
    }
    return 0;
}
