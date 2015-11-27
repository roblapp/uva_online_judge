#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

/*
Accepted: 0.159s
Description: data structures - maps
*/

using namespace std;

#define read cin
#define MAXN 5

int main() {
    map<string, int> m;
    string line, key;
    int n, x, a[MAXN], maxval, cnt;
    while (read >> n && n != 0) {
        m.clear();
        maxval = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < MAXN; j++) {
                read >> x;
                a[j] = x;
            }
            sort(a, a + MAXN);
            stringstream ss("");
            for (int j = 0; j < MAXN; j++)
                ss << a[j];
            key = ss.str();
            m[key] = (m.find(key) == m.end()) ? 1 : m[key] + 1;
            if (m[key] > maxval) maxval = m[key];
        }
        cnt = 0;
        for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
            if (it->second == maxval)
                cnt += maxval;
        cout << cnt << endl;
    }
    return 0;
}
