#include <iostream>
#include <vector>
#include <climits>
#include <cmath>

/*
Accepted: 0.023s
Description: complete search - double nested loops
*/

using namespace std;

#define read cin

int closestSum(vector<int> &v, int sum) {
    int N = (int) v.size(), diff = INT_MAX, temp, temp2, c = 0;
    for (int i = 0; i < N - 1; i++)
        for (int j = i + 1; j < N; j++) {
            temp = v[i] + v[j];
            if ((temp2 = abs(temp - sum)) < diff) {
                c = temp;
                diff = temp2;
            }
        }
    return c;
}

int main() {
    int n, m, x, N = 1;

    while (read >> n && n != 0) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            read >> x;
            v.push_back(x);
        }
        read >> m;
        cout << "Case " << N++ << ":" << endl;
        for (int i = 0; i < m; i++) {
            read >> x;
            cout << "Closest sum to " << x << " is " << closestSum(v, x) << "." << endl;
        }
    }
    return 0;
}
