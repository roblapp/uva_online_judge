#include <iostream>
#include <map>
#include <vector>
#include <sstream>

/*
Accepted: 0.006s
Description: data structures - maps, parsing, ad-hoc
*/

using namespace std;

#define read cin

void parseToken(map<string, string> &m, string &token) {
    size_t index = token.find(":");
    if (index == string::npos)
        return;
    size_t startIndex = 0, endIndex = token.length();
    if (token[0] == '{')
        startIndex++;
    if (token[endIndex - 1] == '}')
        endIndex--;
    m[token.substr(startIndex, index - startIndex)] = token.substr(index + 1, endIndex - 1 - index);
}

void lineToMap(map<string, string> &m, string &line) {
    string token;
    char delim = ',';
    istringstream oldSS(line);
    while (getline(oldSS, token, delim))
        parseToken(m, token);
}

/* first find all values in b not in a */
void findNewKeys(map<string, string> &ma, map<string, string> &mb, vector<string> &v) {
    v.clear();
    for (map<string, string>::iterator it = mb.begin(); it != mb.end(); it++)
        if (ma.find(it->first) == ma.end())
            v.push_back(it->first);
}

/* first find all values in b not in a */
void findChangedValues(map<string, string> &ma, map<string, string> &mb, vector<string> &v) {
    v.clear();
    map<string, string>::iterator mit;
    for (map<string, string>::iterator it = mb.begin(); it != mb.end(); it++) {
        mit = ma.find(it->first);
        if (mit != ma.end() && mit->second != it->second)
            v.push_back(it->first);
    }
}

int main() {
    int n, len;
    string line, token;
    map<string, string> oldM, newM;
    vector<string> v;
    bool isChanged;

    read >> n; getline(read, line);
    while (n--) {
        oldM.clear(); newM.clear();
        isChanged = false;
        getline(read, line);
        lineToMap(oldM, line);
        getline(read, line);
        lineToMap(newM, line);
        findNewKeys(oldM, newM, v);
        if ((len = v.size()) > 0) {
            isChanged = true;
            cout << "+";
            for (int i = 0; i < len; i++)
                (i == 0) ? cout << v[i] : cout << "," << v[i];
            cout << endl;
        }
        findNewKeys(newM, oldM, v);
        if ((len = v.size()) > 0) {
            isChanged = true;
            cout << "-";
            for (int i = 0; i < len; i++)
                (i == 0) ? cout << v[i] : cout << "," << v[i];
            cout << endl;
        }
        findChangedValues(oldM, newM, v);
        if ((len = v.size()) > 0) {
            isChanged = true;
            cout << "*";
            for (int i = 0; i < len; i++)
                (i == 0) ? cout << v[i] : cout << "," << v[i];
            cout << endl;
        }
        if (!isChanged)
            cout << "No changes" << endl;
        cout << endl;
    }
    return 0;
}
