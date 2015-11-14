#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: ad-hoc
Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3166
*/

#define read cin

using namespace std;

struct Element {
    string link;
    int x;
};

typedef struct Element Element;

int main() {
    int i, ncases, x, m, N = 1;
    string line;
    Element e;
    vector<Element> v;
    read >> ncases; getline(read, line);
    while (ncases--) {
        m = -1;
        v.clear();
        for (i = 0; i < 10; i++) {
            read >> line;
            read >> x;
            e.link = line;
            e.x = x;
            if (x > m) m = x;
            v.push_back(e);
        }
        cout << "Case #" << N++ << ":" << endl;
        for (i = 0; i < 10; i++) {
            if (v[i].x == m)
                cout << v[i].link << endl;
        }
    }
    return 0;
}
