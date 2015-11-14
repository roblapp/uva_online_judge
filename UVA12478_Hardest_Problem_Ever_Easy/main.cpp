#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

/*
Accepted: N/A
Description: ad-hoc
Info: I ran this program to find the answer, but submitted
a program with only one print statement with the final result.
*/

#define read cin

using namespace std;

/* stringToFind is already sorted */
int findPermutedString(string &stringToFind, string &stringToSearch, int startPos) {
    int i = 0, len = stringToFind.length(), lenFind = stringToSearch.length();
    string temp;
    while (i + len <= lenFind) {
        temp = stringToSearch.substr(i, len);
        sort(temp.begin(), temp.end());
        if (temp.compare(stringToFind) == 0) {
            return i;
        }
        i++;
    }
    return (-1);
}

bool findName(vector<string> &v, string d[], map<string, int> &m, int &soln) {
    int i, j, findex, len, flen, f;
    for (i = 0; i < 9; i++) {
        len = v[i].length();
        for (j = 0; j < 8; j++) {
            findex = 0;
            flen = len - d[j].length();
            while (findex <= flen && (f = findPermutedString(d[j], v[i], findex)) >= 0) {
                m[d[j]]++;
                if (m[d[j]] > 1) {
                    soln = j;
                    return true;
                }
                findex = f + flen + 1;
            }
        }
    }
    return false;
}

int main() {
    int i, j, soln;
    string line;
    vector<string> v;
    map<string, int> m;
    string d[] = {"RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI"};
    string dp[] = {"RAKIBUL", "ANINDYA", "MOSHIUR", "SHIPLU", "KABIR", "SUNNY", "OBAIDA", "WASI"};
    for (i = 0; i < 8; i++) {
        sort(d[i].begin(), d[i].end());
        m[d[i]] = 0;
    }
    for (i = 0; i < 9; i++) {
        getline(read, line);
        v.push_back(line);
    }
    if (!findName(v, d, m, soln)) {
        vector<string> vi;
        string temp;
        for (i = 0; i < 9; i++) {
            temp = "";
            for (j = 0; j < 9; j++) {
                temp += v[j][i];
            }
            vi.push_back(temp);
        }
        if (!findName(vi, d, m, soln)) {
            cout << "No name appears twice" << endl;
        } else {
            cout << dp[soln] << endl;
        }
    } else {
        cout << dp[soln] << endl;
    }
    return 0;
}
