#include <iostream>
#include <map>

/*
Accepted: 0.363s
Description: data structures - maps, sets
*/

#define read cin

using namespace std;

int main() {
    int ncases, NA, NB, x, sum;
    map<int, int> m;
    map<int, int>::iterator it;

    read >> ncases;
    while (ncases--) {
        sum = 0;
        m.clear();
        read >> NA >> NB;
        for (int i = 0; i < NA; i++) {
            read >> x;
            if ((it = m.find(x)) == m.end())
                m[x] = 1;
            else
                it->second = it->second + 1;
        }
        for (int i = 0; i < NB; i++) {
            read >> x;
            if ((it = m.find(x)) != m.end()) {
                if (it->second == 1)
                    m.erase(x);
                else
                    it->second = it->second - 1;
            }
            else
                sum++;
        }
        for (it = m.begin(); it != m.end(); it++)
            sum += it->second;
        cout << sum << endl;
    }
    return 0;
}
