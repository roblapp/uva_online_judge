#include <iostream>
#include <vector>
#include <sstream>

/*
Accepted: 0.136s
Description: data structures - graphs/adjacency lists
*/

using namespace std;

#define read cin
#define MAXN 1000 + 1

int main() {
    int ncases, n, x, sum, minsum, nsolns;
    string line;
    vector<int> g[MAXN];

    read >> ncases;
    for (int i = 0; i < ncases; i++) {
        read >> n; getline(read, line);
        minsum = n;
        nsolns = 0;
        for (int j = 1; j <= n; j++) {
            g[j].clear();
            getline(read, line);
            stringstream ss(line);
            sum = 0;
            while (ss >> x) {
                g[j].push_back(x);
                sum++;
            }
            if (sum == minsum) {
                nsolns++;
            } else if (sum < minsum) {
                minsum = sum;
                nsolns = 1;
            }
        }
        for (int j = 1; j <= n && nsolns > 0; j++) {
            if ((int) g[j].size() == minsum) {
                if (nsolns == 1) cout << j << endl;
                else cout << j << " ";
                nsolns--;
            }
        }
    }
    return 0;
}
