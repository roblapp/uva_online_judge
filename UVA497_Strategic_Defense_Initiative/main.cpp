#include <iostream>
#include <vector>
#include <sstream>

/*
Accepted: 0.000s
Description: longest increasing subsequence, ,NLOGN implementation
*/

using namespace std;

#define read cin

void printSequence(vector<int> &v, int parent[], int index, int length) {
    if (index < 0) {
        cout << "Max hits: " << length << endl;
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
    int ncases, x;
    string line;

    read >> ncases; getline(read, line); getline(read, line);

    for (int i = 0; i < ncases; i++) {
        vector<int> v;
        int n = 0;
        while (getline(read, line) && !line.empty()) {
            stringstream ss(line);
            ss >> x;
            v.push_back(x);
            n++;
        }
        if (i)
            cout << endl;
        longestIncreasingSubsequence(v, n);
    }
    return 0;
}
