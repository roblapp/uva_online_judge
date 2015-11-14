#include <iostream>
#include <string>
#include <sstream>
#include <map>

/*
Accepted: 0.006s
Description: ad-hoc
*/

#define read cin

using namespace std;

int main() {
    int ncases, index, maxIndex;
    string a, b, temp;
    map<int, string> m;

    read >> ncases; getline(read, temp);
    for (int i = 1; i <= ncases; i++) {
        m.clear();
        maxIndex = 0;
        getline(read, temp); /* read blank line */
        getline(read, a);
        getline(read, b);
        stringstream ssa(a);
        stringstream ssb(b);
        while (ssa >> index) {
            ssb >> temp;
            m[index] = temp;
            maxIndex = max(maxIndex, index);
        }
        for (int j = 1; j <= maxIndex; j++) {
            cout << m[j] << endl;
        }
        if (i != ncases) cout << endl;
    }
    return 0;
}
