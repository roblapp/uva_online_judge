#include <iostream>

/*
Accepted: 0.009s
Category: math
Algorithm: ad-hoc
*/

using namespace std;

bool hasRepeatedDigit(int x) {
    bool used[10] = {false};
    while (x > 0) {
        if (used[x%10])
            return true;
        else {
            used[x%10] = true;
            x /= 10;
        }
    }
    return false;
}

int main() {
	int n, m, cnt;

	while (cin >> n >> m) {
	    cnt = 0;
        for (int i = n; i <= m; i++)
            if (!hasRepeatedDigit(i))
                cnt++;
        cout << cnt << endl;
	}
    return 0;
}
