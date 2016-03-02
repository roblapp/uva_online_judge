#include <iostream>
#include <set>

/*
Accepted: 0.129s
Category: ad-hoc
Algorithm: ad-hoc
*/

using namespace std;

int sortAsc(int x) {
    int u[10] = {0};
    while (x > 0) {
        u[x%10]++;
        x /= 10;
    }
    int res = 0;
    for (int i = 0; i <= 9; i++) {
        while (u[i] > 0) {
            res = 10*res + i;
            u[i]--;
        }
    }
    return res;
}

int sortDesc(int x) {
    int u[10] = {0};
    while (x > 0) {
        u[x%10]++;
        x /= 10;
    }
    int res = 0;
    for (int i = 9; i >= 0; i--) {
        while (u[i] > 0) {
            res = 10*res + i;
            u[i]--;
        }
    }
    return res;
}

int main() {
	int x, xa, xd, chainLen;

	while (cin >> x and x != 0) {
        set<int> s;
        chainLen = 0;
        cout << "Original number was " << x << endl;
        while (1) {
            xd = sortDesc(x);
            xa = sortAsc(x);
            x = sortDesc(x) - sortAsc(x);
            cout << xd << " - " << xa << " = " << x << endl;
            chainLen++;
            if (s.find(x) != s.end())
                break;
            s.insert(x);
        }
        cout << "Chain length " << chainLen << endl << endl;
	}
    return 0;
}
