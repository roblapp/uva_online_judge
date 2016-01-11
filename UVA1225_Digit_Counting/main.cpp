#include <iostream>
#include <cstring>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

void countDigits(int x, int f[]) {
    while (x > 0) {
        f[x % 10]++;
        x /= 10;
    }
}

int main() {
	int n, x;
	cin >> n;
	while (n--) {
        cin >> x;
        int f[10];
        memset(f, 0, sizeof(f));
        for (int i = 1; i <= x; i++)
            countDigits(i, f);
        for (int i = 0; i < 10; i++)
            (i > 0) ? cout << " " << f[i] : cout << f[i];
        cout << endl;
	}
    return 0;
}
