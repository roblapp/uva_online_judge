#include <iostream>
#include <fstream>
#include <vector>
#include <climits>

/* ACCEPTED 0.019s */
/*
Algorithm:

Ad hoc
*/

#define in cin

using namespace std;

int main() {

    vector<long long int> v;
    long long int n, m, temp, k;
    bool is_valid;

    while (in >> n >> m) {
        if (n < 2 || m < 2 || n < m || n % m != 0) {
            cout << "Boring!" << endl;
            continue;
        }
        k = -1;
        v.clear();
        is_valid = true;
        v.push_back(n);
        temp = n;
        k++;

        while ((temp = temp / m) > 0) {
            if (temp == 1) {
                v.push_back(1);
                break;
            }
            v.push_back(temp);
            k++;
            if (v[k] >= v[k-1] or v[k] % m != 0) {
                is_valid = false;
                break;
            }
        }

        if (is_valid && temp == 1) {
            bool s = false;
            for (vector<long long int>::iterator it = v.begin(); it != v.end(); it++) {
                if (s) cout << " ";
                cout << *it;
                s = true;
            }
        } else {
            cout << "Boring!";
        }
        cout << endl;
    }

    return 0;
}
