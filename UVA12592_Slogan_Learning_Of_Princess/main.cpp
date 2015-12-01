#include <iostream>
#include <map>

/*
Accepted: 0.000s
Description: data structures - maps, ad-hoc
*/

using namespace std;

#define read cin

int main() {
    int n;
    string a, b;
    map<string, string> m;

    read >> n; getline(read, a);
    while (n--) {
        getline(read, a);
        getline(read, b);
        m[a] = b;
    }
    read >> n; getline(read, a);
    while (n--) {
        getline(read, a);
        cout << m[a] << endl;
    }
    return 0;
}
