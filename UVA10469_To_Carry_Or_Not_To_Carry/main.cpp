#include <iostream>

/*
Accepted: 0.000s
Description: bitwise operations
Info: Just think about it for a minute and do an example on
paper and you can see it is a simple problem.
*/

using namespace std;

int main() {
    int a, b, temp;
    while (cin >> a >> b) {
        temp = a & b;
        if (temp == 0) cout << (a + b) << endl;
        else cout << (a ^ b) << endl;
    }
    return 0;
}
