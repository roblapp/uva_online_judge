#include <iostream>
#include <cmath>
#include <map>

/*
Accepted: 0.253s (solution after a few optimizations)

Accepted: 0.309s (straight forward solution)

Description: for number of digitis in N! NDIGITS = sum (log10(i)) for 2<=i<=N
*/

using namespace std;

int main() {
    int i, ncases, x, temp, closestKey;
    double sum;
    map<int, double> m;
    map<int, double>::iterator it;
    cin >> ncases;
    m[1] = log10(2); m[2] = log10(2);
    while (ncases--) {
        cin >> x;
        it = m.find(x);
        if (it != m.end()) {
            cout << ((int) (it->second)) + 1 << endl;
        } else {
            closestKey = 0;
            for (it = m.begin(); it != m.end(); it++) {
                temp = it->first;
                if (temp <= x and temp > closestKey) {
                    closestKey = temp;
                }
            }
            sum = m[closestKey];
            for (i = closestKey + 1; i <= x; i++) {
                sum += log10(i);
            }
            m[x] = sum;
            cout << ((int) sum) + 1 << endl;
        }
    }
    return 0;
}
