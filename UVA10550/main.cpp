#include <iostream>
/*
Accepted: 0.000s
Description: Ad hoc, simple calculations
Info: Carefully look at how the lock operates and make sure you are
spinning the lock the right way!!!
*/
#define NDEGREES 9

using namespace std;

int main() {
    int initial, a, b, c, sum;
    while (cin >> initial >> a >> b >> c) {
        if (initial == 0 && a == 0 && b == 0 && c == 0) {
            break;
        }
        sum = 40 + 40 + 40;
        if (initial >= a) sum += initial - a;
        else sum += 40 - a + initial;
        initial = a;
        if (initial > b) sum += 40 - initial + b;
        else sum += b - initial;
        initial = b;
        if (initial >= c) sum += initial - c;
        else sum += 40 - c + initial;
        cout << (sum * NDEGREES) << endl;
    }
    return 0;
}
