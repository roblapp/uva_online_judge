#include <iostream>

/*
Accepted: 0.000s
*/
using namespace std;

int main() {
    int ncases, sum = 0, x;
    string line;
    cin >> ncases; getline(cin, line);
    while (ncases--) {
        cin >> line;
        if (line == "donate") {
            cin >> x; getline(cin, line);
            sum += x;
        } else cout << sum << endl;
    }
    return 0;
}
