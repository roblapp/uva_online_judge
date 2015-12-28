#include <iostream>
#include <vector>

/*
Accepted: 0.109s
Description: dynamic programming - Kadane's algorithm
*/

using namespace std;

#define read cin

int kadanes(vector<int> &v, int N) {
    int meh = v[0], msf = v[0];
    for (int i = 1; i < N; i++) {
        if (meh < 0)
            meh = v[i];
        else
            meh += v[i];
        if (meh > msf)
            msf = meh;
    }
    return msf;
}

int main() {
    int n, x, sum;

    while (read >> n && n != 0) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            read >> x;
            v.push_back(x);
        }
        if ((sum = kadanes(v, n)) > 0)
            cout << "The maximum winning streak is " << sum << "." << endl;
        else
            cout << "Losing streak." << endl;
    }
    return 0;
}
