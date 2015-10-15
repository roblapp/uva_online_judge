#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/*
Accepted: 0.000s
Description: use sorting/hashing
*/
#define read cin

using namespace std;

int main() {
    int i, j, k, len, ncases;
    string line, sortedLine;
    map<string, vector<string> > m;
    vector<string> bucket;
    vector<string> soln;
    read >> ncases; getline(read, line); getline(read, line);
    for (k = 0; k < ncases; k++) {
        m.clear(); soln.clear();
        while (getline(read, line) and line != "") {
            sortedLine = "";
            for (j = 0, len = line.length(); j < len; j++) {
                if (!isspace(line[j])) sortedLine += line[j];
            }
            sort(sortedLine.begin(), sortedLine.end());
            m[sortedLine].push_back(line);
        }
        if (k > 0) cout << endl;
        for (map<string, vector<string> >::iterator it = m.begin(); it != m.end(); it++) {
            bucket = it->second;
            len = bucket.size();
            if (len > 1) {
                sort (bucket.begin(), bucket.end());
                for (i = 0; i < len - 1; i++) {
                    for (j = i + 1; j < len; j++) {
                        soln.push_back(bucket[i] + " = " + bucket[j]);
                    }
                }
            }
        }
        sort(soln.begin(), soln.end());
        for (vector<string>::iterator it = soln.begin(); it != soln.end(); it++) {
            cout << *it << endl;
        }
    }
    return 0;
}
