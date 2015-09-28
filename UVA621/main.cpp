#include <iostream>
/*
Accepted: 0.000s
*/
using namespace std;

int main() {
    int ncases, len;
    string line;
    cin >> ncases; getline(cin, line);
    while (ncases--) {
        getline(cin, line); len = line.length();
        if (line == "1" or line == "4" or line == "78") cout << "+" << endl;
        else if (len > 1 and line.substr(len - 2, 2) == "35") cout << "-" << endl;
        else if (len > 1 and line[0] == '9' and line[len-1] == '4') cout << "*" << endl;
        else if (len > 2 and line.substr(0, 3) == "190") cout << "?" << endl;
    }
    return 0;
}
