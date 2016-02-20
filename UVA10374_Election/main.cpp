#include <iostream>
#include <map>
#include <vector>

/*
Accepted: 0.006s
Category: string processing, frequency counting
Algorithm: frequency counting
*/

using namespace std;

int main() {
	int ncases, np, nv, N = 0;
	string line, candidate, party;
    map<string,int>::iterator fit;

	cin >> ncases;
	while (ncases--) {
        map<string,string> m;
        map<string,int> fmap;

        cin >> np; getline(cin, line); /* drain newline */
        for (int i = 0; i < np; i++) {
            getline(cin, candidate); getline(cin, party);
            m[candidate] = party;
        }
        cin >> nv; getline(cin, line); /* drain newline */
        for (int i = 0; i < nv; i++) {
            getline(cin, candidate);
            if (m.find(candidate) != m.end()) { /* if a valid candidate */
                fit = fmap.find(candidate);
                if (fit == fmap.end())
                    fmap[candidate] = 1;
                else
                    fit->second = fit->second + 1;
            }
        }
        int maxVote = -1;
        string maxCandidate = "";
        vector<int> v(nv + 1, 0);
        for (fit = fmap.begin(); fit != fmap.end(); fit++) {
            v[fit->second]++;
            if (maxVote < fit->second) {
                maxVote = fit->second;
                maxCandidate = fit->first;
            }
        }

        if (N++)
            cout << endl;
        if (maxVote == -1 or v[maxVote] > 1)
            cout << "tie" << endl;
        else
            cout << m[maxCandidate] << endl;
	}
    return 0;
}
