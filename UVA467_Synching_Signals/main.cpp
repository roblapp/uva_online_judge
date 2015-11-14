#include <iostream>
#include <vector>
#include <sstream>

/*
Accepted: 0.109s
Description: ad-hoc/1D array processing
*/

#define MAXN 60*60 + 2
#define read cin

using namespace std;

int main() {
    string line;
    int i, j, k, x, N, minTime, greenTime, nonGreenTime, mins, secs, NS = 1;
    vector<int> v;
    vector<bool> soln(MAXN);
    while (getline(read, line)) {
        v.clear(); soln.clear();
        stringstream ss(line);
        minTime = MAXN;
        while (ss >> x) {
            v.push_back(x);
            minTime = min(minTime, 2*x);
        }
        N = v.size();
        for (i = 0; i < MAXN; i++) soln[i] = true;
        for (i = 0; i < N; i++) {
            greenTime = v[i] - 5;
            nonGreenTime = v[i] + 5;
            j = greenTime + 1;
            while (j < MAXN) { /* Mark positions false where they are red*/
                for (k = 0; j < MAXN && k < nonGreenTime; k++) {
                    soln[j++] = false;
                }
                j += greenTime;
            }
        }

        for (i = minTime; i < MAXN && !soln[i]; i++) ;
        if (i < MAXN) {
            mins = (i-1) / 60;
            secs = (i-1) % 60;
            cout << "Set " << NS++ << " synchs again at " << mins <<
                    " minute(s) and " << secs << " second(s) after all turning green." << endl;
        } else {
            cout << "Set " << NS++ << " is unable to synch after one hour." << endl;
        }
    }
    return 0;
}
