#include <iostream>
#include <map>

/*
Accepted: 0.619s
Description: data structures - sorted sets
Info: horrible time on this... working on improving the
algorithm.
*/

using namespace std;

#define read cin

int main() {
    long long n, x, y, sum;
    map<long long, int> m;
    map<long long, int>::iterator it;
    map<long long, int>::reverse_iterator rit;

    while (read >> n && n != 0) {
        sum = 0;
        m.clear();
        for (int i = 0; i < n; i++) {
            read >> x;
            for (int j = 0; j < x; j++) {
                read >> y;
                it = m.find(y);
                if (it == m.end())
                    m[y] = 1;
                else
                    it->second = it->second + 1;
            }
            it = m.begin();
            rit = m.rbegin();
            sum += rit->first - it->first;
            if (it->second == 1)
                m.erase(it->first);
            else
                it->second = it->second - 1;
            if (rit->second == 1)
                m.erase(rit->first);
            else
                rit->second = rit->second - 1;
        }
        cout << sum << endl;
    }
    return 0;
}
