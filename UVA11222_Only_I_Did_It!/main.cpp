#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.003s
Description: 1D array processing
*/

#define read cin
#define MAXN 10000 + 1

using namespace std;

int main() {
    int i, j, k, ncases, n, x, maxVal, solnLen;
    vector<int> v[3];
    vector<int>::iterator it;
    vector<int> maxPersons;
    int a[MAXN], cnt[3];
    read >> ncases;
    for (i = 1; i <= ncases; i++) {
        for (k = 0; k < MAXN; k++) a[k] = 0;
        for (k = 0; k < 3; k++) {
            v[k].clear();
            read >> n;
            for (j = 0; j < n; j++) {
                read >> x;
                v[k].push_back(x);
                a[x]++;
            }
        }
        maxVal = 0;
        maxPersons.clear();
        for (k = 0; k < 3; k++) cnt[k] = 0;
        for (k = 0; k < 3; k++) {
            for (it = v[k].begin(); it != v[k].end(); it++)
                if (a[*it] == 1) cnt[k]++;
            if (cnt[k] > maxVal) {
                maxVal = cnt[k];
                maxPersons.clear();
                maxPersons.push_back(k);
            } else if (cnt[k] == maxVal) {
                maxPersons.push_back(k);
            }
        }

        solnLen = maxPersons.size();
        for (k = 0; k < solnLen; k++)
            sort(v[maxPersons[k]].begin(), v[maxPersons[k]].end());

        cout << "Case #" << i << ":" << endl;
        for (k = 0; k < solnLen; k++) {
            cout << maxPersons[k] + 1 << " " << cnt[maxPersons[k]];
            for (it = v[maxPersons[k]].begin(); it != v[maxPersons[k]].end(); it++)
                if (a[*it] == 1)
                    cout << " " << *it;
            cout << endl;
        }
    }
    return 0;
}
