#include <iostream>

using namespace std;

int main() {
    int ncases, w, h, l, i = 1;
    cin >> ncases;
    while (ncases--) {
        cin >> w >> h >> l;
        (w > 20 or h > 20 or l > 20) ? cout << "Case " << i++ << ": bad" << endl
            : cout << "Case " << i++ << ": good" << endl;
    }
    return 0;
}
