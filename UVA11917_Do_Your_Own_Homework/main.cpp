#include <iostream>
#include <map>

/*
Accepted: 0.003s
Description: data structures - maps, ad-hoc
*/

using namespace std;

#define read cin

int main() {
    int ncases, nwords, x, d, N = 1;
    string line;
    map<string, int> m;
    map<string, int>::iterator it;

    read >> ncases;
    while (ncases--) {
        read >> nwords; getline(read, line); /* Drain newline */
        m.clear();
        for (int i = 1; i <= nwords; i++) {
            read >> line >> x;
            m[line] = x;
            getline(read, line); /* Drain newline */
        }
        read >> d; getline(read, line); /* Drain newline */
        getline(read, line);
        it = m.find(line);
        if (it == m.end()) cout << "Case " << N++ << ": " << "Do your own homework!" << endl;
        else if (it->second <= d) cout << "Case " << N++ << ": " << "Yesss" << endl;
        else if (it->second <= d + 5) cout << "Case " << N++ << ": " << "Late" << endl;
        else cout << "Case " << N++ << ": " << "Do your own homework!" << endl;
    }
    return 0;
}
