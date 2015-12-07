#include <iostream>
#include <vector>
#include <map>

/*
Accepted: 0.315s
Description: data structures - graphs/adjacency lists
*/

using namespace std;

#define read cin
#define out cout
#define MAXN 100000 + 1

int main() {
    int n, m, x, k, pos, v, prevMaxElement = 0;
    map<int, int> mIndexer;
    map<int, int>::iterator mit;
    vector<int> g[MAXN]; /* g[x] gives us a vector that represents the position in the sequence the number occurs */

    while (read >> n >> m) {
        k = 0;
        mIndexer.clear();
        for (int i = 0; i <= prevMaxElement; i++) g[i].clear();
        for (int i = 0; i < n; i++) {
            read >> x;
            if ((mit = mIndexer.find(x)) == mIndexer.end()) { /* Assign an index */
                mIndexer[x] = k;
                pos = k;
                k++;
            } else
                pos = mit->second;
            prevMaxElement = max(prevMaxElement, pos);
            g[pos].push_back(i + 1);
        }
        vector<int> vn;
        for (int i = 0; i < m; i++) {
            read >> k >> v;
            vn = g[mIndexer[v]];
            if (k > (int) vn.size())
              out << "0" << endl;
            else
               out << vn[k-1] << endl;
        }
    }
    return 0;
}
