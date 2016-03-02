#include <iostream>
#include <map>

using namespace std;

void splitAndCountFreq(map<string,int> &m, map<string,int>::iterator &it, string &line) {
    bool state = false;
    string temp = "";
    for (int i = 0; line[i]; i++) {
        if (isalpha(line[i])) {
            temp += tolower(line[i]);
            state = true;
        } else {
            if (state) {
                if ((it = m.find(temp)) == m.end())
                    m[temp] = 1;
                else
                    it->second = it->second + 1;
                temp = "";
            }
            state = false;
        }
    }
    if (state) {
        if ((it = m.find(temp)) == m.end())
            m[temp] = 1;
        else
            it->second = it->second + 1;
    }
}

int main() {
	int freq, N = 0;
	string line;

	while (cin >> freq) {
        map<string,int> m;
        map<string,int>::iterator it;
        while (cin >> line and line != "EndOfText")
            splitAndCountFreq(m, it, line);

        if (N++)
            cout << endl;

        bool foundOne = false;
        for (it = m.begin(); it != m.end(); it++) {
            if (it->second == freq) {
                foundOne = true;
                cout << it->first << endl;
            }
        }
        if (!foundOne)
            cout << "There is no such word." << endl;
	}
    return 0;
}
