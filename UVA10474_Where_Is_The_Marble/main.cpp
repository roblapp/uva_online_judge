#include <iostream>
#include <vector>

/*
Accepted: 0.792s
Description: ad-hoc
Info: I was confused as to what the problem was asking. After looking
around online I found that what they want is the position of a number in
an array if it was sorted. This can be done with binary search if you
sort the input.
*/

using namespace std;

#define read cin

int main() {
    int n, q, x, N = 1;

    while (read >> n >> q && (n != 0 || q != 0)) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            read >> x;
            v.push_back(x);
        }
        cout << "CASE# " << N++ << ":" << endl;
        for (int i = 0; i < q; i++) {
            read >> x;
            bool found = false;
            int pos = 1;
            for (int j = 0; j < n; j++) {
                if (v[j] < x) pos++;
                else if (v[j] == x) found = true;
            }
            if (found) cout << x << " found at " << pos << endl;
            else cout << x << " not found" << endl;
        }
    }
    return 0;
}
