#include <iostream>

/*
Accepted: 0.000s
Category: math
Algorithm: brute force count the squares
*/

using namespace std;

int main() {
	int n, sum, cnt;

	while (cin >> n and n != 0) {
        sum = 0;
        for (int sz = 1; sz <= n; sz++) {
            cnt = 0;
            for (int i = 0; i + sz <= n; i++)
                cnt++;
            sum += cnt*cnt;
        }
        cout << sum << endl;
    }
    return 0;
}
