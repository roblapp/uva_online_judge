#include <iostream>

/*
Accepted: 0.000s
Description: ad hoc
Info: this problem requires no programming knowledge or mathematical
knowledge. Possibly the dumbest problem I have ever seen.
*/
using namespace std;

int main() {
    int ncases, a, b;
    cin >> ncases;
    while (ncases--) {
        cin >> a >> b;
        if (a == b) cout << "=" << endl;
        else if (a < b) cout << "<" << endl;
        else cout << ">" << endl;
    }
    return 0;
}
