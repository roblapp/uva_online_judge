#include <iostream>

using namespace std;

bool isOneOff(const string &a, const string &b) {
    int cnt = 0, len = a.length();
    for (int i = 0; cnt < 2 && i < len; i++) if (a[i] != b[i]) cnt++;
    return (cnt == 1);
}

int main() {
    int ncases;
    string line;
    cin >> ncases; getline(cin, line);
    while (ncases--) {
        getline(cin, line);
        if (isOneOff("one", line) or line == "one") cout << "1" << endl;
        else if (isOneOff("two", line) or line == "two") cout << "2" << endl;
        else cout << "3" << endl;
    }
    return 0;
}
