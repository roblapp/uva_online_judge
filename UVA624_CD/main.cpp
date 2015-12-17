#include <iostream>
#include <vector>
#include <climits>

/*
Accepted: 0.009s
Description: backtracking, subset generation, subset sum
*/

using namespace std;

#define read cin

void backtrack(vector<int> &v, vector<int> &cand, int k, int ntracks, int sumSoFar, int targetSum,
                        vector<int> &bestV, int &bestSum, int &bestDiff) {
    if (sumSoFar > targetSum)
        return;

    if (k == ntracks) {
        if (targetSum - sumSoFar < bestDiff || (targetSum - sumSoFar == bestDiff && cand.size() > bestV.size())) {
            bestDiff = targetSum - sumSoFar;
            bestSum = sumSoFar;
            bestV.clear();
            for (vector<int>::iterator it = cand.begin(); it != cand.end(); it++)
                bestV.push_back(*it);
        }
        return;
    }
    cand.push_back(v[k]);
    backtrack(v, cand, k + 1, ntracks, sumSoFar + v[k], targetSum, bestV, bestSum, bestDiff);
    cand.pop_back();
    backtrack(v, cand, k + 1, ntracks, sumSoFar, targetSum, bestV, bestSum, bestDiff);
}

int main() {
    int N, ntracks, x, bestDiff, bestSum;
    vector<int> v, cand, bestV;

    while (read >> N) {
        read >> ntracks;
        v.clear(); cand.clear(); bestV.clear();
        bestDiff = INT_MAX;
        bestSum = 0;
        for (int i = 0; i < ntracks; i++) {
            read >> x;
            v.push_back(x);
        }
        backtrack(v, cand, 0, ntracks, 0, N, bestV, bestSum, bestDiff);
        for (vector<int>::iterator it = bestV.begin(); it != bestV.end(); it++)
            cout << *it << " ";
        cout << "sum:" << bestSum << endl;
    }
    return 0;
}
