#include <iostream>
#include <string.h>
#include <string>
#include <stack>

/* ACCEPTED 0.012s */
/*
Algorithm:

This was a lowest common ancestor problem.
Simply traverse up the tree starting from both paths
until the first common node.
*/

#define in cin
#define ALPHA 26
#define DIFF 65
#define mset(a,b) memset(a, b, sizeof(a))

using namespace std;

void climb(int parent[], string& a, string& b) {

    int child = (b[0] - DIFF);
    bool used[ALPHA];
    mset(used, false);

    stack<int> s;

    while (child != -1) {
        s.push(child);
        used[child] = true;
        child = parent[child];
    }

    child = (a[0] - DIFF);

    while (!used[child]) {
        cout << ((char) (child + DIFF));
        child = parent[child];
    }

    while (s.top() != child) {
        s.pop();
    }

    while (!s.empty()) {
        cout << ((char) (s.top() + DIFF));
        s.pop();
    }

    cout << endl;
}

int main() {

    int ncases, p, q;
    string a, b;
    int parent[ALPHA];

    in >> ncases;

    for (int i = 0; i < ncases; i++) {
        if (i) cout << endl;
        in >> p >> q;
        mset(parent, -1);

        for (int j = 0; j < p; j++) {
            in >> a >> b;
            parent[b[0]-DIFF] = (a[0] - DIFF);
        }

        for (int j = 0; j < q; j++) {
            in >> a >> b;
            climb(parent, a, b);
        }
    }

    return 0;
}
