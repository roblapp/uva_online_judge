#include <iostream>
#include <iomanip>
#include <map>

/*
Accepted: 0.273s
Description: easy hashing problem
*/

#define read cin

using namespace std;

int main() {
    int ncases, x, val;
    char c;
    map<char,int> m;
    map<char,int>::iterator it;
    unsigned long long sum;
    string line;
    read >> ncases;
    while (ncases--) {
        m.clear(); sum = 0;
        read >> x; getline(read, line); /* Eat newline */
        while (x--) {
            read >> c >> val;
            m[c] = val;
        }
        read >> x; getline(read, line);
        while (x--) {
            getline(read, line);
            for (int i = 0; line[i]; i++) {
                it = m.find(line[i]);
                if (it != m.end())
                    sum += it->second;
            }
        }
        cout << (sum/100) << "." << setw(2) << setfill('0') << (sum%100) << "$" << endl;
    }
    return 0;
}
