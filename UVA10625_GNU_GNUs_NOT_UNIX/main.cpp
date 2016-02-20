#include <iostream>
#include <vector>

/*
Accepted: 0.019s
Category: string processing, frequency counting
Algorithm: frequency counting (a lot of it!)
*/

using namespace std;

#define NALPHA (126-33+1)
#define ASCII_DIFF 33

void parseRule(string &line, vector<vector<int> > &ruleVec, vector<bool> &hasRule) {
    char charToReplace = line[0];
    /* start i @ 3 because rule has form C->xxxx */
    hasRule[charToReplace-ASCII_DIFF] = true;
    for (int i = 3; line[i]; i++)
        ruleVec[charToReplace-ASCII_DIFF][line[i]-ASCII_DIFF]++;
}

int main() {
	int ncases, nrules, nqueries, ntimes;
	string line, initialString, charToCount;

	cin >> ncases;
	while (ncases--) {
        cin >> nrules;
        vector<vector<int> > ruleVec(NALPHA, vector<int>(NALPHA, 0));
        vector<bool> hasRule(NALPHA, false);
        for (int i = 0; i < nrules; i++) {
            cin >> line;
            parseRule(line, ruleVec, hasRule);
        }
        cin >> nqueries;
        for (int i = 0; i < nqueries; i++) {
            cin >> initialString >> charToCount >> ntimes;
            vector<unsigned long long> freq(NALPHA, 0);
            for (int j = 0; initialString[j]; j++) {
                freq[initialString[j]-ASCII_DIFF]++;
            }
            for (int z = 0; z < ntimes; z++) {
                vector<unsigned long long> temp(NALPHA, 0);
                /* for each item that has a frequency */
                for (int j = 0; j < NALPHA; j++) {
                    if (freq[j] > 0 and hasRule[j]) { /* if char is in "current string" and has a replacement rule */
                       /* vector<int> replacementFreq = ruleVec[j]; comment out and use ruleVec[j] so no copying is done */
                        for (int k = 0; k < NALPHA; k++) {
                            if (ruleVec[j][k] > 0) {
                                temp[k] += freq[j]*ruleVec[j][k];
                            }
                        }
                    }
                }
                for (int j = 0; j < NALPHA; j++) {
                    if (freq[j] > 0 and hasRule[j]) {
                        freq[j] = temp[j]; /* replace the rule chars */
                    } else if (temp[j] > 0) {
                        freq[j] += temp[j];
                    }
                }
            } /* end for (int z = 0; z < ntimes; z++) */
            cout << freq[charToCount[0]-ASCII_DIFF] << endl;
        } /* end for (int i = 0; i < nqueries; i++) */
	}
    return 0;
}
