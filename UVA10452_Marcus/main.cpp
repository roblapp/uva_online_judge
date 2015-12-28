#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: complete search - backtracking
*/

using namespace std;

#define read cin

void backtrack(vector<string> &v, vector<string> &soln, string &path, int currentPathStrPos, int cr, int cc, int er, int ec) {
    if (cr == er && cc == ec) {
        for (int i = 0; i < 7; i++)
            (i > 0) ? cout << " " << soln[i] : cout << soln[i];
        cout << endl;
        return;
    }

    if (cr - 1 >= 0 && v[cr-1][cc] == path[currentPathStrPos]) {
        soln.push_back("forth");
        backtrack(v, soln, path, currentPathStrPos + 1, cr - 1, cc, er, ec);
    } else if (cc - 1 >= 0 && v[cr][cc-1] == path[currentPathStrPos]) {
        soln.push_back("left");
        backtrack(v, soln, path, currentPathStrPos + 1, cr, cc - 1, er, ec);
    } else if (cc + 1 < (int) v[cr].size() && v[cr][cc+1] == path[currentPathStrPos]) {
        soln.push_back("right");
        backtrack(v, soln, path, currentPathStrPos + 1, cr, cc + 1, er, ec);
    }
}

int main() {
    int ncases, m, n, sr, sc, er, ec;
    string line, path = "IEHOVA#";

    read >> ncases; getline(read, line);
    while (ncases--) {
        read >> m >> n; getline(read, line);
        vector<string> v;
        vector<string> soln;
        for (int i = 0; i < m; i++) {
            getline(read, line);
            v.push_back(line);
            for (int j = 0; j < n; j++) {
                if (line[j] == '@') {
                    sr = i;
                    sc = j;
                } else if (line[j] == '#') {
                    er = i;
                    ec = j;
                }
            }
        }
        backtrack(v, soln, path, 0, sr, sc, er, ec);
    }
    return 0;
}
