#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <sstream>

/*
Accepted: 0.013s
Description: data structures - maps, sets, string processing/parsing
Info: see http://www.udebug.com/UVa/10686 - I would not have gotten this right
had it not been for uDebug!
*/

#define read cin

using namespace std;

struct Entry {
    string category;
    set<string> wordsFound;
    size_t numWordsNeeded;
};

string preProcess(string &s) {
    string result = "";
    for (int i = 0, len = s.length(); i < len; i++) {
        if (isalpha(s[i]))
            result += s[i];
    }
    return s;
}

void process(map<string, set<int> > &m, vector<Entry> &v, string &s) {
    map<string, set<int> >::iterator mit = m.find(s);
    if (mit != m.end()) { /* If it is a keyword... */
        /* For each category the word is in */
        for (set<int>::iterator sit = mit->second.begin(); sit != mit->second.end(); sit++) {
            v[*sit].wordsFound.insert(mit->first);
        }
    }
}

void split_process(map<string, set<int> > &m, vector<Entry> &v, string &s) {
    int i = 0;
    bool state = false;
    string data = "";
    while (s[i]) {
        if (isalpha(s[i])) {
            data += s[i];
            state = true;
        } else {
            if (state) {
                process(m, v, data);
                data = "";
            }
            state = false;
        }
        i++;
    }
    if (state) {
        process(m, v, data);
        data = "";
    }
}

string trim(string &s) {
    string res = "";
    for (int i = 0; s[i]; i++)
        if (!isspace(s[i])) res += s[i];
    return res;
}

int main() {
    int ncases, nkeywords, value, nsubwords, vindex, solnCount;
    string line, category, keyword;
    vector<Entry> v;
    map<string, set<int> > m;
    Entry e;
    getline(read, line);
    stringstream ss(line);
    ss >> ncases;
    for (int i = 0; i < ncases; i++) {
        vindex = -1;
        solnCount = 0;
        m.clear(); v.clear();
        getline(read, line);
        stringstream ss2(line);
        ss2 >> nkeywords;
        for (int j = 0; j < nkeywords; j++) {
            getline(read, line);
            stringstream ss3(line);
            ss3 >> category >> nsubwords >> value;
            e.category = category;
            e.numWordsNeeded = value;
            v.push_back(e);
            vindex++;
            for (int k = 0; k < nsubwords; k++) {
                getline(read, keyword);
                m[trim(keyword)].insert(vindex);
            }
        }
        while (getline(read, line) && !line.empty()) {
            split_process(m, v, line);
        }
        for (int j = 0; j <= vindex; j++) {
            if (v[j].wordsFound.size() >= v[j].numWordsNeeded) {
                if (solnCount > 0) cout << "," << v[j].category;
                else cout << v[j].category;
                solnCount++;
            }
        }
        if (solnCount == 0) {
            cout << "SQF Problem.";
        }
        cout << endl;
    }
    return 0;
}
