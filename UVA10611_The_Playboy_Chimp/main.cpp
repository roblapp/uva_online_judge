#include <iostream>
#include <vector>
#include <algorithm>

/*
Accepted: 0.052s
Description: binary search
*/

using namespace std;

#define read cin
#define out cout

int main() {
	int n, nq, x;
	vector<int> v;

	read >> n;
	for (int i = 0; i < n; i++) {
        read >> x;
        v.push_back(x);
	}
	read >> nq;
	for (int i = 0; i < nq; i++) {
        read >> x;
        int lo = lower_bound(v.begin(), v.end(), x) - v.begin();
        while (lo >= 0 && v[lo] >= x) {
            lo--;
        }
        int hi = upper_bound(v.begin(), v.end(), x) - v.begin();
        if (lo >= 0 && lo < n)
            (hi < n) ? out << v[lo] << " " << v[hi] << endl : out << v[lo] << " X" << endl;
        else
            (hi < n) ? out << "X " << v[hi] << endl : out << "X X" << endl;
	}
    return 0;
}
