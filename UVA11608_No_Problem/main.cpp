#include <iostream>
#include <vector>

/*
Accepted: 0.000s
Description: ad-hoc/1D array processing
*/

#define read cin

using namespace std;

int main() {
    int i, nproblems, x, N = 1;
    vector<int> problems;
    vector<int> contests;
    while (read >> nproblems && nproblems >= 0) {
        problems.clear(); contests.clear();
        problems.push_back(nproblems);
        for (i = 0; i < 12; i++) {
            read >> x;
            problems.push_back(x);
        }
        for (i = 0; i < 12; i++) {
            read >> x;
            contests.push_back(x);
        }
        cout << "Case " << N++ << ":" << endl;
        for (i = 0; i < 12; i++) {
            if (problems[i] >= contests[i]) {
                cout << "No problem! :D" << endl;
                x = problems[i] - contests[i];
            } else {
                cout << "No problem. :(" << endl;
                x = problems[i];
            }
            problems[i+1] += x;
        }
    }
    return 0;
}
