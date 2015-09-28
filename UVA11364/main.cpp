#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted 0.000s
Description: ad hoc, super easy
Info: read in each number and sort them, then compute the difference between
each pair of consecutive elements.
*/
using namespace std;

int main() {
    int ncases, n, x, i, len;
    vector<int> v;
    cin >> ncases;
    while (ncases--) {
        cin >> n;
        v.clear(); len = 0;
        while (n--) {
            cin >> x;
            v.push_back(x);
            len++;
        }
        sort(v.begin(), v.end());
        x = 0;
        for (i = 0; i + 1 < len; i++) {
            x += v[i+1] - v[i];
        }
        cout << (2*x) << endl;
    }

    return 0;
}
