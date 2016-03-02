#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, encoding/decoding
Algorithm: frequency counting, word counting
*/

using namespace std;

#define NALPHA 26
#define ASCII_DIFF 'a'

int processString(vector<int> &wsv, vector<int> &fv, string &s) {
    int cnt = 0, sz = 0;
    bool state = false;
    wsv.clear();
    fv.assign(NALPHA, 0);
    for (int i = 0; s[i]; i++) {
        if (isspace(s[i])) {
            if (state) {
                cnt++;
                sz = 0;
                wsv.push_back(sz);
            }
            state = false;
        } else if (isalpha(s[i])) {
            state = true;
            sz++;
            fv[s[i]-ASCII_DIFF]++;
        }
    }
    sort(fv.begin(), fv.end());
    return cnt;
}

bool hasEncoding(vector<string> &v, string &s, int nwords, vector<int> &wsv, vector<int> &fv, vector<char> &soln) {
    int NV = (int) v.size(), NS = (int) s.length();
    for (int i = 0; i < NV; i++) {
        if ((int) v[i].length() == NS) {
            vector<int> wsvtemp, fvtemp;
            int nwordsTemp = processString(wsvtemp, fvtemp, v[i]);
            if (nwords == nwordsTemp) {
                int j = 0;
                while (j < NALPHA and fv[j] == fvtemp[j]) {
                    j++;
                }
                if (j == NALPHA) { /* all words match */
                    j = 0;
                    while (j < nwords and wsv[j] == wsvtemp[j]) {
                        j++;
                    }
                    if (j == nwords) { /* the word sizes match... v[i] is a great candidate */
                        soln.assign(NALPHA, 0);
                        for (j = 0; j < NS; j++) { /* note v[i].length() == NS */
                            if (!isspace(v[i][j])) {
                                soln[v[i][j]-ASCII_DIFF] = s[j];
                            }
                        }
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main() {
	string line;
	string REF_STRING = "the quick brown fox jumps over the lazy dog";
	vector<int> wsv, fv;
	int ncases, nwords = processString(wsv, fv, REF_STRING), N = 0;

	cin >> ncases; getline(cin, line); getline(cin, line); /* drain newline and first empty line */
	while (ncases--) {
        vector<string> v;
        vector<char> soln;
        while (getline(cin, line) and !line.empty()) {
            v.push_back(line);
        }

        if (N++)
            cout << endl;

        if (hasEncoding(v, REF_STRING, nwords, wsv, fv, soln)) {
            stringstream ss("");
            for (int i = 0; i < (int) v.size(); i++) {
                for (int j = 0; v[i][j]; j++) {
                    if (isalpha(v[i][j])) {
                        ss << soln[v[i][j]-ASCII_DIFF];
                    } else {
                        ss << v[i][j];
                    }
                }
                ss << endl;
            }
            cout << ss.str();
        } else {
            cout << "No solution." << endl;
        }
	}
    return 0;
}
