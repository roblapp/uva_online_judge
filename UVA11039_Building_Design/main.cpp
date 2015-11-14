#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

/*
Accepted: 0.076s
Description: sorting
*/

#define read cin

using namespace std;

bool compare(int a, int b) {
    return abs(a) > abs(b);
}

int main() {
    int ncases, N, x, meh;
    bool e, c;
    vector<int> v;
    read >> ncases;
    while (ncases--) {
        v.clear();
        read >> N;
        if (N == 0) {
            cout << "0" << endl;
        } else {
            for (int i = 0; i < N; i++) {
                read >> x;
                v.push_back(x);
            }
            sort(v.begin(), v.end(), compare);
            meh = 1;
            e = !(v[0] < 0);
            for (int i = 1; i < N; i++) {
                c = v[i] < 0;
                if (e == c) meh++;
                e = !c;
            }
            cout << meh << endl;
        }
    }
    return 0;
}
