#include <iostream>
#include <cmath>
#include <sstream>
#include <fstream>

using namespace std;

int solve(int ncoins);

int solve(int startIndex, int endIndex, int ncoins, int totalCoinsFromTheStart);

int main() {
    int ncases, ncoins;

    cin >> ncases;
    while (ncases--) {
        cin >> ncoins;
        int result = solve(1, ncoins, ncoins, ncoins);
        cout << "Answer " << result << endl;
    }
    return 0;
}

int solve(int ncoins) {
    return solve(1, ncoins, ncoins, ncoins);
}

int solve(int startIndex, int endIndex, int ncoins, int totalCoinsFromTheStart) {
    int partitionSize = (int) ceil(1.0*ncoins/3);
    int right = ncoins - 2*partitionSize;

    cout << "startIndex=" << startIndex << ", endIndex=" << endIndex << endl;
    cout << "partitionSize=" << partitionSize << ", right=" << right << endl;

    stringstream ss;
    ss << "Test";
    for (int i = startIndex, counter = 0, stop = 2*partitionSize; counter < stop; counter++, i++) {
        ss << " " << i;
    }
    cout << ss.str() << endl;

    int result;
    cin >> result;
    if (result == 0) {
        if (right == 1) {
                cout << "case1a" << endl;
            return startIndex + 2*partitionSize;
        } else {
            cout << "case1b" << endl;
            return solve(startIndex + 2*partitionSize, endIndex, right, totalCoinsFromTheStart);
        }
    } else if (result == -1) { /* -1 means the scale tipped this way \ */
        if (partitionSize == 1) { /* 1 means the scale tipped this way / */
                cout << "case2a" << endl;
            return startIndex + partitionSize;
        }
        cout << "case2b" << endl;
        return solve(startIndex + partitionSize, startIndex + 2*partitionSize - 1, partitionSize, totalCoinsFromTheStart);
    }
    if (partitionSize == 1) {
            cout << "case3a" << endl;
        return startIndex;
    }
    cout << "case3b" << endl;
    return solve(startIndex, startIndex + partitionSize - 1, partitionSize, totalCoinsFromTheStart);
}


