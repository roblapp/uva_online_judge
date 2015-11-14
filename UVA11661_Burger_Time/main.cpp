#include <iostream>
#include <cmath>

/*
Accepted: 0.193s
Description: ad-hoc
Info: I am sure there is a cleaner way to do this, but
this works and is O(N).
*/

#define read cin

using namespace std;

int main() {
    int i, n, minCount, cnt;
    string line;
    bool foundCombo, seenAnR;
    while (read >> n && n != 0) {
        getline(read, line); /* Consume newline character */
        getline(read, line);
        cnt = 0;
        foundCombo = seenAnR = false;
        minCount = n;
        for (i = 0; i < n && !foundCombo; i++) { /* Scan L to R */
            if (line[i] == 'R') {
                seenAnR = true;
                cnt = 1;
            } else if (line[i] == 'D' && seenAnR) {
                minCount = min(minCount, cnt);
                cnt++;
            }
            else if (line[i] == 'Z') foundCombo = true;
            else if (seenAnR) cnt++;
        }
        if (foundCombo) {
            cout << "0" << endl;
        } else {
            cnt = 0;
            seenAnR = false;
            for (i = n - 1; i >= 0; i--) { /* Scan R to L */
                if (line[i] == 'R') {
                    seenAnR = true;
                    cnt = 1;
                } else if (line[i] == 'D' && seenAnR) {
                    minCount = min(minCount, cnt);
                    cnt++;
                }
                else if (line[i] == 'Z') foundCombo = true;
                else if (seenAnR) cnt++;
            }
            cout << minCount << endl;
        }
    }
    return 0;
}
