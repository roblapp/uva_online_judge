#include <iostream>
#include <map>

/*
Accepted: 0.362s
Description: data structures - maps
*/

using namespace std;

#define read cin

int main() {
    int ncases, n, x, lastIndex, maxLen;
    map<int, int> m;
    map<int, int>::iterator it;

    read >> ncases;
    while (ncases--) {
        read >> n;
        m.clear();
        lastIndex = maxLen = 0;
        for (int i = 0; i < n; i++) {
            read >> x;
            it = m.find(x);
            if (it == m.end()) {
                m[x] = i;
            } else {
                lastIndex = max(it->second + 1, lastIndex);
                it->second = i;
            }
            maxLen = max(maxLen, i - lastIndex + 1);
        }
        cout << maxLen << endl;
    }
    return 0;
}
