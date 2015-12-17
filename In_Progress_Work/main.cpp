#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//#define read cin

void process(vector<int> &v, vector<int> &isUsed, int k, int N, int targetSum,
                    vector<int> &bestV, int &bestSum, int &bestDiff) {

}

void backtrack(vector<int> &v, vector<int> &cand, int k, int N, int sumSoFar, int targetSum,
                        vector<int> &bestV, int &bestSum, int &bestDiff) {
    if (sumSoFar > targetSum)
        return;

    if (k == N) {
        if (targetSum - sumSoFar < bestDiff) {
            bestSum = sumSoFar;
            bestV.clear();
            for (int i = 0; i < cand.size(); i++) {
                bestV[i] = cand[i];
            }
        }
        return;
    }
    for (int i = 0; i < 2; i++) {
        if (i == 0) {
            sum += v[k];
            cand.push_back(v[k]);
        } else {
            sum -= v[k];
            cand.pop_back();
        }
    }
}

int main() {
    ifstream read("test.txt");
    int N, ntracks, x;
    vector<int> v;
    vector<int> isUsed;

    while (read >> N) {
        read >> ntracks;
        v.clear();
        isUsed.clear();
        isUsed.assign(isUsed.begin(), 0);
        for (int i = 0; i < ntracks; i++) {
            read >> x;
            v.push_back(x);
        }
    }

    read.close();
    return 0;
}
