#include <iostream>
#include <vector>

/*
Accepted: 0.006s
Description: ad-hoc/1d array processing
*/

#define read cin

using namespace std;

int main() {
    int i, n, x, first, last;
    vector<int> v;
    while (read >> n && n != 0) {
        v.clear();
        for (i = 0; i < n; i++) {
            read >> x;
            if (i == 0) first = x;
            if (i == n - 1) last = x;
            v.push_back(x);
        }
        v.push_back(first);
        v.insert(v.begin(), last);
        x = 0;
        for (i = 1; i <= n; i++)
            if ((v[i-1] < v[i] && v[i] > v[i+1]) ||
                (v[i-1] > v[i] && v[i] < v[i+1]))
                x++;
        cout << x << endl;
    }
    return 0;
}
