#include <iostream>

/*
Accepted: 0.000s
Description: ad hoc, super easy
Info: simple numeric comparisons.
*/
using namespace std;

int main() {
    int ncases, dx, dy, x, y;
    while (cin >> ncases and ncases != 0) {
        cin >> dx >> dy;
        while (ncases--) {
            cin >> x >> y;
            if (x == dx or y == dy) cout << "divisa" << endl;
            else if (x > dx and y > dy) cout << "NE" << endl;
            else if (x < dx and y > dy) cout << "NO" << endl;
            else if (x > dx and y < dy) cout << "SE" << endl;
            else cout << "SO" << endl;
        }
    }
    return 0;
}
