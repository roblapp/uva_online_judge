#include <iostream>

/*
Accepted: 0.000s
Description: ad-hoc
*/

#define read cin

using namespace std;

int main() {
    int a, b, temp;
    while (read >> a >> b && (a >= 0 || b >= 0)) {
        if (a > b) swap(a, b);
        temp = b - a;
        cout << min(temp, 100-temp) << endl;
    }
    return 0;
}
