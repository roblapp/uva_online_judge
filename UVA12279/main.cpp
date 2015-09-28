#include <iostream>

/*
Accepted: 0.003s
*/
using namespace std;

int main() {
    int ncases, x, a, b, i = 1;
    while (cin >> ncases && ncases != 0) {
        a = b = 0;
        while (ncases--) {
            cin >> x;
            if (x == 0)  b++;
            else a++;
        }
        cout << "Case " << i++ << ": " << (a-b) << endl;
    }
    return 0;
}
