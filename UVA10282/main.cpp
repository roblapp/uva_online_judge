#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>

/* ACCEPTED 0.902s */
/*
Algorithm:

Hashing
*/

#define MAXLINE 1000

using namespace std;

int main() {

    char line[MAXLINE], a[MAXLINE >> 1], b[MAXLINE >> 1];
    map<string, string> m;
    map<string, string>::iterator it;

    while (fgets(line, MAXLINE, stdin)) {
        if (sscanf(line, "%s %s", a, b) != 2) { break; }
        string sa(a); string sb(b);
        m[sb] = sa;
    }

    while (scanf("%s", a) == 1) {
        string sa(a);
        it = m.find(a);
        (it == m.end()) ? cout << "eh" << endl : cout << it->second << endl;
    }

    return 0;
}
