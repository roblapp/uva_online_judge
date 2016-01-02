#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.042s
Description: longest increasing subsequence, NLOGN implementation
Note: Did not produce the correct output on uDebug, but was accepted
on UVa.
*/

using namespace std;

#define read cin

void printSequence(vector<int> &v, int parent[], int index, int length) {
    if (index < 0) {
        cout << length << endl << "-" << endl;
        return;
    }
    printSequence(v, parent, parent[index], length);
    cout << v[index] << endl;
}

void longestIncreasingSubsequence(vector<int> &v, int N) {
    int parent[N];
    int S[N];
    int SI[N + 1];
    int length = 0;
    int maxPos = 0;

    for (int i = 0; i < N; i++) {
        int index = lower_bound(S, S + length, v[i]) - S;
        S[index] = v[i];
        SI[index] = i;
        parent[i] = (index > 0) ? SI[index - 1] : -1;
        if (index == length) {
            length++;
            maxPos = i;
        }
    }
    printSequence(v, parent, maxPos, length);
}

int main() {
    int x, n = 0;
    vector<int> v;

    while (read >> x) {
        n++;
        v.push_back(x);
    }
    longestIncreasingSubsequence(v, n);
    return 0;
}
