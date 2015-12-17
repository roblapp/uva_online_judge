#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.208s
Description: backtracking, complete search, permutations
*/

using namespace std;

#define read cin

bool backtrack(vector<int> &v, int k, int value) {
    if (k == 4) { /* Done */
        return (value == 23);
    }
    int tempValue = (k == 0) ? v[0] : value;
    if (backtrack(v, k + 1, tempValue + v[k+1]))
        return true;
    if (backtrack(v, k + 1, tempValue - v[k+1]))
        return true;
    if (backtrack(v, k + 1, tempValue * v[k+1]))
        return true;
    return false;
}

int main() {
    int x;
    vector<int> v;

    while (1) {
        v.clear();
        for (int i = 0; i < 5; i++) {
            read >> x;
            v.push_back(x);
        }
        if (v[0] == 0)
            break;
        sort(v.begin(), v.end());
        bool possible = false;
        do {
            possible = backtrack(v, 0, 0);
        } while (!possible && next_permutation(v.begin(), v.end()));
        if (possible)
            cout << "Possible" << endl;
        else
            cout << "Impossible" << endl;
    }
    return 0;
}
