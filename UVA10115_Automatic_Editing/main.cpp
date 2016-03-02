#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Category: string processing, ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

void replaceWithRules(string &findStr, string &replaceStr, string &s) {
    int i = 0, findLen = findStr.length();
    while (i <= (int) (s.length() - findLen)) {
        if (s.substr(i, findLen) == findStr)
            s.replace(i, findLen, replaceStr);
        else
            i++;
    }
}

string applyRules(vector<string> &fv, vector<string> &rv, string &s) {
    int N = (int) fv.size();
    for (int i = 0; i < N; i++)
        replaceWithRules(fv[i], rv[i], s);
    return s;
}

int main() {
	int nrules;
	string line;

	while (cin >> nrules and nrules != 0) {
        getline(cin, line); /* drain newline */
        vector<string> fv(nrules), rv(nrules);
        for (int i = 0; i < nrules; i++) {
            getline(cin, fv[i]);
            getline(cin, rv[i]);
        }
        getline(cin, line);
        cout << applyRules(fv, rv, line) << endl;
	}
    return 0;
}
