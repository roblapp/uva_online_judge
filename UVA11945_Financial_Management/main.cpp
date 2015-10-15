#include <iostream>
#include <cstdio>
#include <cmath>

/*
Accepted: 0.000s
Description: ad-hoc
*/

using namespace std;

int main() {
    int j, ncases, N = 1;
    double x, sum;
    string line;
    scanf("%i", &ncases);
    while (ncases--) {
        sum = 0;
        for (j = 0; j < 12; j++) {
            scanf("%lf", &x);
            sum += x;
        }
        sum /= 12.0;
        if (sum > 999.99) printf("%i $%ld,%.2lf\n", N++, (long) (sum/1000.0), fmod(sum, 1000.0));
        else printf("%i $%.2lf\n", N++, sum);
    }
    return 0;
}
