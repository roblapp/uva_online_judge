#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: complete search - backtracking
Info: Even with a brute force and 0 optimizations, I still passed with 0.000s time!!!
*/

using namespace std;

#define read cin
#define out cout

void printSoln(vector<int> &vs) {
    int N = (int) vs.size();
    for (int i = 0; i < N; i++)
        (i > 0) ? out << "+" << vs[i] : out << vs[i];
    out << endl;
}

bool isSame(vector<int> &va, vector<int> &vb) {
    int n;
    if ((n = va.size()) == (int) vb.size()) {
        for (int i = 0; i < n; i++)
            if (va[i] != vb[i])
                return false;
        return true;
    }
    return false;
}

void process(vector<vector<int> > &soln, vector<int> &vs) {
    if (soln.size() == 0) {
        soln.push_back(vs);
        return;
    }
    for (vector<vector<int> >::iterator it = soln.begin(); it != soln.end(); it++)
        if (isSame(*it, vs))
            return;
    soln.push_back(vs);
}

void backtrack(vector<int> &v, vector<int> &vs, vector<vector<int> > &soln, int k, int n, int currentSum, int targetSum, bool &foundOne) {
    if (currentSum == targetSum) {
        process(soln, vs);
        foundOne = true;
        return;
    } else if (k >= n) {
        return;
    }
    vs.push_back(v[k]);
    backtrack(v, vs, soln, k + 1, n, currentSum + v[k], targetSum, foundOne);
    vs.pop_back();
    backtrack(v, vs, soln, k + 1, n, currentSum, targetSum, foundOne);
}

int main() {
    int n, t, x;

    while (read >> t >> n && (t != 0 || n != 0)) {
        vector<int> v, vs;
        vector<vector<int> > soln;
        bool foundOne = false;
        for (int i = 0; i < n; i++) {
            read >> x;
            v.push_back(x);
        }
        out << "Sums of " << t << ":" << endl;
        backtrack(v, vs, soln, 0, n, 0, t, foundOne);
        if (!foundOne)
            out << "NONE" << endl;
        else
            for (vector<vector<int> >::iterator it = soln.begin(); it != soln.end(); it++)
                printSoln(*it);
    }
    return 0;
}
