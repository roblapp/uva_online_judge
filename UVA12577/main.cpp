#include <iostream>

/*
Accepted: 0.000s
*/
using namespace std;

int main() {
    int i = 1; string line;
    while (cin >> line and line != "*")
        (line == "Hajj") ? cout << "Case " << i++ << ": " << "Hajj-e-Akbar" << endl
            : cout << "Case " << i++ << ": " << "Hajj-e-Asghar" << endl;
    return 0;
}
