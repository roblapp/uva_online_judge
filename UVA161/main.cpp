#include <iostream>
#include <cstring>
#include <iomanip>
#include <climits>
#include <fstream>

/*
ACCEPTED 0.003s
Algorithm: simulation
My Solution: create an array that represents time. One position in the array
corresponds to one second. Then, for each time we read, iterate through the
array and mark off where that corresponding light was green. Once each time/
light has been processed, iterate through and find the first element that has
a count equal to the number of traffic light times that we read. Thus, we know
that each light was green at this time if such a condition exists. If there was
not such condition, then output 'Signals fail to synchronise in 5 hours'
Warning: watch out for a condition like 10 20 40. (problem description was unclear)
*/

#define MAX_SECONDS 5*60*60

using namespace std;

int main() {
    int i, j, x, nzeros = 0, nread, greenTime, inc, mst;
    bool foundNonZero, found;
    int a[MAX_SECONDS + 1];
    while (nzeros < 3) {
        foundNonZero = false;
        nread = 0;
        memset(a, 0, sizeof(a));
        mst = INT_MAX;
        while (cin >> x && x != 0) {
            nread++;
            greenTime = x - 5;
            inc = 2*x;
            mst = min(mst, inc);
            for (i = 0; i <= MAX_SECONDS; i += inc)
                for (j = 0; i + j <= MAX_SECONDS && j < greenTime; j++)
                    a[i + j]++;
            foundNonZero = true;
        }
        if (!foundNonZero) nzeros++;
        else {
            found = false;
            for (i = mst; i <= MAX_SECONDS; i++) {
                if (a[i] == nread) {
                    x = (i % 3600);
                   cout << setw(2) << setfill('0') << (i / 3600)
                    << ":" << setw(2) << setfill('0') << (x / 60)
                    << ":" << setw(2) << setfill('0') << (x % 60) << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Signals fail to synchronise in 5 hours" << endl;
            }
        }
    }
    return 0;
}
