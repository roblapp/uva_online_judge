#include <iostream>
#include <iomanip>
#include <math.h>

/* ACCEPTED 0.019 */

using namespace std;

int sum_divisors(int n) {
    int i;
    int res = 1;
    int bound = sqrt(n);

    for (i = 2; i <= bound; i++) {
        if (n % i == 0) {
            res += n / i;
            if ((n / i) != i) {
                res += i;
            }
        }
    }
    return res;
}


int main() {
    int n, sum;
    cout << "PERFECTION OUTPUT" << endl;
    while (cin >> n && n > 0) {
        sum = sum_divisors(n);
        if (n == 1 || sum < n)
            cout << setw(5) << n << "  " << "DEFICIENT" << endl;
       else if (sum > n)
            cout << setw(5) << n << "  " << "ABUNDANT" << endl;
        else
            cout << setw(5) << n << "  " << "PERFECT" << endl;
    }
    cout << "END OF OUTPUT" << endl;

    return 0;
}
