#include <iostream>
#include <algorithm>

/*
Accepted: 0.026s
Description: finding median in a 2d plane
Info: I copied this algorithm from https://tausiq.wordpress.com/2011/01/11/uva-855-lunch-in-grid-city/
*/

#define read cin
#define MAXN 50000 + 1

using namespace std;

int main() {
    int ncases, st, ave, friends;
    int p[MAXN];
    int q[MAXN];
    read >> ncases;
    while (ncases--) {
        read >> st >> ave >> friends;
        for (int i = 0; i < friends; i++) {
            read >> st >> ave;
            p[i] = st;
            q[i] = ave;
        }
        sort(p, p + friends);
        sort(q, q + friends);
        if (friends & 1) cout << "(Street: " << p[friends >> 1] << ", Avenue: " << q[friends >> 1] << ")" << endl;
        else cout << "(Street: " << p[(friends - 1) >> 1] << ", Avenue: " << q[(friends - 1) >> 1] << ")" << endl;
    }
    return 0;
}
