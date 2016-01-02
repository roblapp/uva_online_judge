#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: dynamic programming - longest increasing/decreasing subsequence
*/

using namespace std;

#define read cin

int longestDecreasingSubsequence(vector<int> &v, int N) {
    int sol[N];
    int temp;
    for (int i = 0; i < N; i++) sol[i] = 0;

    sol[0] = 1;
    for (int i = 1; i < N; i++) {
        temp = 0;
        for (int j = 0; j < i; j++) {
            if (v[j] >= v[i] && sol[j] > temp) {
                temp = sol[j];
            }
        }
        sol[i] = temp + 1;
    }
    temp = 0;
    for (int i = 0; i < N; i++)
        if (sol[i] > temp)
            temp = sol[i];
    return temp;
}

int main() {
    int x, N = 0;

    while (1) {
        read >> x;
        if (x == -1)
            break;
        vector<int> v;
        do {
            v.push_back(x);
            read >> x;
        } while (x != -1);
        if (N)
            cout << endl;
        cout << "Test #" << N++ + 1 << ":" << endl;
        cout << "  maximum possible interceptions: " << longestDecreasingSubsequence(v, (int) v.size()) << endl;
    }
    return 0;
}
