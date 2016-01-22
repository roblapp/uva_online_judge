#include <iostream>
#include <cstring>

/*
Accepted: 0.016s
Description: ad-hoc
*/

using namespace std;

#define MAXN 501

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
	int x, g, sum[MAXN];
	memset(sum, 0, sizeof(sum));
	for (int i = 1; i <= 499; i++) {
        for (int j = i + 1; j <= 500; j++) {
            g = gcd(i, j);
            for (int k = j; k <= 500; k++)
                sum[k] += g;
        }
	}
    while (cin >> x && x > 0)
        cout << sum[x] << endl;
    return 0;
}
