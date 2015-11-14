#include <iostream>
#include <map>

/*
Accepted: 0.036s
Description: data structures - maps, recursion
*/

#define read cin
#define MAXLEN 5

using namespace std;

void generateStrings(map<string, int> &m, char s[], int position, int length, int &counter) {
    if (position == length) {
        s[position] = 0;
        m[s] = ++counter;
        return;
    }
    char startPoint = (position == 0) ? 'a' : s[position-1] + 1;
    for (char c = startPoint; c <= 'z'; c++) {
        s[position] = c;
        generateStrings(m, s, position + 1, length, counter);
    }
}

int main() {
    map<string, int> m;
    map<string, int>::iterator it;
    string line;
    char s[MAXLEN + 1];
    int counter = 0;
    for (int length = 1; length <= 5; length++)
        generateStrings(m, s, 0, length, counter);
    while (getline(read, line)) {
        it = m.find(line);
        (it == m.end()) ? cout << "0" << endl : cout << it->second << endl;
    }
    return 0;
}
