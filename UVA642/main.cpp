#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
Accepted: 0.000s
Description: hashing/sorting
*/

#define read cin

using namespace std;

int main() {
    map<string, vector<string> > m;
    string line;
    string sortedLine;
    while (getline(read, line) and line != "XXXXXX") {
        sortedLine = line;
        sort(sortedLine.begin(), sortedLine.end());
        m[sortedLine].push_back(line);
    }
    while (getline(read, line) and line != "XXXXXX") {
        sortedLine = line;
        sort(sortedLine.begin(), sortedLine.end());
        map<string, vector<string> >::iterator it = m.find(sortedLine);
        if (it != m.end()) {
            vector<string> bucket = m.find(sortedLine)->second;
            sort(bucket.begin(), bucket.end());
            for (vector<string>::iterator it = bucket.begin(); it != bucket.end(); it++) {
                cout << *it << endl;
            }
        } else {
            cout << "NOT A VALID WORD" << endl;
        }
        cout << "******" << endl;
    }
    return 0;
}
