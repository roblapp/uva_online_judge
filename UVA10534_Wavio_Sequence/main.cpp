#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.106s
Description: longest increasing subsequence - NLOGN implementation
I did most of this myself but then cheated a bit... I wasn't reversing the LIS array and
kept getting wrong answers in sample I/O. I finally looked at
    https://belbesy.wordpress.com/2011/08/09/uva-10534-wavio-sequence/
and that clarified things.
*/

using namespace std;

int wavioSequence(vector<int> &v, int N, int LIS[]) {
    int S[N];
    int length = 1;

    S[0] = v[0];
    LIS[0] = 1;
    for (int i = 1; i < N; i++) {
        /* Returns an iterator pointing to the first element in the range [first,last) which compares less than val. */
        int index = lower_bound(S, S + length, v[i]) - S;
        LIS[i] = index + 1;
        S[index] = v[i];
        if (index == length)
            length++;
    }
    return length;
}

int main() {
    int n, x;

    while (cin >> n) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        int LIS[n];
        int LDS[n];
        wavioSequence(v, n, LIS);
        reverse(v.begin(), v.end());
        wavioSequence(v, n, LDS);
        reverse(LDS, LDS + n);
        int temp = -1;
        for (int i = 0; i < n; i++)
            temp = max(temp, min(LIS[i], LDS[i]));
        cout << 2*temp - 1 << endl;
    }
    return 0;
}
