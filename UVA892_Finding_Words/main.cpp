#include <iostream>

/*
Accepted: 0.000s
Category: string processing, parsing, ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

void printContent(string &temp, string &prev) {
    if (!prev.empty()) {
        if (!temp.empty()) {
            cout << prev << temp << endl;
            temp = prev = "";
        }
    } else { /* prev is empty */
        if (!temp.empty()) {
            cout << temp;
            temp = "";
        }
    }
}

void filterAndStrip(string &s, string &prev) {
    int i = 0, N = (int) s.length();
    bool ignoreLast = false;
    bool prevHasContent = !prev.empty();
    bool tempHasContent = false;

    if (N == 0 and prevHasContent) {
        cout << prev << endl;
    }

    string temp = "";
    while (i < N) {
        if (isspace(s[i])) {
            if (prevHasContent or tempHasContent) {
                printContent(temp, prev);
            }
            tempHasContent = prevHasContent = false;
            cout << s[i];
        } else if (isalpha(s[i])) {
            temp += s[i];
            tempHasContent = true;
        } else if (s[i] == '-' and i + 1 == N){
            if (tempHasContent) {
                prev = temp;
                ignoreLast = true;
                tempHasContent = false;
            }
        } else {
            /* do nothing */
        }
        i++;
    }
    if (!ignoreLast and tempHasContent) {
        cout << temp;
    }
    cout << endl;
}

int main() {
	string line, prevStr = "";

	while (getline(cin, line) and line != "#") {
        filterAndStrip(line, prevStr);
	}
    return 0;
}
