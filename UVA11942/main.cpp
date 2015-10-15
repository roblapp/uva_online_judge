#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.000s
Description: ad-hoc
*/
using namespace std;

bool isSorted(vector<int> &v, bool isDesc) {
    int msf;
    bool sorted = true;
    for (int i = 0, len = v.size(); sorted and i < len; i++) {
        if (i == 0) {
            msf = v[i];
        } else {
            if (isDesc) {
                if (v[i] > msf) sorted = false;
                else msf = v[i];
            } else {
                if (v[i] < msf) sorted = false;
                else msf = v[i];
            }
        }
    }
    return sorted;
}

int main() {
    int i, ncases; bool isFirst = true, sorted;
    vector<int> v(10);
    cin >> ncases;
    while (ncases--) {
        if (isFirst) cout << "Lumberjacks:" << endl;
        for (i = 0; i < 10; i++) cin >> v[i];
        if (v[0] - v[1] < 0) sorted = isSorted(v, false);
        else sorted = isSorted(v, true);
        if (sorted) cout << "Ordered" << endl;
        else cout << "Unordered" << endl;
        isFirst = false;
    }

    return 0;
}
