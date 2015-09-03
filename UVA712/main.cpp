#include <iostream>
#include <vector>
#include <cctype>

/*
ACCEPTED 0.000s

How did that happen?
*/
#define DIFF 48
#define myfile cin

using namespace std;

int main() {
    int n, nfunc, lo, mid, hi, N = 1, val;
    string line;
    vector<int> ordering, rootNodes, input;
    while (myfile >> n && n != 0) {
        getline(myfile, line); /* eat up newline */ getline(myfile, line);
        ordering.clear(); rootNodes.clear();
        for (int i = 0, len = line.length(); i < len; i++) {
            if (isdigit(line[i])) {
                ordering.push_back(line[i] - DIFF);
            }
        }
        getline(myfile, line);
        for (int i = 0, len = line.length(); i < len; i++) {
            rootNodes.push_back(line[i] - DIFF);
        }
        myfile >> nfunc;
        getline(myfile, line);
        cout << "S-Tree #" << N++ << ":" << endl;
        while (nfunc--) {
            getline(myfile, line);
            input.clear();
            for (int i = 0, len = line.length(); i < len; i++) {
                input.push_back(line[i] - DIFF);
            }
            lo = 0, hi = rootNodes.size(), mid = (hi + lo) / 2;
            for (vector<int>::iterator it = ordering.begin(); it != ordering.end(); it++) {
                val = input[*it - 1];
                if (val == 0) {
                    hi = mid;
                } else {
                    lo = mid;
                }
                mid = (hi + lo) / 2;
            }
            cout << rootNodes[mid];
        }
        cout << endl << endl;
    }

    return 0;
}
