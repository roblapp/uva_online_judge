#include <iostream>
#include <sstream>

/*
Accepted: 0.000s
Category: strings, parsing
Algorithm: ad-hoc parsing
*/

using namespace std;

/* returns next index to be processed */
int readDecimal(string &s, int startIndex) {
    int i = startIndex, n = s.length();
    bool readDec = false;
    bool hasReadDigit = false;
    while (i < n) {
        if (s[i] == '.') {
            if (!readDec) {
                readDec = true;
            } else {
                if (i > 0 and s[i-1] == '.') /* a case like this: /s..The output should be/s -> ..The output should be */
                    return i - 1;
                return i; /* /s.05.Another case/s -> .Another case */
            }
        } else if (isdigit(s[i])) {
            hasReadDigit = true;
        } else {
            if (readDec and !hasReadDigit) { /* if we read a decimal but no digit, we need to process the . as a regular char */
                i--;
            } else {
                ; /* */
            }
            break;
        }
        i++;
    }
    return i;
}

int main() {
	string s;
	bool processingOn = true;

	while (getline(cin, s)) {
        if (s.empty()) {
            cout << endl;
        } else {
            int i = 0, n = s.length();
            stringstream ss("");
            while (i < n) {
                if (!processingOn) {
                    if (s[i] == '\\' and i + 1 < n and s[i+1] == '*') {
                        processingOn = true;
                        i += 2;
                    } else {
                        ss << s[i];
                        i++;
                    }
                } else { /* The processing is on */
                    if (s[i] == '\\' and i + 1 < n) {
                        if (s[i+1] == 'b' or s[i+1] == 'i') {
                            i += 2;
                        } else if (s[i+1] == 's') {
                            i = readDecimal(s, i+2);
                        } else if (s[i+1] == '*') {
                            processingOn = false;
                            i += 2;
                        } else if (s[i+1] == '\\') { /* \ literal */
                            ss << s[i+1];
                            i += 2;
                        } else {
                            ss << s[i+1];
                            i += 2;
                        }
                    } else { /* ignore a single \ at the end of a sentence */
                        if (s[i] != '\\')
                            ss << s[i];
                        i++;
                    }
                }
            } /* end while (i < n) */
            cout << ss.str() << endl;
        } /* end if (line.empty()) else */
	} /* end while (getline(cin, line)) */
    return 0;
}
