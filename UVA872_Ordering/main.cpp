#include <iostream>
#include <vector>
#include <map>
#include <sstream>

/*
Accepted: 0.000s
Description: topological sort, backtracking
Info: I may look into this and try and eliminate some of the vectors
like nsmaller and nlarger and see if I lose any speed by counting each
time I need to make a comparison.
*/

using namespace std;

bool isCandidate(vector<int> &soln, int k, int N, vector<vector<int> > &compareMatrix,
                            vector<int> &nsmaller, vector<int> &nlarger, vector<bool> &used, int candidate) {
    if (!used[candidate] && nsmaller[candidate] <= N - k - 1 && nlarger[candidate] <= k) { /* If not used and its possible... */
        /* check all previous values in the partial solution and make sure previousValue is not > candidate */
        for (int i = 0; i < k; i++)
            if (compareMatrix[soln[i]][candidate] > 0)
                return false;
        return true;
    }
    return false;
}

void backtrack(vector<int> &soln, int k, int N, vector<vector<int> > &compareMatrix,
               vector<int> &nsmaller, vector<int> &nlarger, vector<bool> &used, vector<char> &reverseMap) {
    if (k == N) {
         for (int i = 0; i < N; i++)
            (i > 0) ? cout << " " << reverseMap[soln[i]] : cout << reverseMap[soln[i]];
        cout << endl;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isCandidate(soln, k, N, compareMatrix, nsmaller, nlarger, used, i)) {
            used[i] = true;
            soln.push_back(i);
            backtrack(soln, k + 1, N, compareMatrix, nsmaller, nlarger, used, reverseMap);
            used[i] = false;
            soln.pop_back();
        }
    }
}

int main() {
	int ncases, n, src, dst, N = 0;
	char c;
	string line, temp;

	cin >> ncases; getline(cin, line);
	while (ncases--) {
	    getline(cin, line); /* Drain empty line */
        getline(cin, line);
        stringstream ss(line);
        map<char, int> m; /* Indexer */
        vector<char> reverseMap;
        n = 0;
        while (ss >> c) {
            m[c] = n++;
            reverseMap.push_back(c);
        }

        /* compareMatrix[i][j] is true if and only if i < j */
        vector<vector<int> > compareMatrix(n, vector<int>(n, 0));

        getline(cin, line);
        stringstream ss2(line);

        bool isPossible = true;
        while (ss2 >> temp && isPossible) {
            src = m[temp[0]];
            dst = m[temp[2]];
            for (int i = 0; i < n && isPossible; i++) {
                if (compareMatrix[i][src] == -1) {
                    if (i == dst) { /* We have a contradiction */
                        isPossible = false;
                    } else {
                        if (compareMatrix[i][dst] == 1) { /* We have a contradiction */
                            isPossible = false;
                        } else {
                            compareMatrix[i][dst] = -1;
                            compareMatrix[dst][i] = 1;
                        }
                    }
                }
            }
            if (isPossible) {
                compareMatrix[src][dst] = -1; /* true, src < dst */
                compareMatrix[dst][src] = 1;
            }
        }
        if (N++)
            cout << endl;
        if (isPossible) {
            /* Fast way to find out how many elements some X is larger than (nlarger[X]) */
            vector<int> nlarger(n, 0), nsmaller(n, 0), soln;
            vector<bool> used(n, false);
            for (int j = 0; j < n; j++)
                for (int i = 0; i < n; i++)
                    if (compareMatrix[i][j] == -1)
                        nlarger[j]++;
                    else if (compareMatrix[i][j] == 1)
                        nsmaller[j]++;
            backtrack(soln, 0, n, compareMatrix, nsmaller, nlarger, used, reverseMap);
        } else
            cout << "NO" << endl;
	}
    return 0;
}
