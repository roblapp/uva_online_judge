#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <iomanip>

/* ACCEPTED 0.000s */

using namespace std;

int main() {
    int ncases, nwords, N = 0;
    string s, sortedWord;
    map<string, vector<string> > d;
    map<string, vector<string> >::iterator it;
    cin >> ncases;
    while (ncases--) {
        cin >> nwords; getline(cin, s);
        d.clear();
        while (nwords--) {
            getline(cin, s);
            sortedWord = s;
            sort(sortedWord.begin(), sortedWord.end());
            d[sortedWord].push_back(s);
        }
        if (N++) { cout << endl; }
        while (getline(cin, s) && s != "END") {
            sortedWord = s;
            sort(sortedWord.begin(), sortedWord.end());
            it = d.find(sortedWord);
            cout << "Anagrams for: " << s << endl;
            if (it == d.end()) {
                cout << "No anagrams for: " << s << endl;
            } else {
                vector<string> &temp = it->second;
                int i = 1;
                for (vector<string>::iterator it2 = temp.begin(); it2 != temp.end(); it2++) {
                    cout << setw(3) << (i++) << ") " << *it2 << endl;
                }
            }
        }
    }
    return 0;
}
