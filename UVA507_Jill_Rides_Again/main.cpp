#include <iostream>
#include <vector>
#include <climits>

/*
Accepted: 0.186s
Description: dynamic programming - Kadane's algorithm
*/

using namespace std;

#define read cin

void kadanes(vector<int> &v, int N, int &maxSum, int &maxStartIndex, int &maxEndIndex) {
    int meh = v[0], msf = v[0], tempStartIndex = 0, tempEndIndex = 1;
    maxStartIndex = 0, maxEndIndex = 1;
    for (int i = 1; i < N; i++) {
        if (meh < 0) {
            meh = v[i];
            tempStartIndex = i, tempEndIndex = i + 1;
        } else {
            meh += v[i];
            tempEndIndex++;
        }
        if (meh > msf) {
            msf = meh;
            maxStartIndex = tempStartIndex;
            maxEndIndex = tempEndIndex;
        } else if (meh == msf && (tempEndIndex - tempStartIndex) > (maxEndIndex - maxStartIndex)) {
            msf = meh;
            maxStartIndex = tempStartIndex;
            maxEndIndex = tempEndIndex;
        }
    }
    maxSum = msf;
}

int main() {
    int ncases, nstops, x;

    read >> ncases;
    for (int i = 1; i <= ncases; i++) {
        read >> nstops;
        vector<int> v;
        int si, ei, res;
        for (int j = 0; j < nstops - 1; j++) {
            read >> x;
            v.push_back(x);
        }
        kadanes(v, nstops - 1, res, si, ei);
        if (res > 0)
            cout << "The nicest part of route " << i << " is between stops " << si + 1 << " and " << ei + 1 << endl;
        else
            cout << "Route " << i << " has no nice parts" << endl;
    }
    return 0;
}
