#include <iostream>
#include <algorithm>

/*
Accepted: 0.000s
Category: string processing, parsing
Algorithm: ad-hoc parsing
*/

using namespace std;

string splitProcess(string &s, string &soln, int &maxLen) {
    bool state = false;
    string temp = "";
    int len = 0;
    for (int i = 0; s[i]; i++) {
        if (isalpha(s[i]) or s[i] == '-') {
            state = true;
            temp += tolower(s[i]);
            len++;
        } else {
            if (state and temp != "e-n-d" and len > maxLen) {
                soln = temp;
                maxLen = len;
            }
            temp = "";
            len = 0;
            state = false;
        }
    }
    if (state and temp != "e-n-d" and len > maxLen) {
        soln = temp;
        maxLen = len;
    }
    return soln;
}

int main() {
	string line, soln = "";
	int maxLen = 0;

	while (getline(cin, line)) {
        splitProcess(line, soln, maxLen);
	}
	cout << soln << endl;
    return 0;
}
