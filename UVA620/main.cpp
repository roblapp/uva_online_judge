#include <iostream>
#include <string>

/* ACCEPTED 0.000s How does this keep happening? */

#define read cin

using namespace std;

bool match(const string &s) {
    int len = s.length();
    if (len < 1) {
        return false;
    } else if (s == "A") {
        return true;
    } else if (len > 2 && s.substr(len - 2, len - 1) == "AB" && match(s.substr(0, len - 2))) {
        return true;
    } else if (len > 2 && s[0] == 'B' && s[len-1] == 'A' && match(s.substr(1, len - 2))) {
        return true;
    }
    return false;
}

int main() {
    int ncases, len;
    string s;
    read >> ncases; getline(read, s);
    while (ncases--) {
        getline(read, s);
        len = s.length();
        if (s == "A") {
            cout << "SIMPLE" << endl;
        } else if (len > 2 && s.substr(len - 2, len - 1) == "AB" && match(s.substr(0, len - 2))) {
            cout << "FULLY-GROWN" << endl;
        } else if (len > 2 && s[0] == 'B' && s[len-1] == 'A' && (match(s.substr(1, len - 2)))) {
            cout << "MUTAGENIC" << endl;
        } else {
            cout << "MUTANT" << endl;
        }
    }
    return 0;
}
