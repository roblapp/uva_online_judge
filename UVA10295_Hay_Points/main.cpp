#include <iostream>
#include <map>

/*
Accepted: 0.000s
Description: data structures - maps
*/

#define read cin

using namespace std;

int main() {
    int nwords, ndescriptions, value, sum;
    string s;
    map<string, int> m;
    read >> nwords >> ndescriptions;
    getline(read,  s); /* Drain newline */
    for (int i = 0; i < nwords; i++) {
        read >> s >> value;
        m[s] = value;
        getline(read, s); /* Drain newline */
    }
    for (int i = 0; i < ndescriptions; i++) {
        sum = 0;
        while (read >> s && s != ".")
            if (m.find(s) != m.end())
                sum += m[s];
        cout << sum << endl;
    }
    return 0;
}
