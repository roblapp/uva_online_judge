#include <cstdio>
#include <vector>
#include <algorithm>

/*
Accepted: 0.329s
Description: sorting, ad-hoc
*/

using namespace std;

int main() {
    int i, x, n;
    vector<int> v;
    while (scanf("%i", &n) && n != 0) {
        v.clear();
        for (i = 0; i < n; i++) {
            scanf("%i", &x);
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        printf("%i", v[0]);
        for (i = 1; i < n; i++) {
            printf(" %i", v[i]);
        }
        putchar('\n');
    }
    return 0;
}
