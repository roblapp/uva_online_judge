#include <iostream>
#include <vector>

/*
Accepted: 0.112s
Description: complete search - backtracking
*/

using namespace std;

#define read cin

void backtrackHelper(vector<string> &v, int nv, string &rule, int currentRuleStrPos, const int ruleLen, string soln) {
    if (currentRuleStrPos >= ruleLen) {
        cout << soln << endl;
        return;
    }

    if (rule[currentRuleStrPos] == '#')
        for (int i = 0; i < nv; i++)
            backtrackHelper(v, nv, rule, currentRuleStrPos + 1, ruleLen, soln + v[i]);
    else
        for (int i = 0; i < 10; i++)
            backtrackHelper(v, nv, rule, currentRuleStrPos + 1, ruleLen, soln + (char) (i + '0'));
}

void backtrack(vector<string> &v, int nv, vector<string> &vr, int nvr) {
    for (int i = 0; i < nvr; i++) {
        cout << "--" << endl;
        backtrackHelper(v, nv, vr[i], 0, vr[i].length(), "");
    }
}

int main() {
    int nwords, nrules;
    string line;

    while (read >> nwords) {
        getline(read, line);
        vector<string> v;
        while (nwords--) {
            getline(read, line);
            v.push_back(line);
        }
        read >> nrules; getline(read, line);
        vector<string> vr;
        while (nrules--) {
            getline(read, line);
            vr.push_back(line);
        }
        backtrack(v, (int) v.size(), vr, (int) vr.size());
    }
    return 0;
}
