#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>

/*
Accepted: 0.000s
Category: string processing, simple encode/decode
Algorithm: ad-hoc, hashing
*/

using namespace std;

string reverseNum(int x) { /* use a string to preserve leading 0's (i.e. 100 reversed = 001) */
    stringstream ss("");
    while (x > 0) {
        ss << x%10;
        x /= 10;
    }
    return ss.str();
}

void initMap(map<string,char> &m) {
    for (int i = 65; i <= 90; i++)
        m[reverseNum(i)] = (char) i;
    for (int i = 97; i <= 122; i++)
        m[reverseNum(i)] = (char) i;
    m["23"] = ' '; m["33"] = '!'; m["44"] = ',';
    m["64"] = '.'; m["85"] = ':'; m["95"] = ';'; m["36"] = '?';
}

void encode(string &s) {
    stringstream ss("");
    for (int i = s.length()-1; i >= 0; i--)
        ss << reverseNum((int) s[i]);
    cout << ss.str() << endl;
}

void decode(map<string,char> &m, string &s) {
    int i = 0, N = s.length();
    map<string,char>::iterator it;
    stringstream ss("");
    while (i < N) {
        if (i + 2 <= N) {
            it = m.find(s.substr(i, 2));
            if (it == m.end()) {
                it = m.find(s.substr(i, 3));
                if (i + 3 > N or it == m.end()) {
                    /* fatal error */
                    return;
                }
                ss << it->second;
                i += 3;
            } else  {
                ss << it->second;
                i += 2;
            }
        } else {
            /* fatal error */
            return;
        }
    }
    string temp = ss.str();
    reverse(temp.begin(), temp.end());
    cout << temp << endl;
}

int main() {
	string line;
	map<string,char> m;

	initMap(m);
	while (getline(cin, line))
        (isdigit(line[0])) ? decode(m, line) : encode(line);

    return 0;
}
