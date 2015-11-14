#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: ad-hoc
Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3947
*/

#define read cin

using namespace std;

int main() {
    int ncases, n, val, s;
    string line;
    vector<int> v;
    read >> ncases;
    while (ncases--) {
        read >> n; getline(read, line);
        val = 0;
        v.clear();
        while (n--) {
            read >> line;
            if (line == "LEFT") {
                val--;
                v.push_back(-1);
            } else if (line == "RIGHT") {
                val++;
                v.push_back(1);
            } else if (line == "SAME") {
                read >> line;
                read >> s;
                val += v[s-1];
                v.push_back(v[s-1]);
            }
            getline(read, line); /* Drain newline */
        }
        cout << val << endl;
    }
    return 0;
}
