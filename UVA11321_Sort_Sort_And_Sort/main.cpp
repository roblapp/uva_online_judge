#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.272s
Description: sorting
*/

#define read cin

using namespace std;

int M;

bool compare(int a, int b) {
    int moda = a % M;
    int modb = b % M;
    if (moda < modb) return true;
    else if (moda > modb) return false;
    int amod2 = a % 2;
    int bmod2 = b % 2;
    if (amod2 == 0) {
        if (bmod2 == 0) return a < b;
        else return false;
    } else {
        if (bmod2 == 0) { /* Tie between an even and an odd, */
            return true;
        } else { /* Tie between 2 odds, the larger odd comes first */
            return a > b;
        }
    }
}

int main() {
    int i, N, x;
    vector<int> v;
    while (read >> N >> M) {
        cout << N << " " << M << endl;
        if (N == 0 && M == 0) {
            break;
        } else {
            v.clear();
            for (i = 0; i < N; i++) {
                read >> x;
                v.push_back(x);
            }
            sort(v.begin(), v.end(), compare);
            for (i = 0; i < N; i++) {
                cout << v[i] << endl;
            }
        }
    }
    return 0;
}
