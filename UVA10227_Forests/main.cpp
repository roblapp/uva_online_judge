#include <iostream>
#include <set>
#include <sstream>

/*
Accepted: 0.000s
Description: data structures - sets (and sets of sets)
*/

using namespace std;

#define read cin
#define out cout
#define MAXN 100

int main() {
    int ncases, p, t, pi, tj;
    string line;
    set<set<int> > s;

    read >> ncases; getline(read, line); getline(read, line);
    while (ncases--) {
        s.clear();
        set<int> temp[MAXN];
        read >> p >> t; getline(read, line);
        while (getline(read, line) && !line.empty()) {
            stringstream ss(line);
            ss >> pi >> tj;
            temp[pi].insert(tj);
        }
        for (int i = 1; i <= p; i++)
            s.insert(temp[i]);
        out << s.size() << endl;
        if (ncases)
            out << endl;
    }
    return 0;
}
