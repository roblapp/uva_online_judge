#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <set>

/*
Accepted: 0.000s
Description: data structures - sets, ad-hoc, parsing
*/

#define read cin

using namespace std;

void processWord(set<string> &s, string &word) {
    if (!word.empty())
        s.insert(word);
    word = "";
}

int main() {
    char c;
    string word = "";
    set<string> s;
    while (1) {
        c = getchar();
        if (c == EOF)
            break;
        if (c == '-') {
            char nextc = getchar();
            if (nextc != '\n') {
                word += c;
                if (!isalpha(nextc))
                    processWord(s, word);
                else
                    word += tolower(nextc);
            }
        } else if (!isalpha(c))
            processWord(s, word);
        else
            word += tolower(c);
    }
    processWord(s, word);
    for (set<string>::iterator it = s.begin(); it != s.end(); it++)
        cout << *it << endl;
    return 0;
}
