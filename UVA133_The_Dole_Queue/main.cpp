#include <iostream>
#include <iomanip>
#include <vector>

/*
Accepted: 0.000s
Category: data structures
Algorithm: ad-hoc
*/

using namespace std;

struct Entry {
    int value;
    bool isGone;
    Entry(int _value) : value(_value), isGone(false) {}
};

int nextIndex(int index, int stopPos, int startOverPos, int inc) {
    return (index == stopPos) ? startOverPos : index + inc;
}

int performCountHelper(vector<Entry> &v, int k, int startPos, int stopPos, int startOverPos, int inc) {
    int cnt = 0;
    int index = startPos;
    while (cnt < k) {
        if (!v[index].isGone) {
            cnt++;
        }
        if (cnt == k) {
            return index;
        }
        index = nextIndex(index, stopPos, startOverPos, inc);
    }
    return index;
}

/* returns true if there are 2 candidates, false if there is 1 */
bool performCount(vector<Entry> &v, int k, int m, int ccs, int cs, int &candIndex0, int &candIndex1) {
    candIndex0 = performCountHelper(v, k, ccs, 0, (int) v.size() - 1, -1); /* CCW */
    candIndex1 = performCountHelper(v, m, cs, (int) v.size() - 1, 0, 1); /* CW */
    v[candIndex0].isGone = true;
    v[candIndex1].isGone = true;
    return candIndex0 != candIndex1;
}

bool hasCandidates(vector<Entry> &v) {
    for (int i = 0; i < (int)v.size(); i++)
        if (!v[i].isGone)
            return true;
    return false;
}

int nextStartIndex(vector<Entry> &v, int index, int stopPost, int startOverPos, int inc) {
    int k = nextIndex(index, stopPost, startOverPos, inc);
    while (v[k].isGone) {
        k = nextIndex(k, stopPost, startOverPos, inc);
    }
    return k;
}

int main() {
	int n, k, m, candIndex0, candIndex1, ccs, cs;

	while (cin >> n >> k >> m and (n != 0 or k != 0 or m != 0)) {
        vector<Entry> v;
        for (int i = 0; i < n; i++) {
            v.push_back(Entry(n-i));
        }

        bool first = true;
        ccs = n - 1; /* initial starting points */
        cs = 0;
        while (hasCandidates(v)) {
            if (!first) {
                cout << ",";
                ccs = nextStartIndex(v, candIndex0, 0, (int)v.size() - 1, -1);
                cs = nextStartIndex(v, candIndex1, (int)v.size() - 1, 0, 1);
            }
            if (performCount(v, k, m, ccs, cs, candIndex0, candIndex1)) {
                cout << setw(3) << v[candIndex0].value;
                cout << setw(3) << v[candIndex1].value;
            } else {
                cout << setw(3) << v[candIndex0].value;
            }
            first = false;
        }
        cout << endl;
	}
    return 0;
}
