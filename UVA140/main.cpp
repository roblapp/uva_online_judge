#include <iostream>
#include <cstring>
#include <algorithm>
#include <climits>

#define MAXN 26
#define DIFF 65
#define SRC 1
#define DST 2
#define read cin
#define INF INT_MAX

/* ACCEPTED 0.026s */

using namespace std;

int main() {
    string line, graphString, solnGraphString;
    char c;
    bool v[MAXN], g[MAXN][MAXN];
    int state, src, neighbor, nvertices, glen, dist, maxdist, minmaxdist;
    while (1) {
        getline(read, line);
        if (line == "#") {
            break;
        }
        memset(v, false, sizeof(v));
        for (int i = 0; i < MAXN; i++)
            for (int j = 0; j < MAXN; j++) g[i][j] = false;
        state = SRC;
        nvertices = 0;
        graphString = "";
        for (int i = 0, len = line.length(); i < len; i++) {
            c = line[i];
            if (c == ':') {
                state = DST;
            } else if (c == ';') {
                state = SRC;
            } else if (state == SRC && c >= 'A' && c <= 'Z') {
                src = (c - DIFF);
            } else if (c >= 'A' && c <= 'Z') {
                neighbor = (c - DIFF);
                g[src][neighbor] = g[neighbor][src] = true;
                if (!v[src]) {
                    nvertices++;
                    graphString += (char) (src + DIFF);
                    v[src] = true;
                }
                if (!v[neighbor]) {
                    nvertices++;
                    graphString += (char) (neighbor + DIFF);
                    v[neighbor] = true;
                }
            }
        }
        sort(graphString.begin(), graphString.end());
        glen = graphString.length();
        solnGraphString = graphString;
        minmaxdist = INF;
        do {
            maxdist = 0;
            for (int i = 0; i < glen - 1; i++) { /* Compute distance between ith and jth char */
                for (int j = i + 1; j < glen; j++) {
                    if (g[graphString[i] - DIFF][graphString[j] - DIFF]) { /* If j is a neighbor of i */
                        dist = j - i;
                        if (maxdist < dist) {
                            maxdist = dist;
                        }
                    }
                }
            }
            if (maxdist < minmaxdist) {
                minmaxdist = maxdist;
                solnGraphString = graphString;
            }
        } while (next_permutation(graphString.begin(), graphString.end()));
       for (int i = 0; i < glen; i++) {
            cout << solnGraphString[i] << " ";
       }
       cout << "-> " << minmaxdist << endl;
    }

    return 0;
}
