#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <cstdlib>

#define MAXN 5607
#define MAXINT (1 << 20)
#define in cin

using namespace std;

struct data {
    int strength, weight;
};

typedef struct data data;

int compare(const void *pa, const void *pb) {
    data a = *((data *) pa);
    data b = *((data *) pb);

    if (a.strength != b.strength) {
        return a.weight - b.weight;
    }

    return a.strength - b.strength;
}

int main() {

    int a, b, k = 0, n;
    data d[MAXN];
    int dp[MAXN];

    while (cin >> a >> b) {
        if (a > b) continue;
        d[k].weight = a;
        d[k].strength = b;
        k++;
    }

    n = k;

    qsort(d, k, sizeof(data), compare);

    memset(dp, MAXINT, sizeof(dp));
    dp[0] = 0;
    int soln = 1;
    for (int i = 0; i <= n - 1; i++) {
        for (int j = n - 1; j >= 1; j--) {
                cout << i << " " << j << endl;
            if (dp[j-1] + d[i].weight <= d[i].strength) {
                dp[j] = min(dp[j], dp[j-1] + d[i].weight);
            }
            if (dp[j] < MAXINT) {
                soln = max(soln, j);
            }
        }
    }


    cout << soln << endl;

    return 0;
}
